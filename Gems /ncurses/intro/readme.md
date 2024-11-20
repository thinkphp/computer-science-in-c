### How It Works:
1. The program initializes ncurses using initscr().
2. It uses mvprintw() to display instructions and guide the user.
3. getstr() is used to take input for the two numbers as strings, which are then converted to integers using atoi().
4. The program calculates the sum of the two numbers.
5. The result is displayed using mvprintw().
6. The program waits for the user to press a key before exiting and restoring the terminal state with endwin().

### Compilation and Execution:
1. Save the code in a file, e.g., add_numbers.c.
2. Compile the program with the ncurses library:

```
   gcc -o add_numbers add_numbers.c -lncurses
```

```
./add_numbers

```


