#include <gtkmm.h>

class SimpleApp : public Gtk::Window {
public:
    SimpleApp();

protected:
    // Signal handlers:
    void on_button_clicked();

    // Member widgets:
    Gtk::Button m_button;
};

SimpleApp::SimpleApp()
: m_button("Click Me") {
    // Set the title of the window
    set_title("Simple GTKmm App");

    // Set the border width of the window
    set_border_width(10);

    // When the button is clicked, it will call the on_button_clicked() method
    m_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleApp::on_button_clicked));

    // Add the button to the window
    add(m_button);

    // Make the button visible
    m_button.show();
}

void SimpleApp::on_button_clicked() {
    // Create a message dialog and set the message
    Gtk::MessageDialog dialog(*this, "Button Clicked!", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK);
    dialog.set_secondary_text("You clicked the button!");

    // Show the dialog and wait for a response
    dialog.run();
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    SimpleApp window;

    // Show the window and return when it is closed
    return app->run(window);
}

//g++ simple_app.cpp -o simple_app `pkg-config --cflags --libs gtkmm-3.0`
