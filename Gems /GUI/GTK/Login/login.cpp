#include <gtkmm.h>
#include <iostream>
class AuthWindow : public Gtk::Window {
public:
    AuthWindow() {
        // Set window properties
        set_title("Authentication");
        set_default_size(300, 150);
        set_border_width(10);

        // Create widgets
        Gtk::Box* box = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 5));
        add(*box);

        Gtk::Label* usernameLabel = Gtk::manage(new Gtk::Label("Username:"));
        box->pack_start(*usernameLabel, Gtk::PACK_SHRINK);

        usernameEntry.set_max_length(50);
        usernameEntry.set_placeholder_text("Enter username");
        box->pack_start(usernameEntry, Gtk::PACK_EXPAND_WIDGET);

        Gtk::Label* passwordLabel = Gtk::manage(new Gtk::Label("Password:"));
        box->pack_start(*passwordLabel, Gtk::PACK_SHRINK);

        passwordEntry.set_visibility(false); // Hide password text
        passwordEntry.set_max_length(50);
        passwordEntry.set_placeholder_text("Enter password");
        box->pack_start(passwordEntry, Gtk::PACK_EXPAND_WIDGET);

        Gtk::Button* loginButton = Gtk::manage(new Gtk::Button("Login"));
        loginButton->signal_clicked().connect(sigc::mem_fun(*this, &AuthWindow::on_login_button_clicked));
        box->pack_start(*loginButton, Gtk::PACK_SHRINK);

        show_all_children();
    }

protected:
    void on_login_button_clicked() {
        std::string username = usernameEntry.get_text();
        std::string password = passwordEntry.get_text();

        // Implement your authentication logic here
        // For now, just print username and password
        std::cout << "Username: " << username << std::endl;
        std::cout << "Password: " << password << std::endl;
    }

private:
    Gtk::Entry usernameEntry;
    Gtk::Entry passwordEntry;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    AuthWindow authWindow;

    return app->run(authWindow);
}
