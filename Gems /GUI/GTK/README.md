### GTK GUI App Desktop

GTK is a widget toolkit. Each user interface created by GTK consists of widgets. This is implemented in C using GObject, an object-oriented framework for C. Widgets are organized in a hierarchy. The window widget is the main container. The user interface is then built by adding buttons, drop-down menus, input fields, and other widgets to the window


### Simple Apps

1. Intro GTKmm
3. Notepad / Notepad
4. Calculator/ Calculator
5. TodoList / ToDoList-persistent
6. Login / Login System
7. Games / Tic Tac Toe
8. Shortner / Url Shortner
9. Competitive Programming / The Time in Words (7:23 => twenty three past 7)


To compile your `C++` program using `gtkmm`, you need to ensure you have the necessary development packages installed (such as `gtkmm-3.0`) and use the appropriate compiler flags.

### Compilation Steps:

1. **Install `gtkmm-3.0` (if not installed)**:
   - On **Ubuntu/Debian**:
     ```bash
     sudo apt-get install libgtkmm-3.0-dev
     ```

   - On **Fedora**:
     ```bash
     sudo dnf install gtkmm30-devel
     ```

   - On **Arch Linux**:
     ```bash
     sudo pacman -S gtkmm3
     ```

2. **Compile the program** using `g++` with `pkg-config` to find the required compiler and linker flags for `gtkmm-3.0`:

   ```bash
   g++ -o app app.cpp `pkg-config --cflags --libs gtkmm-3.0`
   ```

### Explanation:
- `g++`: The GNU C++ compiler.
- `-o app`: Specifies the output executable file name (`notepad`).
- `app.cpp`: Your source file.
- `` `pkg-config --cflags --libs gtkmm-3.0` ``: This part uses `pkg-config` to retrieve the necessary include paths (`--cflags`) and libraries (`--libs`) for compiling and linking against `gtkmm-3.0`.

### Running the compiled program:

After compilation, run the program with:

```bash
./app
```

### References

https://gnome.pages.gitlab.gnome.org/gtkmm-documentation/index.html
