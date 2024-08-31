#include <gtkmm.h>

class SimpleApp : public Gtk::Window {
public:
    SimpleApp();

protected:
    // Signal handlers:
    void on_button_clicked();

    // Member widgets:
    Gtk::Button m_button;
    Gtk::Entry m_entry;
    Gtk::ComboBoxText m_combobox;
    Gtk::Box m_box;  // To hold the widgets in a vertical layout
};

SimpleApp::SimpleApp()
: m_button("Click Me"), m_box(Gtk::ORIENTATION_VERTICAL) {
    // Set the title of the window
    set_title("Simple GTKmm App");

    // Set the border width of the window
    set_border_width(10);

    // Set the default size of the window
    set_default_size(800, 600);

    // Configure the vertical box
    m_box.set_spacing(10);  // Add some space between widgets

    // Populate the combo box with items
    m_combobox.append("Option 1");
    m_combobox.append("Option 2");
    m_combobox.append("Option 3");
    m_combobox.set_active(0);  // Set default active item to the first one

    // When the button is clicked, it will call the on_button_clicked() method
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleApp::on_button_clicked));

    // Add the widgets to the box
    m_box.pack_start(m_entry, Gtk::PACK_EXPAND_WIDGET); // Entry will expand
    m_box.pack_start(m_combobox, Gtk::PACK_SHRINK);     // Combo box will take only as much space as needed
    m_box.pack_start(m_button, Gtk::PACK_SHRINK);      // Button will take only as much space as needed

    // Add the box to the window
    add(m_box);

    // Make all widgets visible
    m_entry.show();
    m_combobox.show();
    m_button.show();
    m_box.show();
}

void SimpleApp::on_button_clicked() {
    // Get the text from the entry
    Glib::ustring entry_text = m_entry.get_text();

    // Get the active item from the combo box
    Glib::ustring combo_text = m_combobox.get_active_text();

    // Create a message dialog and set the message
    Gtk::MessageDialog dialog(*this, "Button Clicked!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
    dialog.set_secondary_text("You entered: " + entry_text + "\nSelected option: " + combo_text);

    // Show the dialog and wait for a response
    dialog.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    SimpleApp window;

    // Show the window and return when it is closed
    return app->run(window);
}
