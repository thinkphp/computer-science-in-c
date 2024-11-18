# ncurses
`ncurses` (short for **new curses**) is a programming library that provides an API for creating text-based user interfaces in a terminal or command-line environment. It is primarily used for creating interactive, console-based applications that can handle windows, color, key events, and text manipulation in a more advanced way than simple command-line programs.

Key features of `ncurses` include:

1. **Window Management**: It allows developers to create and manage multiple windows within the terminal, making it easier to display text in specific locations and layers.
2. **Keyboard Input Handling**: `ncurses` can capture user input, including keyboard keys, mouse events, and special function keys, which is essential for building interactive applications.
3. **Color Support**: It enables the use of different colors for text and backgrounds, allowing for a more visually appealing interface.
4. **Text Manipulation**: Developers can manipulate text by moving the cursor, adding or deleting text, or creating scrolling regions.
5. **Portable**: Since `ncurses` operates at the terminal level, it works across a wide variety of UNIX-like operating systems, including Linux, macOS, and others.

It’s commonly used for creating terminal-based applications, such as text editors, system monitors, games, and more, where graphical user interfaces (GUIs) are impractical or unnecessary.


```
sudo apt-get install libncurses5-dev
```
### Compile the code
```
gcc -o snake_game snake_game.c -lncurses
```

### Run the code
```
./snake_game
```
