#include <gtkmm.h>
#include <webkit2/webkit2.h>

class SimpleBrowser : public Gtk::Window {
public:
    SimpleBrowser();

private:
    void on_go_button_clicked();
    void on_back_button_clicked();
    void on_forward_button_clicked();
    void on_refresh_button_clicked();
    void on_load_changed(WebKitWebView*, WebKitLoadEvent);

    Gtk::Box m_vbox;
    Gtk::Box m_hbox;
    Gtk::Entry m_entry;
    Gtk::Button m_go_button;
    Gtk::Button m_back_button;
    Gtk::Button m_forward_button;
    Gtk::Button m_refresh_button;
    Gtk::Label m_loader_label; // Loader label
    WebKitWebView* m_webview;
};

SimpleBrowser::SimpleBrowser()
    : m_vbox(Gtk::ORIENTATION_VERTICAL),
      m_hbox(Gtk::ORIENTATION_HORIZONTAL),
      m_go_button("Go"),
      m_back_button("Back"),
      m_forward_button("Forward"),
      m_refresh_button("Refresh"),
      m_loader_label("Loading...") { // Initializing loader label
    set_title("Simple Browser");
    set_default_size(800, 600);

    m_hbox.pack_start(m_back_button, Gtk::PACK_SHRINK);
    m_hbox.pack_start(m_forward_button, Gtk::PACK_SHRINK);
    m_hbox.pack_start(m_refresh_button, Gtk::PACK_SHRINK);
    m_hbox.pack_start(m_entry);
    m_hbox.pack_start(m_go_button, Gtk::PACK_SHRINK);

    m_vbox.pack_start(m_hbox, Gtk::PACK_SHRINK);
    m_vbox.pack_start(m_loader_label, Gtk::PACK_SHRINK); // Add loader label to the layout
    m_loader_label.set_no_show_all(); // Don't show it initially

    m_webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
    Gtk::Widget* webkit_widget = Gtk::manage(Glib::wrap(GTK_WIDGET(m_webview)));
    m_vbox.pack_start(*webkit_widget);

    add(m_vbox);

    m_go_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleBrowser::on_go_button_clicked));
    m_back_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleBrowser::on_back_button_clicked));
    m_forward_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleBrowser::on_forward_button_clicked));
    m_refresh_button.signal_clicked().connect(sigc::mem_fun(*this, &SimpleBrowser::on_refresh_button_clicked));

    // Connect to the load-changed signal of the WebKitWebView to show/hide the loader
    g_signal_connect(m_webview, "load-changed", G_CALLBACK(+[](WebKitWebView* webview, WebKitLoadEvent load_event, gpointer user_data) {
        SimpleBrowser* browser = static_cast<SimpleBrowser*>(user_data);
        browser->on_load_changed(webview, load_event);
    }), this);

    show_all_children();
}

void SimpleBrowser::on_go_button_clicked() {
    webkit_web_view_load_uri(m_webview, m_entry.get_text().c_str());
}

void SimpleBrowser::on_back_button_clicked() {
    webkit_web_view_go_back(m_webview);
}

void SimpleBrowser::on_forward_button_clicked() {
    webkit_web_view_go_forward(m_webview);
}

void SimpleBrowser::on_refresh_button_clicked() {
    webkit_web_view_reload(m_webview);
}

// Handle the load-changed signal to show/hide the loader
void SimpleBrowser::on_load_changed(WebKitWebView* webview, WebKitLoadEvent load_event) {
    switch (load_event) {
        case WEBKIT_LOAD_STARTED:
            // Show the loading message when a new page starts loading
            m_loader_label.show();
            break;
        case WEBKIT_LOAD_FINISHED:
            // Hide the loading message when the page is fully loaded
            m_loader_label.hide();
            break;
        default:
            break;
    }
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    SimpleBrowser browser;

    return app->run(browser);
}

//How to compile: ++ -o simple_browser browser.cpp `pkg-config --cflags --libs gtkmm-3.0 webkit2gtk-4.0`
