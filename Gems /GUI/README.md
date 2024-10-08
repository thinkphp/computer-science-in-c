# GTKmm 

GTKmm is a C++ wrapper library for the popular GTK+ toolkit, providing a more object-oriented and type-safe way to create graphical user interfaces (GUIs). If you're familiar with C++ and want to 
develop cross-platform desktop applications, GTKmm is an excellent choice

### Key Features

- Object-Oriented: Leverages C++'s object-oriented paradigm for intuitive GUI development.
- Type Safety: Reduces potential errors by providing strong type checking.
- Rich Widget Set: Offers a wide range of pre-built widgets for various UI components.
- Extensibility: Allows you to create custom widgets by inheriting from existing ones.
- Signal/Slot Mechanism: Facilitates event handling and communication between UI elements.
- Integration with GNOME: Closely tied to the GNOME desktop environment, providing seamless integration.

```
  #include <gtkmm.h>

  int main(int argc, char *argv[]) {
    Gtk::Application app("my.application.id");

    Gtk::Window window;
    window.set_title("Hello, World!");

    Gtk::Label label("Hello, World!");
    window.add(label);

    window.show_all();

    return app.run(window);
}
```
