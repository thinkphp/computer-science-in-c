#include <ncurses.h>
#include <stdlib.h> // For atoi()

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();

    int num1, num2, sum;
    char str_num1[10], str_num2[10];

    // Display instructions
    mvprintw(1, 1, "Welcome to the ncurses addition program!");
    mvprintw(3, 1, "Enter the first number: ");
    refresh();

    // Get first number
    echo(); // Enable echo for user input
    getstr(str_num1);
    num1 = atoi(str_num1); // Convert string to integer

    // Get second number
    mvprintw(4, 1, "Enter the second number: ");
    refresh();
    getstr(str_num2);
    num2 = atoi(str_num2); // Convert string to integer

    // Calculate the sum
    sum = num1 + num2;

    // Display the result
    noecho(); // Disable echo again
    mvprintw(6, 1, "The sum of %d and %d is: %d", num1, num2, sum);
    mvprintw(8, 1, "Press any key to exit...");
    refresh();

    // Wait for user input before exiting
    getch();

    // Close ncurses
    endwin();
    return 0;
}
