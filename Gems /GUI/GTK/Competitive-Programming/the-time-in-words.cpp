#include <gtkmm.h>
#include <iostream>
#include <string>

class TimeConverterWindow : public Gtk::Window
{
public:
    TimeConverterWindow();

private:
    // Signal handlers
    void on_convert_button_clicked();

    // Widgets
    Gtk::Box m_hbox;  // Horizontal box for the entries
    Gtk::Box m_vbox;  // Vertical box for the overall layout
    Gtk::Entry m_hours_entry;
    Gtk::Entry m_minutes_entry;
    Gtk::Button m_convert_button;
    Gtk::Label m_result_label;

    // Helper functions
    std::string convert_time(int hours, int minutes);
    void load_css();

    // Time words
    std::string hoursWords[13] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine", "ten", "eleven", "twelve"
    };
    std::string minutesWords[31] = {
        "zero", "one minute", "two minutes", "three minutes", "four minutes",
        "five minutes", "six minutes", "seven minutes", "eight minutes",
        "nine minutes", "ten minutes", "eleven minutes", "twelve minutes",
        "thirteen minutes", "fourteen minutes", "quarter", "sixteen minutes",
        "seventeen minutes", "eighteen minutes", "nineteen minutes",
        "twenty minutes", "twenty one minutes", "twenty two minutes",
        "twenty three minutes", "twenty four minutes", "twenty five minutes",
        "twenty six minutes", "twenty seven minutes", "twenty eight minutes",
        "twenty nine minutes", "half"
    };
};

TimeConverterWindow::TimeConverterWindow()
    : m_hbox(Gtk::ORIENTATION_HORIZONTAL),
      m_vbox(Gtk::ORIENTATION_VERTICAL),
      m_convert_button("Convert")
{
    // Set CSS ID and class for the button
    m_convert_button.set_name("my-button"); // ID
    m_convert_button.get_style_context()->add_class("my-custom-button"); // Class

    set_title("Time Converter");
    set_default_size(570, 450);

    m_hours_entry.set_placeholder_text("Hours (0-12)");
    m_minutes_entry.set_placeholder_text("Minutes (0-59)");

    // Set a smaller size for the button
    m_convert_button.set_size_request(100, 30);

    // Pack entries and buttons
    m_hbox.pack_start(m_hours_entry);
    m_hbox.pack_start(m_minutes_entry);
    m_vbox.pack_start(m_hbox);
    m_vbox.pack_start(m_convert_button);
    m_vbox.pack_start(m_result_label);

    m_convert_button.signal_clicked().connect(sigc::mem_fun(*this, &TimeConverterWindow::on_convert_button_clicked));

    add(m_vbox);
    show_all_children();
    load_css(); // Load CSS styles

    // Debugging hover signals
    m_convert_button.signal_enter().connect([]() {
        std::cout << "Button hovered" << std::endl;
    });
    m_convert_button.signal_leave().connect([]() {
        std::cout << "Button not hovered" << std::endl;
    });
}

void TimeConverterWindow::on_convert_button_clicked()
{
    int hours, minutes;

    try {
        hours = std::stoi(m_hours_entry.get_text());
        minutes = std::stoi(m_minutes_entry.get_text());
    } catch (const std::exception& e) {
        m_result_label.set_text("Invalid input. Please enter numbers.");
        return;
    }

    m_result_label.set_text(convert_time(hours, minutes));
}

std::string TimeConverterWindow::convert_time(int hours, int minutes)
{
    if (minutes < 0 || minutes > 59 || hours < 0 || hours > 12) {
        return "Invalid time input.";
    }

    if (minutes == 0) {
        return hoursWords[hours] + " o' clock";
    } else if (minutes <= 30) {
        return minutesWords[minutes] + " past " + hoursWords[hours];
    } else {
        return minutesWords[60 - minutes] + " to " + hoursWords[(hours + 1) % 12];
    }
}

void TimeConverterWindow::load_css()
{
    auto css_provider = Gtk::CssProvider::create();

    // CSS data with class and ID styling
    std::string css_data =
        "label { "
        "    color: green; font-size: 30px;"
        "} "

        /* Styling for button with ID my-button */
        "#my-button {"
        "    background-color: #007bff; /* Blue */"
        "    color: white;"
        "    padding: 10px;"
        "    margin: 10px; "
        "    border-radius: 70px;"
        "} "

        "entry { "
        "    background-color: yellow; "
        "    color: black; "
        "    margin: 10px; "
        "    font-size: 20px; "
        "    padding: 5px; "
        "    border: 1px solid #ccc; "
        "    border-radius: 50px; "
        "} "

        "window { "
        "    background-color: lightgreen;"
        "} ";

    try {
        css_provider->load_from_data(css_data);
    } catch (const Gtk::CssProviderError& e) {
        std::cerr << "CSS Provider Error: " << e.what() << std::endl;
        return;  // Exit the function on error
    }

    Gtk::StyleContext::add_provider_for_screen(
        Gdk::Screen::get_default(),
        css_provider,
        GTK_STYLE_PROVIDER_PRIORITY_USER
    );
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.timeconverter");
    TimeConverterWindow window;
    return app->run(window);
}
