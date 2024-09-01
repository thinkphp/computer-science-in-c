//g++ menu.cpp -o menu `pkg-config --cflags --libs gtkmm-3.0`
#include <gtkmm.h>
#include <iostream>

// Callback functions for menu items
void on_menu_file_new()
{
    Gtk::MessageDialog dialog("New File", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'New' from the File menu.");
    dialog.run();
}

void on_menu_file_open()
{
    Gtk::MessageDialog dialog("Open File", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Open' from the File menu.");
    dialog.run();
}

void on_menu_file_save()
{
    Gtk::MessageDialog dialog("Save File", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Save' from the File menu.");
    dialog.run();
}

void on_menu_file_save_as()
{
    Gtk::MessageDialog dialog("Save As", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Save As' from the File menu.");
    dialog.run();
}

void on_menu_file_quit(Gtk::Window& window)
{
    window.close();
}

void on_menu_edit_cut()
{
    Gtk::MessageDialog dialog("Cut", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Cut' from the Edit menu.");
    dialog.run();
}

void on_menu_edit_copy()
{
    Gtk::MessageDialog dialog("Copy", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Copy' from the Edit menu.");
    dialog.run();
}

void on_menu_edit_paste()
{
    Gtk::MessageDialog dialog("Paste", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dialog.set_secondary_text("You clicked on 'Paste' from the Edit menu.");
    dialog.run();
}

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(800, 600);
    window.set_title("Notepad Editor");

    // Create a vertical box to hold the menu and text area
    Gtk::Box vbox(Gtk::ORIENTATION_VERTICAL);
    window.add(vbox);

    // Create the menu bar
    Gtk::MenuBar menuBar;

    // Create File menu
    Gtk::MenuItem menuItemFile("File");
    Gtk::Menu fileMenu;
    menuItemFile.set_submenu(fileMenu);

    // Add items to the File menu
    Gtk::MenuItem menuItemNew("New");
    Gtk::MenuItem menuItemOpen("Open");
    Gtk::MenuItem menuItemSave("Save");
    Gtk::MenuItem menuItemSaveAs("Save As");
    Gtk::MenuItem menuItemQuit("Quit");

    fileMenu.append(menuItemNew);
    fileMenu.append(menuItemOpen);
    fileMenu.append(menuItemSave);
    fileMenu.append(menuItemSaveAs);
    fileMenu.append(menuItemQuit);

    // Connect signals to the File menu items
    menuItemNew.signal_activate().connect(sigc::ptr_fun(&on_menu_file_new));
    menuItemOpen.signal_activate().connect(sigc::ptr_fun(&on_menu_file_open));
    menuItemSave.signal_activate().connect(sigc::ptr_fun(&on_menu_file_save));
    menuItemSaveAs.signal_activate().connect(sigc::ptr_fun(&on_menu_file_save_as));
    menuItemQuit.signal_activate().connect(sigc::bind<Gtk::Window&>(sigc::ptr_fun(&on_menu_file_quit), window));

    // Add the File menu to the menu bar
    menuBar.append(menuItemFile);

    // Create Edit menu
    Gtk::MenuItem menuItemEdit("Edit");
    Gtk::Menu editMenu;
    menuItemEdit.set_submenu(editMenu);

    // Add items to the Edit menu
    Gtk::MenuItem menuItemCut("Cut");
    Gtk::MenuItem menuItemCopy("Copy");
    Gtk::MenuItem menuItemPaste("Paste");

    editMenu.append(menuItemCut);
    editMenu.append(menuItemCopy);
    editMenu.append(menuItemPaste);

    // Connect signals to the Edit menu items
    menuItemCut.signal_activate().connect(sigc::ptr_fun(&on_menu_edit_cut));
    menuItemCopy.signal_activate().connect(sigc::ptr_fun(&on_menu_edit_copy));
    menuItemPaste.signal_activate().connect(sigc::ptr_fun(&on_menu_edit_paste));

    // Add the Edit menu to the menu bar
    menuBar.append(menuItemEdit);

    // Add the menu bar to the vertical box
    vbox.pack_start(menuBar, Gtk::PACK_SHRINK);

    // Create a text area
    Gtk::TextView textView;
    vbox.pack_start(textView);

    // Show all widgets
    window.show_all_children();

    return app->run(window);
}
