#include <ncurses.h>

void display_fibonacci(int n);

int main() {
    int n;

    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    // Instructions for the user
    mvprintw(1, 1, "Fibonacci Sequence Generator");
    mvprintw(3, 1, "Enter the number of terms to generate: ");
    refresh();

    // Enable user input
    echo();
    scanw("%d", &n); // Read the number of terms
    noecho(); // Disable echo after input

    // Clear the screen and display the Fibonacci sequence
    clear();
    mvprintw(1, 1, "Fibonacci Sequence:");
    display_fibonacci(n);

    // End the program
    mvprintw(n + 3, 1, "Press any key to exit...");
    refresh();
    getch();

    // Close ncurses
    endwin();
    return 0;
}

// Function to calculate and display the Fibonacci sequence
void display_fibonacci(int n) {
    long long a = 0, b = 1, next;
    for (int i = 0; i < n; i++) {
        mvprintw(i + 2, 1, "Term %d: %lld", i + 1, a);
        refresh(); // Update the screen

        // Calculate the next term
        next = a + b;
        a = b;
        b = next;

        // Add a small delay to make the display dynamic
        napms(300);
    }
}
