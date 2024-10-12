#include <gtkmm.h>

class Notepad : public Gtk::Window {
public:
    Notepad();

private:
    void on_text_changed();
    void zoom_in();
    void zoom_out();
    void apply_css(const std::string& line_number_color);
    bool on_delete_event(GdkEventAny* event) override; // Override the delete event

    Gtk::Box m_box{Gtk::ORIENTATION_HORIZONTAL};
    Gtk::ScrolledWindow m_text_scrolled_window;
    Gtk::TextView m_text_view;
    Glib::RefPtr<Gtk::TextBuffer> m_text_buffer;

    Gtk::TextView m_line_number_view;
    Glib::RefPtr<Gtk::TextBuffer> m_line_number_buffer;

    // Font size for zoom functionality
    int m_font_size = 12;

    // Function to handle key press events for zoom in/out and color change
    bool on_key_press_event(GdkEventKey* key_event) override;

    // Current color for line numbers (blue or green)
    std::string m_line_number_color = "blue";

    // Function to show the confirmation dialog
    void show_close_confirmation();
};

Notepad::Notepad() {
    set_title("Notepad with Line Numbers and Zoom");
    set_default_size(800, 600);

    // Set up main text view
    m_text_buffer = Gtk::TextBuffer::create();
    m_text_view.set_buffer(m_text_buffer);
    m_text_view.set_wrap_mode(Gtk::WRAP_WORD);
    m_text_view.set_margin_start(10); // Margin for the main text content

    // Set up line number view
    m_line_number_buffer = Gtk::TextBuffer::create();
    m_line_number_view.set_buffer(m_line_number_buffer);
    m_line_number_view.set_editable(false);
    m_line_number_view.set_cursor_visible(false); // Disable the cursor in the line number view
    m_line_number_view.set_margin_end(10); // Margin for the line numbers

    // Connect signal for text changes
    m_text_buffer->signal_changed().connect(sigc::mem_fun(*this, &Notepad::on_text_changed));

    // Set up scrolling window for text view
    m_text_scrolled_window.add(m_text_view);
    m_text_scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    // Pack line number and text areas side by side
    m_box.pack_start(m_line_number_view, Gtk::PACK_SHRINK);
    m_box.pack_start(m_text_scrolled_window);

    add(m_box);
    show_all_children();

    // Apply initial CSS styling with default blue color for line numbers
    apply_css(m_line_number_color);

    // Connect key press event for zoom in/out and color toggle
    signal_key_press_event().connect(sigc::mem_fun(*this, &Notepad::on_key_press_event), false);
}

void Notepad::on_text_changed() {
    int num_lines = m_text_buffer->get_line_count();
    std::string line_numbers;
    for (int i = 1; i <= num_lines; ++i) {
        line_numbers += std::to_string(i) + "\n";
    }
    m_line_number_buffer->set_text(line_numbers);
}

void Notepad::apply_css(const std::string& line_number_color) {
    // Create a CSS provider to apply the font size and line number color
    auto css_provider = Gtk::CssProvider::create();
    css_provider->load_from_data(
        "textview {"
        "   font-size: " + std::to_string(m_font_size) + "px;"  // Use the current font size
        "   color: black;"  // Content text color
        "   background-color: #f0f0f0;"  // Background color for the content area
        "}"
        "textview #line-number {"
        "   background-color: #e0e0e0;"  // Background color for line numbers
        "   color: " + line_number_color + ";"  // Line number color (blue or green)
        "}");

    // Apply the CSS to the screen
    auto screen = Gdk::Screen::get_default();
    Gtk::StyleContext::add_provider_for_screen(screen, css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Add CSS class for line number view
    m_line_number_view.get_style_context()->add_class("line-number");
}

void Notepad::zoom_in() {
    if (m_font_size < 40) { // Limit the maximum zoom level
        m_font_size += 2;
        apply_css(m_line_number_color);  // Re-apply CSS with the current color
    }
}

void Notepad::zoom_out() {
    if (m_font_size > 6) { // Limit the minimum zoom level
        m_font_size -= 2;
        apply_css(m_line_number_color);  // Re-apply CSS with the current color
    }
}

bool Notepad::on_key_press_event(GdkEventKey* key_event) {
    // Check for Ctrl + "+" or Ctrl + "-" for zoom in/out
    if ((key_event->state & GDK_CONTROL_MASK)) {
        if (key_event->keyval == GDK_KEY_plus || key_event->keyval == GDK_KEY_equal) {
            zoom_in();
            return true;
        }
        else if (key_event->keyval == GDK_KEY_minus) {
            zoom_out();
            return true;
        }
        // Check for Ctrl + "b" to switch to blue, or Ctrl + "g" to switch to green
        else if (key_event->keyval == GDK_KEY_b) {
            m_line_number_color = "blue";
            apply_css(m_line_number_color);  // Apply CSS with blue line numbers
            return true;
        }
        else if (key_event->keyval == GDK_KEY_g) {
            m_line_number_color = "green";
            apply_css(m_line_number_color);  // Apply CSS with green line numbers
            return true;
        }
    }
    return Gtk::Window::on_key_press_event(key_event);
}

bool Notepad::on_delete_event(GdkEventAny* event) {
    show_close_confirmation();  // Show confirmation dialog
    return true; // Prevent the default handler from being called
}

void Notepad::show_close_confirmation() {
    Gtk::MessageDialog dialog(*this, "Are you sure you want to close the window?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
    dialog.set_title("Close Confirmation");
    int result = dialog.run();
    if (result == Gtk::RESPONSE_YES) {
        hide(); // Close the window if the user confirms
    }
    // If the user selects "No", just close the dialog
}

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.notepad");
    Notepad notepad;
    return app->run(notepad);
}
