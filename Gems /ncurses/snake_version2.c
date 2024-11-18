#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 30
#define HEIGHT 10
#define INITIAL_SNAKE_SIZE 3

// Directions for snake movement
#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

typedef struct Snake {
    int x[WIDTH * HEIGHT];  // X-coordinates of the snake's body
    int y[WIDTH * HEIGHT];  // Y-coordinates of the snake's body
    int size;               // Length of the snake
    int direction;          // Current direction
} Snake;

void initGame(Snake *snake, int *foodX, int *foodY);
void drawGame(Snake *snake, int foodX, int foodY);
int moveSnake(Snake *snake, int foodX, int foodY);
int checkCollision(Snake *snake);
void generateFood(int *foodX, int *foodY);

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    curs_set(0);  // Hide the cursor
    keypad(stdscr, TRUE);  // Enable keypad input

    // Initialize random number generator
    srand(time(NULL));

    // Initialize the game state
    Snake snake;
    int foodX, foodY;
    initGame(&snake, &foodX, &foodY);

    // Game loop
    while (1) {
        drawGame(&snake, foodX, foodY);
        
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if (snake.direction != DOWN) snake.direction = UP;
                break;
            case KEY_DOWN:
                if (snake.direction != UP) snake.direction = DOWN;
                break;
            case KEY_LEFT:
                if (snake.direction != RIGHT) snake.direction = LEFT;
                break;
            case KEY_RIGHT:
                if (snake.direction != LEFT) snake.direction = RIGHT;
                break;
            case 'q':
                endwin();
                return 0;
        }

        // Move the snake
        if (!moveSnake(&snake, foodX, foodY)) {
            break;  // Game over if collision happens
        }

        usleep(100000);  // Sleep for 100 milliseconds to control snake speed
    }

    endwin();  // End ncurses session
    return 0;
}

void initGame(Snake *snake, int *foodX, int *foodY) {
    // Initialize snake
    snake->size = INITIAL_SNAKE_SIZE;
    snake->direction = RIGHT;

    for (int i = 0; i < snake->size; i++) {
        snake->x[i] = snake->size - i - 1;
        snake->y[i] = HEIGHT / 2;
    }

    // Generate food
    generateFood(foodX, foodY);
}

void drawGame(Snake *snake, int foodX, int foodY) {
    clear();  // Clear the screen

    // Draw border
    for (int i = 0; i < WIDTH; i++) {
        mvprintw(0, i, "#");
        mvprintw(HEIGHT, i, "#");
    }
    for (int i = 0; i < HEIGHT; i++) {
        mvprintw(i, 0, "#");
        mvprintw(i, WIDTH, "#");
    }

    // Draw food
    mvprintw(foodY, foodX, "O");

    // Draw snake
    for (int i = 0; i < snake->size; i++) {
        mvprintw(snake->y[i], snake->x[i], "*");
    }

    // Refresh the screen
    refresh();
}

int moveSnake(Snake *snake, int foodX, int foodY) {
    // Move the snake by shifting the body coordinates
    for (int i = snake->size - 1; i > 0; i--) {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }

    // Move the head in the current direction
    switch (snake->direction) {
        case UP:
            snake->y[0]--;
            break;
        case DOWN:
            snake->y[0]++;
            break;
        case LEFT:
            snake->x[0]--;
            break;
        case RIGHT:
            snake->x[0]++;
            break;
    }

    // Check for collision with the walls
    if (snake->x[0] <= 0 || snake->x[0] >= WIDTH || snake->y[0] <= 0 || snake->y[0] >= HEIGHT) {
        return 0;  // Game over
    }

    // Check for collision with the snake itself
    for (int i = 1; i < snake->size; i++) {
        if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
            return 0;  // Game over
        }
    }

    // Check if snake ate the food
    if (snake->x[0] == foodX && snake->y[0] == foodY) {
        // Snake grows
        snake->size++;

        // Generate new food
        generateFood(&foodX, &foodY);
    }

    return 1;  // Continue the game
}

void generateFood(int *foodX, int *foodY) {
    *foodX = rand() % (WIDTH - 2) + 1;
    *foodY = rand() % (HEIGHT - 2) + 1;
}
