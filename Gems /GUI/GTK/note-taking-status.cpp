#include <gtkmm.h>
#include <fstream>
#include <string>

class NoteTakingApp : public Gtk::Window {
public:
    NoteTakingApp();

protected:
    void on_new_note();
    void on_open_note();
    void on_save_note();
    void on_about();
    void update_status(const Glib::ustring& message);

    Gtk::Box m_main_box;        // Main horizontal box
    Gtk::Box m_button_box;      // Vertical box for buttons
    Gtk::TextView m_text_view;
    Gtk::Button m_new_button, m_open_button, m_save_button, m_about_button;
    Gtk::Statusbar m_statusbar; // Statusbar widget
    Glib::RefPtr<Gtk::TextBuffer> m_text_buffer;
};

NoteTakingApp::NoteTakingApp()
    : m_main_box(Gtk::ORIENTATION_HORIZONTAL),  // Main box is horizontal
      m_button_box(Gtk::ORIENTATION_VERTICAL),  // Button box is vertical
      m_new_button("New"),
      m_open_button("Open"),
      m_save_button("Save"),
      m_about_button("About") {

    set_title("Note-Taking Application");
    set_default_size(800, 600);

    m_text_buffer = Gtk::TextBuffer::create();
    m_text_view.set_buffer(m_text_buffer);

    // Arrange buttons vertically in the button box
    m_button_box.set_spacing(10);
    m_button_box.pack_start(m_new_button, Gtk::PACK_SHRINK);
    m_button_box.pack_start(m_open_button, Gtk::PACK_SHRINK);
    m_button_box.pack_start(m_save_button, Gtk::PACK_SHRINK);
    m_button_box.pack_start(m_about_button, Gtk::PACK_SHRINK);

    // Add the button box and text view to the main box
    m_main_box.pack_start(m_button_box, Gtk::PACK_SHRINK);
    m_main_box.pack_start(m_text_view);

    // Add the main box and the status bar to the window
    Gtk::Box* main_layout = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL));
    main_layout->pack_start(m_main_box);
    main_layout->pack_start(m_statusbar, Gtk::PACK_SHRINK);

    // Connect button signals
    m_new_button.signal_clicked().connect(sigc::mem_fun(*this, &NoteTakingApp::on_new_note));
    m_open_button.signal_clicked().connect(sigc::mem_fun(*this, &NoteTakingApp::on_open_note));
    m_save_button.signal_clicked().connect(sigc::mem_fun(*this, &NoteTakingApp::on_save_note));
    m_about_button.signal_clicked().connect(sigc::mem_fun(*this, &NoteTakingApp::on_about));

    add(*main_layout);
    show_all_children();

    // Initial status message
    update_status("Ready");
}

void NoteTakingApp::on_new_note() {
    m_text_buffer->set_text("");
    update_status("New note created");
}

void NoteTakingApp::on_open_note() {
    Gtk::FileChooserDialog dialog("Open Note", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        std::ifstream file(dialog.get_filename());
        if (file) {
            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            m_text_buffer->set_text(content);
            update_status("Note opened successfully");
        } else {
            Gtk::MessageDialog error_dialog("Failed to open the file.", false, Gtk::MESSAGE_ERROR);
            error_dialog.run();
            update_status("Failed to open note");
        }
    } else {
        update_status("Open operation canceled");
    }
}

void NoteTakingApp::on_save_note() {
    Gtk::FileChooserDialog dialog("Save Note", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::SAVE, Gtk::RESPONSE_OK);

    if (dialog.run() == Gtk::RESPONSE_OK) {
        std::ofstream file(dialog.get_filename());
        if (file) {
            file << m_text_buffer->get_text();
            update_status("Note saved successfully");
        } else {
            Gtk::MessageDialog error_dialog("Failed to save the file.", false, Gtk::MESSAGE_ERROR);
            error_dialog.run();
            update_status("Failed to save note");
        }
    } else {
        update_status("Save operation canceled");
    }
}

void NoteTakingApp::on_about() {
    Gtk::MessageDialog about_dialog(*this, "Created by Adrian", false, Gtk::MESSAGE_INFO);
    about_dialog.set_secondary_text("This is a simple note-taking application.");
    about_dialog.run();
    update_status("Displayed About dialog");
}

void NoteTakingApp::update_status(const Glib::ustring& message) {
    m_statusbar.push(message);
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.example.notetaking");
    NoteTakingApp window;
    return app->run(window);
}

