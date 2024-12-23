#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_DISKS 7
#define NUM_PEGS 3
#define BASE_WIDTH (MAX_DISKS * 2 + 1)
#define DISK_CHAR '='
#define PEG_CHAR '|'
#define SPACE_CHAR ' '
#define DELAY_MS 100000  // 100ms delay for animations

typedef struct {
    int disks[MAX_DISKS];
    int top;
} Peg;

Peg pegs[NUM_PEGS];
int num_disks;
int moves = 0;
int selected_peg = -1;
WINDOW *win_window = NULL;

void init_game(int n) {
    num_disks = n;
    // Initialize all pegs as empty
    for (int i = 0; i < NUM_PEGS; i++) {
        pegs[i].top = -1;
    }

    // Place all disks on the first peg
    for (int i = n - 1; i >= 0; i--) {
        pegs[0].disks[++pegs[0].top] = i + 1;
    }
}

void draw_disk(int y, int x, int size) {
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            mvaddch(y, x - i, DISK_CHAR);
            mvaddch(y, x + i, DISK_CHAR);
        }
    }
    mvaddch(y, x, DISK_CHAR);
}

void create_win_window() {
    int height = 10;
    int width = 40;
    int starty = (LINES - height) / 2;
    int startx = (COLS - width) / 2;

    win_window = newwin(height, width, starty, startx);
    box(win_window, 0, 0);

    // Add victory message
    mvwprintw(win_window, 2, (width-18)/2, "VICTORY!");
    mvwprintw(win_window, 4, (width-20)/2, "Moves taken: %d", moves);
    mvwprintw(win_window, 6, (width-21)/2, "Press any key to quit");

    // Create a border of stars
    for(int i = 0; i < width; i++) {
        mvwaddch(win_window, 0, i, '*');
        mvwaddch(win_window, height-1, i, '*');
    }
    for(int i = 0; i < height; i++) {
        mvwaddch(win_window, i, 0, '*');
        mvwaddch(win_window, i, width-1, '*');
    }

    wrefresh(win_window);
}

void draw_board() {
    clear();

    // Draw title and moves
    mvprintw(1, 10, "Tower of Hanoi - Moves: %d", moves);
    mvprintw(2, 10, "Use 1, 2, 3 to select/move disks. 'q' to quit");

    // Calculate base positions for pegs
    int base_y = 15;
    int peg_spacing = BASE_WIDTH + 4;
    int start_x = 20;

    // Draw pegs and disks
    for (int p = 0; p < NUM_PEGS; p++) {
        int peg_x = start_x + p * peg_spacing;

        // Draw peg number
        mvprintw(base_y + 1, peg_x, "%d", p + 1);

        // Draw peg
        for (int y = base_y - MAX_DISKS; y <= base_y; y++) {
            mvaddch(y, peg_x, PEG_CHAR);
        }

        // Draw highlight if peg is selected
        if (p == selected_peg) {
            mvaddch(base_y - MAX_DISKS - 1, peg_x, '*');
            mvaddch(base_y - MAX_DISKS - 1, peg_x - 1, '>');
            mvaddch(base_y - MAX_DISKS - 1, peg_x + 1, '<');
        }

        // Draw base
        for (int x = peg_x - BASE_WIDTH/2; x <= peg_x + BASE_WIDTH/2; x++) {
            mvaddch(base_y, x, DISK_CHAR);
        }

        // Draw disks
        for (int i = 0; i <= pegs[p].top; i++) {
            int disk_size = pegs[p].disks[i];
            draw_disk(base_y - i - 1, peg_x, disk_size);
        }
    }

    refresh();
}

int is_valid_move(int from, int to) {
    if (from == to) return 0;
    if (pegs[from].top == -1) return 0;
    if (pegs[to].top == MAX_DISKS - 1) return 0;
    if (pegs[to].top >= 0 && pegs[to].disks[pegs[to].top] < pegs[from].disks[pegs[from].top]) return 0;
    return 1;
}

void move_disk(int from, int to) {
    if (!is_valid_move(from, to)) return;

    int disk = pegs[from].disks[pegs[from].top--];
    pegs[to].disks[++pegs[to].top] = disk;
    moves++;
}

int check_win() {
    return (pegs[NUM_PEGS-1].top == num_disks - 1);
}

void animate_victory() {
    // Flash the screen a few times
    for (int i = 0; i < 3; i++) {
        flash();
        usleep(200000);
    }

    // Create and show the victory window
    create_win_window();
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    // Initialize game with 5 disks
    init_game(3);

    int running = 1;
    while (running) {
        draw_board();

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            running = 0;
        }
        else if (ch >= '1' && ch <= '3') {
            int peg = ch - '1';

            if (selected_peg == -1) {
                if (pegs[peg].top >= 0) {
                    selected_peg = peg;
                }
            }
            else {
                move_disk(selected_peg, peg);
                selected_peg = -1;

                if (check_win()) {
                    draw_board();
                    animate_victory();
                    getch();  // Wait for any key
                    running = 0;
                }
            }
        }

        usleep(DELAY_MS);
    }

    if (win_window != NULL) {
        delwin(win_window);
    }
    endwin();
    return 0;
}
