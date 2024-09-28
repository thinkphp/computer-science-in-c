#include <gtkmm.h>
#include <iostream>
#include <fstream>
#include <vector>

class TabPage : public Gtk::Box
{
public:
    TabPage();
    Gtk::TextView& get_text_view() { return m_textview; }
    Gtk::ScrolledWindow& get_scrolled_window() { return m_scrolled_window; }
    void set_filename(const std::string& filename) { m_filename = filename; }
    const std::string& get_filename() const { return m_filename; }

private:
    Gtk::TextView m_textview;
    Gtk::ScrolledWindow m_scrolled_window;
    std::string m_filename;
};

TabPage::TabPage() : Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
    m_scrolled_window.add(m_textview);
    m_scrolled_window.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
    pack_start(m_scrolled_window);
    show_all_children();
}

class NotepadWindow : public Gtk::Window
{
public:
    NotepadWindow();

private:
    // Signal handlers
    void on_menu_file_new_tab();
    void on_menu_file_close_tab();
    void on_menu_file_open();
    void on_menu_file_save();
    void on_menu_file_save_as();
    void on_menu_file_quit();
    void on_menu_edit_cut();
    void on_menu_edit_copy();
    void on_menu_edit_paste();
    bool on_key_press_event(GdkEventKey* event) override;

    // Helper functions
    void save_file(const std::string& filename, TabPage* page);
    void load_file(const std::string& filename);
    void change_font_size(int increment);
    void update_tab_label(Gtk::Widget* page, const std::string& text);

    // Widgets
    Gtk::Box m_vbox;
    Gtk::MenuBar m_menubar;
    Gtk::Notebook m_notebook;

    // Font settings
    int m_font_size;
    std::string m_font_family;

    // Tab counter
    int m_tab_counter;
};

NotepadWindow::NotepadWindow()
    : m_vbox(Gtk::ORIENTATION_VERTICAL), m_font_size(12), m_font_family("Arial"), m_tab_counter(0)
{
    set_title("Notepad Editor");
    set_default_size(800, 600);

    add(m_vbox);

    // Create File menu
    auto menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    auto submenu_file = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*submenu_file);

    auto menuitem_new_tab = Gtk::manage(new Gtk::MenuItem("New _Tab", true));
    auto menuitem_close_tab = Gtk::manage(new Gtk::MenuItem("_Close Tab", true));
    auto menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    auto menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    auto menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    auto menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));

    submenu_file->append(*menuitem_new_tab);
    submenu_file->append(*menuitem_close_tab);
    submenu_file->append(*menuitem_open);
    submenu_file->append(*menuitem_save);
    submenu_file->append(*menuitem_save_as);
    submenu_file->append(*Gtk::manage(new Gtk::SeparatorMenuItem()));
    submenu_file->append(*menuitem_quit);

    menuitem_new_tab->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_new_tab));
    menuitem_close_tab->signal_activate().connect(sigc::mem_fun(*this, &NotepadWindow::on_menu_file_close_tab));
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

    // Add the notebook (tabbed interface)
    m_vbox.pack_start(m_notebook);

    show_all_children();

    // Create an initial tab
    on_menu_file_new_tab();
}

void NotepadWindow::on_menu_file_new_tab()
{
    m_tab_counter++;
    auto page = Gtk::manage(new TabPage());
    std::string tab_name = "Untitled " + std::to_string(m_tab_counter);
    int page_num = m_notebook.append_page(*page, tab_name);
    m_notebook.set_current_page(page_num);
    page->show();

    // Set the font for the new tab
    change_font_size(0);
}

void NotepadWindow::on_menu_file_close_tab()
{
    int current_page = m_notebook.get_current_page();
    if (current_page != -1) {
        m_notebook.remove_page(current_page);
    }
    if (m_notebook.get_n_pages() == 0) {
        on_menu_file_new_tab();
    }
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
    TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
    if (current_page) {
        if (current_page->get_filename().empty())
        {
            on_menu_file_save_as();
        }
        else
        {
            save_file(current_page->get_filename(), current_page);
        }
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
        TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
        if (current_page) {
            save_file(dialog.get_filename(), current_page);
        }
    }
}

void NotepadWindow::on_menu_file_quit()
{
    close();
}

void NotepadWindow::on_menu_edit_cut()
{
    TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
    if (current_page) {
        auto clipboard = Gtk::Clipboard::get();
        current_page->get_text_view().get_buffer()->cut_clipboard(clipboard);
    }
}

void NotepadWindow::on_menu_edit_copy()
{
    TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
    if (current_page) {
        auto clipboard = Gtk::Clipboard::get();
        current_page->get_text_view().get_buffer()->copy_clipboard(clipboard);
    }
}

void NotepadWindow::on_menu_edit_paste()
{
    TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
    if (current_page) {
        auto clipboard = Gtk::Clipboard::get();
        current_page->get_text_view().get_buffer()->paste_clipboard(clipboard);
    }
}

void NotepadWindow::save_file(const std::string& filename, TabPage* page)
{
    try
    {
        std::ofstream file(filename);
        auto buffer = page->get_text_view().get_buffer();
        std::string text = buffer->get_text();
        file << text;
        file.close();

        page->set_filename(filename);
        update_tab_label(page, Glib::path_get_basename(filename));
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

        on_menu_file_new_tab();
        TabPage* current_page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(m_notebook.get_current_page()));
        if (current_page) {
            current_page->get_text_view().get_buffer()->set_text(content);
            current_page->set_filename(filename);
            update_tab_label(current_page, Glib::path_get_basename(filename));
        }
    }
    catch (const std::exception& e)
    {
        Gtk::MessageDialog dialog(*this, "Error opening file", false, Gtk::MESSAGE_ERROR);
        dialog.set_secondary_text(e.what());
        dialog.run();
    }
}

bool NotepadWindow::on_key_press_event(GdkEventKey* event)
{
    if ((event->state & GDK_CONTROL_MASK))
    {
        if (event->keyval == GDK_KEY_plus || event->keyval == GDK_KEY_equal)
        {
            change_font_size(2);
            return true;
        }
        else if (event->keyval == GDK_KEY_minus)
        {
            change_font_size(-2);
            return true;
        }
    }

    return Gtk::Window::on_key_press_event(event);
}

void NotepadWindow::change_font_size(int increment)
{
    m_font_size += increment;

    // Set the new font size and family for all tabs
    auto pango_desc = Pango::FontDescription(m_font_family);
    pango_desc.set_size(m_font_size * PANGO_SCALE);

    for (int i = 0; i < m_notebook.get_n_pages(); ++i) {
        TabPage* page = dynamic_cast<TabPage*>(m_notebook.get_nth_page(i));
        if (page) {
            page->get_text_view().override_font(pango_desc);
        }
    }
}

void NotepadWindow::update_tab_label(Gtk::Widget* page, const std::string& text)
{
    Gtk::Label* label = dynamic_cast<Gtk::Label*>(m_notebook.get_tab_label(*page));
    if (label) {
        label->set_text(text);
    }
}

int main(int argc, char* argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.notepad");
    NotepadWindow window;
    return app->run(window);
}
