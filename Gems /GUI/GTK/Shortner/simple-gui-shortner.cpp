#include <gtkmm.h>
#include <iostream>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.example.urlshortener");

    Gtk::Window window;
    window.set_title("URL Shortener");
    window.set_default_size(400, 200); // Set window size

    Gtk::Box layout(Gtk::ORIENTATION_VERTICAL, 10);

    Gtk::Entry longURLEntry;
    layout.pack_start(longURLEntry, Gtk::PACK_EXPAND_WIDGET);

    Gtk::Label shortenedURLLabel;
    layout.pack_start(shortenedURLLabel, Gtk::PACK_EXPAND_WIDGET);

    Gtk::Button shortenButton("Shorten");
    layout.pack_start(shortenButton, Gtk::PACK_SHRINK);

    shortenButton.signal_clicked().connect([&longURLEntry, &shortenedURLLabel] {
        std::string long_url = longURLEntry.get_text();
        std::cout << "Button clicked. URL: " << long_url << std::endl;
        shortenedURLLabel.set_text("URL: " + long_url); // Just for testing
    });

    window.add(layout);
    window.show_all();

    return app->run(window);
}
