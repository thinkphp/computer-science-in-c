#include <gtkmm.h>
#include <cairomm/context.h>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

struct Point {
    int x, y;
};

class SnakeGame : public Gtk::Window {
public:
    SnakeGame();
    virtual ~SnakeGame();

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
    bool on_key_press_event(GdkEventKey* event) override;
    bool on_timeout();

private:
    void update_game();
    void draw_snake(const Cairo::RefPtr<Cairo::Context>& cr);
    void draw_food(const Cairo::RefPtr<Cairo::Context>& cr);
    void spawn_food();

    Glib::RefPtr<Glib::TimeoutSource> timeout_source;
    std::vector<Point> snake;
    Point food;
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
    bool growing;
    bool game_over;

    const int TILE_SIZE = 20;
    const int GRID_WIDTH = 40;
    const int GRID_HEIGHT = 30;
};

// Constructor
SnakeGame::SnakeGame()
    : direction(1), growing(false), game_over(false) {

    set_title("Snake Game");
    set_default_size(GRID_WIDTH * TILE_SIZE, GRID_HEIGHT * TILE_SIZE);
    set_border_width(10);

    // Initialize the snake
    snake.push_back({GRID_WIDTH / 2, GRID_HEIGHT / 2});

    // Set up the timer for the game loop
    timeout_source = Glib::TimeoutSource::create(100); // ~10 FPS
    timeout_source->connect(sigc::mem_fun(*this, &SnakeGame::on_timeout));
    Glib::signal_timeout().connect(sigc::mem_fun(*this, &SnakeGame::on_timeout), 100);

    add_events(Gdk::KEY_PRESS_MASK); // Enable key press events

    // Initialize random seed
    srand(static_cast<unsigned>(time(nullptr)));

    // Spawn the initial food
    spawn_food();
}

// Destructor
SnakeGame::~SnakeGame() {}

bool SnakeGame::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
    // Clear the background
    cr->set_source_rgb(0, 0, 0); // Black background
    cr->rectangle(0, 0, get_allocated_width(), get_allocated_height());
    cr->fill();

    // Draw game elements
    if (!game_over) {
        draw_snake(cr);
        draw_food(cr);
    } else {
        cr->set_source_rgb(1, 0, 0); // Red for game over text
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
        cr->set_font_size(40);
        cr->move_to(10, 50);
        cr->show_text("Game Over!");
    }

    return true;
}

bool SnakeGame::on_key_press_event(GdkEventKey* event) {
    if (game_over) return true;

    switch (event->keyval) {
        case GDK_KEY_Up:
            if (direction != 2) direction = 0; // Up
            break;
        case GDK_KEY_Right:
            if (direction != 3) direction = 1; // Right
            break;
        case GDK_KEY_Down:
            if (direction != 0) direction = 2; // Down
            break;
        case GDK_KEY_Left:
            if (direction != 1) direction = 3; // Left
            break;
        default:
            return Gtk::Window::on_key_press_event(event);
    }
    return true;
}

bool SnakeGame::on_timeout() {
    if (!game_over) {
        update_game();
        queue_draw(); // Request redraw
    }
    return true; // Continue calling on_timeout
}

void SnakeGame::update_game() {
    if (game_over) return;

    // Move the snake
    Point head = snake.front();
    switch (direction) {
        case 0: head.y--; break; // Up
        case 1: head.x++; break; // Right
        case 2: head.y++; break; // Down
        case 3: head.x--; break; // Left
    }

    // Check for collision with walls
    if (head.x < 0 || head.x >= GRID_WIDTH || head.y < 0 || head.y >= GRID_HEIGHT) {
        game_over = true;
        return;
    }

    // Check for collision with itself
    for (const auto& segment : snake) {
        if (segment.x == head.x && segment.y == head.y) {
            game_over = true;
            return;
        }
    }

    snake.insert(snake.begin(), head); // Add new head

    // Check for collision with food
    if (head.x == food.x && head.y == food.y) {
        growing = true;
        spawn_food(); // Spawn new food
    }

    if (!growing) {
        snake.pop_back(); // Remove the tail
    } else {
        growing = false; // Reset growth flag
    }
}

void SnakeGame::draw_snake(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source_rgb(0, 1, 0); // Green for snake
    for (const auto& segment : snake) {
        cr->rectangle(segment.x * TILE_SIZE, segment.y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
        cr->fill();
    }
}

void SnakeGame::draw_food(const Cairo::RefPtr<Cairo::Context>& cr) {
    cr->set_source_rgb(1, 0, 0); // Red for food
    cr->rectangle(food.x * TILE_SIZE, food.y * TILE_SIZE, TILE_SIZE, TILE_SIZE);
    cr->fill();
}

void SnakeGame::spawn_food() {
    bool position_found = false;
    while (!position_found) {
        food.x = rand() % GRID_WIDTH;
        food.y = rand() % GRID_HEIGHT;

        // Ensure the food doesn't spawn on the snake
        position_found = true;
        for (const auto& segment : snake) {
            if (food.x == segment.x && food.y == segment.y) {
                position_found = false;
                break;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv);
    SnakeGame window;
    return app->run(window);
}
