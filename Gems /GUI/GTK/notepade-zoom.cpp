#include <gtkmm.h>
#include <iostream>
#include <fstream>

class NotepadWindow : public Gtk::Window
{
public:
    NotepadWindow();

private:
    // Signal handlers
    void on_menu_file_new();
    void on_menu_file_open();
    void on_menu_file_save();
    void on_menu_file_save_as();
    void on_menu_file_quit();
    void on_menu_edit_cut();
    void on_menu_edit_copy();
    void on_menu_edit_paste();
    bool on_key_press_event(GdkEventKey* event) override;

    // Helper functions
    void save_file(const std::string& filename);
    void load_file(const std::string& filename);
    void change_font_size(int increment);

    // Widgets
    Gtk::Box m_vbox;
    Gtk::MenuBar m_menubar;
    Gtk::TextView m_textview;
    Gtk::ScrolledWindow m_scrolled_window;

    // Current file
    std::string m_current_file;

    // Font size state
    int m_font_size;
};

NotepadWindow::NotepadWindow()
    : m_vbox(Gtk::ORIENTATION_VERTICAL), m_font_size(12)  // Set initial font size
{
    set_title("Notepad Editor");
    set_default_size(800, 600);

    add(m_vbox);

    // Create File menu
    auto menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    auto submenu_file = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*submenu_file);

    auto menuitem_new = Gtk::manage(new Gtk::MenuItem("_New", true));
    auto menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    auto menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    auto menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    auto menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));

    submenu_file->append(*menuitem_new);
    submenu_file->append(*menuitem_open);
    submenu_file->append(*menuitem_save);
    submenu_file->append(*menuitem_save_as);
    submenu_file->append(*Gtk::manage(new Gtk::SeparatorMenuItem()));
    submenu_file->append(*menuitem_quit);

    menuitem_new->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_new));
    menuitem_open->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_open));
    menuitem_save->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_save));
    menuitem_save_as->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_save_as));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_quit));

    // Create Edit menu
    auto menuitem_edit = Gtk::manage(new Gtk::MenuItem("_Edit", true));
    auto submenu_edit = Gtk::manage(new Gtk::Menu());
    menuitem_edit->set_submenu(*submenu_edit);

    auto menuitem_cut = Gtk::manage(new Gtk::MenuItem("Cu_t", true));
    auto menuitem_copy = Gtk::manage(new Gtk::MenuItem("_Copy", true));
    auto menuitem_paste = Gtk::manage(new Gtk::MenuItem("_Paste", true));

    submenu_edit->append(*menuitem_cut);
    submenu_edit->append(*menuitem_copy);
    submenu_edit->append(*menuitem_paste);

    menuitem_cut->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_edit_cut));
    menuitem_copy->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_edit_copy));
    menuitem_paste->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_edit_paste));

    // Add the menus to the menubar
    m_menubar.append(*menuitem_file);
    m_menubar.append(*menuitem_edit);

    m_vbox.pack_start(m_menubar, Gtk::PACK_SHRINK);

    // Add the text view inside a scrolled window
    m_scrolled_window.add(m_textview);
    m_scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    m_vbox.pack_start(m_scrolled_window);

    show_all_children();

    // Set the initial font size
    change_font_size(0);
}

void NotepadWindow::on_menu_file_new()
{
    m_textview.get_buffer()->set_text("");
    m_current_file.clear();
    set_title("Notepad Editor");
}

void NotepadWindow::on_menu_file_open()
{
    Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    auto filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);

    int result = dialog.run();
    if (result == Gtk::RESPONSE_OK)
    {
        load_file(dialog.get_filename());
    }
}

void NotepadWindow::on_menu_file_save()
{
    if (m_current_file.empty())
    {
        on_menu_file_save_as();
    }
    else
    {
        save_file(m_current_file);
    }
}

void NotepadWindow::on_menu_file_save_as()
{
    Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    auto filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);

    int result = dialog.run();
    if (result == Gtk::RESPONSE_OK)
    {
        save_file(dialog.get_filename());
    }
}

void NotepadWindow::on_menu_file_quit()
{
    close();
}

void NotepadWindow::on_menu_edit_cut()
{
    auto clipboard = Gtk::Clipboard::get();
    m_textview.get_buffer()->cut_clipboard(clipboard);
}

void NotepadWindow::on_menu_edit_copy()
{
    auto clipboard = Gtk::Clipboard::get();
    m_textview.get_buffer()->copy_clipboard(clipboard);
}

void NotepadWindow::on_menu_edit_paste()
{
    auto clipboard = Gtk::Clipboard::get();
    m_textview.get_buffer()->paste_clipboard(clipboard);
}

void NotepadWindow::save_file(const std::string& filename)
{
    try
    {
        std::ofstream file(filename);
        auto buffer = m_textview.get_buffer();
        std::string text = buffer->get_text();
        file << text;
        file.close();

        m_current_file = filename;
        set_title("Notepad Editor - " + m_current_file);
    }
    catch (const std::exception& e)
    {
        Gtk::MessageDialog dialog(*this, "Error saving file", false, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(e.what());
        dialog.run();
    }
}

void NotepadWindow::load_file(const std::string& filename)
{
    try
    {
        std::ifstream file(filename);
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        auto buffer = m_textview.get_buffer();
        buffer->set_text(content);

        m_current_file = filename;
        set_title("Notepad Editor - " + m_current_file);
    }
    catch (const std::exception& e)
    {
        Gtk::MessageDialog dialog(*this, "Error opening file", false, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(e.what());
        dialog.run();
    }
}

// This function will be called when a key is pressed
bool NotepadWindow::on_key_press_event(GdkEventKey* event)
{
    if ((event->state & GDK_CONTROL_MASK))  // If the Control key is pressed
    {
        if (event->keyval == GDK_KEY_plus || event->keyval == GDK_KEY_equal)
        {
            change_font_size(2);  // Increase font size
            return true;
        }
        else if (event->keyval == GDK_KEY_minus)
        {
            change_font_size(-2);  // Decrease font size
            return true;
        }
    }

    return Gtk::Window::on_key_press_event(event);  // Call base class handler
}

// This function changes the font size of the text view
void NotepadWindow::change_font_size(int increment)
{
    m_font_size += increment;

    // Set the new font size
    auto pango_desc = Pango::FontDescription("Monospace");
    pango_desc.set_size(m_font_size * PANGO_SCALE);  // PANGO_SCALE is used to set font size in points

    m_textview.override_font(pango_desc);  // Apply the font to the TextView
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.notepad");
    NotepadWindow window;
    return app->run(window);
}
