#include <gtkmm.h>
#include <iostream>

class Notepad : public Gtk::Window {
public:
    Notepad();

private:
    void on_text_changed();
    void update_line_numbers();
    void on_text_scroll();
    bool on_delete_event(GdkEventAny* event) override;
    void show_close_confirmation();
    void zoom_in();
    void zoom_out();
    void apply_css();
    bool on_key_press_event(GdkEventKey* key_event) override;

    Gtk::Box m_box{Gtk::ORIENTATION_HORIZONTAL};
    Gtk::ScrolledWindow m_text_scrolled_window;
    Gtk::TextView m_text_view;
    Glib::RefPtr<Gtk::TextBuffer> m_text_buffer;

    Gtk::ScrolledWindow m_line_number_scrolled_window;
    Gtk::TextView m_line_number_view;
    Glib::RefPtr<Gtk::TextBuffer> m_line_number_buffer;

    int m_font_size = 12;
};

Notepad::Notepad() {
    set_title("Notepad with Scrolling Line Numbers and Zoom");
    set_default_size(600, 400);

    m_text_buffer = Gtk::TextBuffer::create();
    m_text_view.set_buffer(m_text_buffer);
    m_text_view.set_wrap_mode(Gtk::WRAP_NONE);

    m_line_number_buffer = Gtk::TextBuffer::create();
    m_line_number_view.set_buffer(m_line_number_buffer);
    m_line_number_view.set_editable(false);
    m_line_number_view.set_can_focus(false);
    m_line_number_view.set_size_request(30, -1);

    m_text_scrolled_window.add(m_text_view);
    m_text_scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_line_number_scrolled_window.add(m_line_number_view);
    m_line_number_scrolled_window.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_EXTERNAL);

    m_box.pack_start(m_line_number_scrolled_window, Gtk::PACK_SHRINK);
    m_box.pack_start(m_text_scrolled_window);

    add(m_box);

    m_text_buffer->signal_changed().connect(sigc::mem_fun(*this, &Notepad::on_text_changed));
    m_text_view.get_vadjustment()->signal_value_changed().connect(sigc::mem_fun(*this, &Notepad::on_text_scroll));

    apply_css();

    show_all_children();
}

void Notepad::on_text_changed() {
    update_line_numbers();
}

void Notepad::update_line_numbers() {
    int lines = m_text_buffer->get_line_count();
    std::string numbers;
    for (int i = 1; i <= lines; ++i) {
        numbers += std::to_string(i) + "\n";
    }
    m_line_number_buffer->set_text(numbers);
}

void Notepad::on_text_scroll() {
    auto text_adj = m_text_view.get_vadjustment();
    auto line_adj = m_line_number_view.get_vadjustment();
    line_adj->set_value(text_adj->get_value());
}

bool Notepad::on_delete_event(GdkEventAny* event) {
    show_close_confirmation();
    return true;
}

void Notepad::show_close_confirmation() {
    Gtk::MessageDialog dialog(*this, "Are you sure you want to close the window?", false, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_YES_NO);
    dialog.set_title("Close Confirmation");
    int result = dialog.run();
    if (result == Gtk::RESPONSE_YES) {
        hide();
    }
}

void Notepad::zoom_in() {
    if (m_font_size < 40) {
        m_font_size += 2;
        apply_css();
    }
}

void Notepad::zoom_out() {
    if (m_font_size > 6) {
        m_font_size -= 2;
        apply_css();
    }
}

void Notepad::apply_css() {
    auto css_provider = Gtk::CssProvider::create();
    css_provider->load_from_data(
        "textview {"
        "   font-size: " + std::to_string(m_font_size) + "px;"
        "   color: black;"
        "   background-color: #f0f0f0;"
        "}"
        "textview#line-number {"
        "   background-color: #e0e0e0;"
        "   color: #808080;"
        "}");

    auto screen = Gdk::Screen::get_default();
    Gtk::StyleContext::add_provider_for_screen(screen, css_provider, GTK_STYLE_PROVIDER_PRIORITY_USER);

    m_line_number_view.set_name("line-number");
}

bool Notepad::on_key_press_event(GdkEventKey* key_event) {
    if ((key_event->state & GDK_CONTROL_MASK)) {
        if (key_event->keyval == GDK_KEY_plus || key_event->keyval == GDK_KEY_equal) {
            zoom_in();
            return true;
        }
        else if (key_event->keyval == GDK_KEY_minus) {
            zoom_out();
            return true;
        }
    }
    return Gtk::Window::on_key_press_event(key_event);
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    Notepad notepad;
    return app->run(notepad);
}
