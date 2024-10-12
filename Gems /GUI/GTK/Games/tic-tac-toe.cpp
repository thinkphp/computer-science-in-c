#include <gtkmm.h>
#include <vector>

class TicTacToeWindow : public Gtk::Window {
public:
    TicTacToeWindow();

protected:
    // Signal handlers
    void on_button_clicked(int row, int col);
    void reset_game();

    // Helper functions
    void check_winner();
    void disable_all_buttons();
    void show_winner_message(const Glib::ustring& message);

    // Child widgets
    Gtk::Grid m_Grid;
    Gtk::Button m_Buttons[3][3];
    Gtk::Label m_Label;
    Gtk::Button m_ResetButton;

    // Game state
    char m_Board[3][3];
    char m_CurrentPlayer;
    bool m_GameOver;
};

TicTacToeWindow::TicTacToeWindow()
    : m_CurrentPlayer('X'), m_GameOver(false) {

    set_title("Tic-Tac-Toe");
    set_border_width(10);
    set_default_size(300, 350);

    // Initialize the grid and label
    m_Grid.set_row_homogeneous(true);
    m_Grid.set_column_homogeneous(true);
    m_Label.set_text("Player X's turn");
    m_Label.set_hexpand(true);
    m_Label.set_margin_bottom(10);

    // Add label and grid to the main window
    Gtk::Box *vbox = Gtk::make_managed<Gtk::Box>(Gtk::ORIENTATION_VERTICAL);
    vbox->pack_start(m_Label, Gtk::PACK_SHRINK);
    vbox->pack_start(m_Grid);
    add(*vbox);

    // Initialize buttons and connect signals
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            m_Buttons[row][col].set_label("");
            m_Buttons[row][col].set_size_request(100, 100);
            m_Grid.attach(m_Buttons[row][col], col, row, 1, 1);
            m_Buttons[row][col].signal_clicked().connect(sigc::bind<int, int>(sigc::mem_fun(*this, &TicTacToeWindow::on_button_clicked), row, col));
            m_Board[row][col] = ' ';
        }
    }

    // Reset button
    m_ResetButton.set_label("Reset Game");
    m_ResetButton.set_margin_top(10);
    m_ResetButton.signal_clicked().connect(sigc::mem_fun(*this, &TicTacToeWindow::reset_game));
    vbox->pack_start(m_ResetButton, Gtk::PACK_SHRINK);

    show_all_children();
}

void TicTacToeWindow::on_button_clicked(int row, int col) {
    if(m_Board[row][col] == ' ' && !m_GameOver) {
        m_Board[row][col] = m_CurrentPlayer;
        m_Buttons[row][col].set_label(Glib::ustring(1, m_CurrentPlayer));

        // Check if there's a winner
        check_winner();

        // Switch player
        if (!m_GameOver) {
            m_CurrentPlayer = (m_CurrentPlayer == 'X') ? 'O' : 'X';
            m_Label.set_text(Glib::ustring::compose("Player %1's turn", m_CurrentPlayer));
        }
    }
}

void TicTacToeWindow::check_winner() {
    const char* winning_positions[8][3] = {
        {&m_Board[0][0], &m_Board[0][1], &m_Board[0][2]}, // Row 1
        {&m_Board[1][0], &m_Board[1][1], &m_Board[1][2]}, // Row 2
        {&m_Board[2][0], &m_Board[2][1], &m_Board[2][2]}, // Row 3
        {&m_Board[0][0], &m_Board[1][0], &m_Board[2][0]}, // Col 1
        {&m_Board[0][1], &m_Board[1][1], &m_Board[2][1]}, // Col 2
        {&m_Board[0][2], &m_Board[1][2], &m_Board[2][2]}, // Col 3
        {&m_Board[0][0], &m_Board[1][1], &m_Board[2][2]}, // Diagonal
        {&m_Board[2][0], &m_Board[1][1], &m_Board[0][2]}  // Diagonal
    };

    for (auto& position : winning_positions) {
        if (*position[0] != ' ' && *position[0] == *position[1] && *position[0] == *position[2]) {
            Glib::ustring winner_message = Glib::ustring::compose("Player %1 wins!", *position[0]);
            m_Label.set_text(winner_message);
            m_GameOver = true;
            disable_all_buttons();
            show_winner_message(winner_message); // Show winner message dialog
            return;
        }
    }

    // Check for draw
    bool draw = true;
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            if(m_Board[row][col] == ' ') {
                draw = false;
                break;
            }
        }
    }

    if(draw) {
        m_Label.set_text("It's a draw!");
        m_GameOver = true;
        show_winner_message("It's a draw!"); // Show draw message dialog
    }
}

void TicTacToeWindow::disable_all_buttons() {
    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            m_Buttons[row][col].set_sensitive(false);
        }
    }
}

void TicTacToeWindow::show_winner_message(const Glib::ustring& message) {
    Gtk::MessageDialog dialog(*this, message, false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.run();
}

void TicTacToeWindow::reset_game() {
    m_GameOver = false;
    m_CurrentPlayer = 'X';
    m_Label.set_text("Player X's turn");

    for(int row = 0; row < 3; ++row) {
        for(int col = 0; col < 3; ++col) {
            m_Board[row][col] = ' ';
            m_Buttons[row][col].set_label("");
            m_Buttons[row][col].set_sensitive(true);
        }
    }
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    TicTacToeWindow ticTacToeWindow;

    return app->run(ticTacToeWindow);
}
  
