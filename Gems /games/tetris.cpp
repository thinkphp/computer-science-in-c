//g++ -o cairo cai.cpp `pkg-config --cflags --libs gtkmm-3.0 cairo`

#include <gtkmm.h>
#include <cairomm/cairomm.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 20;
const int BLOCK_SIZE = 30;

// Tetromino shapes
const std::vector<std::vector<std::vector<int>>> tetrominoes = {
    {{1, 1, 1, 1}},  // I
    {{1, 1}, {1, 1}},  // O
    {{0, 1, 0}, {1, 1, 1}},  // T
    {{1, 0, 0}, {1, 1, 1}},  // L
    {{0, 0, 1}, {1, 1, 1}},  // J
    {{1, 1, 0}, {0, 1, 1}},  // S
    {{0, 1, 1}, {1, 1, 0}}   // Z
};

class Tetris : public Gtk::DrawingArea {
public:
    Tetris() : current_x_(BOARD_WIDTH / 2), current_y_(0), game_over_(false), paused_(false) {
        std::srand(std::time(0));
        Glib::signal_timeout().connect(sigc::mem_fun(*this, &Tetris::on_timeout), 300);
        current_piece_ = get_random_tetromino();
    }

public:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        cr->set_source_rgb(0, 0, 0);
        cr->paint();
        draw_board(cr);
        draw_tetromino(cr, current_piece_, current_x_, current_y_);

        if (game_over_) {
            draw_game_over(cr);
        }

        if (paused_) {
            draw_pause(cr);
        }

        return true;
    }

    bool on_key_press_event(GdkEventKey* event) override {
        if (game_over_) return false;

        if (paused_) {
            if (event->keyval == GDK_KEY_p) {
                paused_ = false;
                queue_draw();
            }
            return true;
        }

        switch (event->keyval) {
            case GDK_KEY_Left:
                if (!collides(current_piece_, current_x_ - 1, current_y_))
                    current_x_--;
                break;
            case GDK_KEY_Right:
                if (!collides(current_piece_, current_x_ + 1, current_y_))
                    current_x_++;
                break;
            case GDK_KEY_Down:
                if (!collides(current_piece_, current_x_, current_y_ + 1))
                    current_y_++;
                break;
            case GDK_KEY_space:
                rotate_tetromino(current_piece_);
                if (collides(current_piece_, current_x_, current_y_)) {
                    rotate_tetromino(current_piece_, true);  // Rotate back if collision
                }
                break;
            case GDK_KEY_p:  // Pause the game
                paused_ = true;
                queue_draw();
                break;
        }
        queue_draw();
        return true;
    }

    bool on_timeout() {
        if (game_over_ || paused_) return true;

        if (!collides(current_piece_, current_x_, current_y_ + 1)) {
            current_y_++;
        } else {
            lock_tetromino();
            clear_lines();
            current_piece_ = get_random_tetromino();
            current_x_ = BOARD_WIDTH / 2;
            current_y_ = 0;

            if (collides(current_piece_, current_x_, current_y_)) {
                game_over_ = true;
            }
        }
        queue_draw();
        return true;
    }

private:
    std::vector<std::vector<int>> board_{BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0)};
    std::vector<std::vector<int>> current_piece_;
    int current_x_, current_y_;
    bool game_over_;
    bool paused_;

    void draw_board(const Cairo::RefPtr<Cairo::Context>& cr) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            for (int x = 0; x < BOARD_WIDTH; ++x) {
                if (board_[y][x]) {
                    draw_block(cr, x, y, 0.2, 0.6, 0.8);  // Blue blocks
                }
            }
        }
    }

    void draw_block(const Cairo::RefPtr<Cairo::Context>& cr, int x, int y, double r, double g, double b) {
        cr->set_source_rgb(r, g, b);
        cr->rectangle(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        cr->fill();
    }

    void draw_tetromino(const Cairo::RefPtr<Cairo::Context>& cr, const std::vector<std::vector<int>>& tetromino, int x, int y) {
        for (size_t i = 0; i < tetromino.size(); ++i) {
            for (size_t j = 0; j < tetromino[i].size(); ++j) {
                if (tetromino[i][j]) {
                    draw_block(cr, x + j, y + i, 1.0, 0.5, 0.0);  // Orange blocks
                }
            }
        }
    }

    void draw_game_over(const Cairo::RefPtr<Cairo::Context>& cr) {
        cr->set_source_rgb(1, 0, 0);  // Red color for game over text
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
        cr->set_font_size(50);
        cr->move_to(BOARD_WIDTH * BLOCK_SIZE / 4, BOARD_HEIGHT * BLOCK_SIZE / 2);
        cr->show_text("Game Over");
        cr->stroke();
    }

    void draw_pause(const Cairo::RefPtr<Cairo::Context>& cr) {
        cr->set_source_rgb(1, 1, 0);  // Yellow color for pause text
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
        cr->set_font_size(50);
        cr->move_to(BOARD_WIDTH * BLOCK_SIZE / 4, BOARD_HEIGHT * BLOCK_SIZE / 2);
        cr->show_text("Paused");
        cr->stroke();
    }

    std::vector<std::vector<int>> get_random_tetromino() {
        return tetrominoes[std::rand() % tetrominoes.size()];
    }

    void rotate_tetromino(std::vector<std::vector<int>>& tetromino, bool reverse = false) {
        int rows = tetromino.size();
        int cols = tetromino[0].size();
        std::vector<std::vector<int>> rotated(cols, std::vector<int>(rows));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (reverse) {
                    rotated[j][rows - 1 - i] = tetromino[i][j];
                } else {
                    rotated[cols - 1 - j][i] = tetromino[i][j];
                }
            }
        }
        tetromino = rotated;

        // Debug output
        std::cout << "Rotated piece:" << std::endl;
        for (const auto& row : tetromino) {
            for (int val : row) {
                std::cout << val << ' ';
            }
            std::cout << std::endl;
        }
    }

    bool collides(const std::vector<std::vector<int>>& tetromino, int x, int y) {
        for (size_t i = 0; i < tetromino.size(); ++i) {
            for (size_t j = 0; j < tetromino[i].size(); ++j) {
                if (tetromino[i][j]) {
                    int new_x = x + j;
                    int new_y = y + i;
                    if (new_x < 0 || new_x >= BOARD_WIDTH || new_y >= BOARD_HEIGHT || board_[new_y][new_x]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void lock_tetromino() {
        for (size_t i = 0; i < current_piece_.size(); ++i) {
            for (size_t j = 0; j < current_piece_[i].size(); ++j) {
                if (current_piece_[i][j]) {
                    board_[current_y_ + i][current_x_ + j] = 1;
                }
            }
        }
    }

    void clear_lines() {
        for (int y = BOARD_HEIGHT - 1; y >= 0; --y) {
            bool full_line = true;
            for (int x = 0; x < BOARD_WIDTH; ++x) {
                if (!board_[y][x]) {
                    full_line = false;
                    break;
                }
            }
            if (full_line) {
                board_.erase(board_.begin() + y);
                board_.insert(board_.begin(), std::vector<int>(BOARD_WIDTH, 0));
                y++;
            }
        }
    }
};

class MyWindow : public Gtk::Window {
public:
    MyWindow() {
        set_title("Tetris in gtkmm");
        set_default_size(BOARD_WIDTH * BLOCK_SIZE, BOARD_HEIGHT * BLOCK_SIZE);

        add(tetris_);
        tetris_.show();

        add_events(Gdk::KEY_PRESS_MASK);
        signal_key_press_event().connect(sigc::mem_fun(tetris_, &Tetris::on_key_press_event), false);
    }

private:
    Tetris tetris_;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    MyWindow window;

    return app->run(window);
}
