#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

// Dimensiuni matrice
#define WIDTH  30
#define HEIGHT 20

// Direcții
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point body[WIDTH * HEIGHT];
    int length;
    int direction;
} Snake;

Point food;
Snake snake;

// Inițializează jocul
void init_game() {
    srand(time(0));
    snake.length = 1;
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;
    snake.direction = RIGHT;

    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

// Generare fruct nou
void generate_food() {
    food.x = rand() % WIDTH;
    food.y = rand() % HEIGHT;
}

// Desenează harta
void draw_game() {
    clear();

    // Desenează margini
    for (int i = 0; i <= WIDTH; i++) {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT, i, "#");
    }
    for (int i = 0; i <= HEIGHT; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH, "#");
    }

    // Desenează șarpele
    for (int i = 0; i < snake.length; i++) {
        mvprintw(snake.body[i].y, snake.body[i].x, "O");
    }

    // Desenează fructul
    mvprintw(food.y, food.x, "*");

    refresh();
}

// Actualizează poziția șarpelui
void update_snake() {
    // Determină poziția următoare a capului
    Point new_head = snake.body[0];
    switch (snake.direction) {
        case UP:    new_head.y--; break;
        case DOWN:  new_head.y++; break;
        case LEFT:  new_head.x--; break;
        case RIGHT: new_head.x++; break;
    }

    // Verifică coliziunea cu margini
    if (new_head.x <= 0 || new_head.x >= WIDTH || new_head.y <= 0 || new_head.y >= HEIGHT) {
        endwin();
        printf("Game Over! Ai pierdut.\n");
        exit(0);
    }

    // Verifică coliziunea cu corpul
    for (int i = 0; i < snake.length; i++) {
        if (snake.body[i].x == new_head.x && snake.body[i].y == new_head.y) {
            endwin();
            printf("Game Over! Ai pierdut.\n");
            exit(0);
        }
    }

    // Actualizează corpul șarpelui
    for (int i = snake.length; i > 0; i--) {
        snake.body[i] = snake.body[i - 1];
    }
    snake.body[0] = new_head;

    // Verifică dacă șarpele a mâncat fructul
    if (new_head.x == food.x && new_head.y == food.y) {
        snake.length++;
        generate_food();
    }
}

// Procesează intrările utilizatorului
void handle_input() {
    int ch = getch();
    switch (ch) {
        case 'w': if (snake.direction != DOWN)  snake.direction = UP;    break;
        case 's': if (snake.direction != UP)    snake.direction = DOWN;  break;
        case 'a': if (snake.direction != RIGHT) snake.direction = LEFT;  break;
        case 'd': if (snake.direction != LEFT)  snake.direction = RIGHT; break;
    }
}

int main() {
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);

    init_game();

    while (1) {
        draw_game();
        handle_input();
        update_snake();
        napms(500); // Pauză între cadre (100ms)
    }

    endwin();
    return 0;
}
