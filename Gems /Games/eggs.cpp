#include <gtkmm.h>
#include <cairomm/cairomm.h>
#include <cstdlib>
#include <ctime>
#include <vector>

// Constants
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const int MAGNET_WIDTH = 100;
const int MAGNET_HEIGHT = 50;
const int MAGNET_LEG_WIDTH = 20;
const int EGG_WIDTH = 30;
const int EGG_HEIGHT = 40;
const int MAGNET_SPEED = 20;
const int EGG_SPEED = 5;
const int LIVES = 3;
const int SPAWN_INTERVAL = 2000;

class EggCatcherGame : public Gtk::DrawingArea {
public:
    EggCatcherGame() : score(0), lives(LIVES), magnet_x(WINDOW_WIDTH / 2 - MAGNET_WIDTH / 2) {
        srand(time(0));  // Initialize random seed
        Glib::signal_timeout().connect(sigc::mem_fun(*this, &EggCatcherGame::on_timeout), 50);
        Glib::signal_timeout().connect(sigc::mem_fun(*this, &EggCatcherGame::spawn_egg), SPAWN_INTERVAL);
        add_events(Gdk::KEY_PRESS_MASK);
        signal_key_press_event().connect(sigc::mem_fun(*this, &EggCatcherGame::on_key_press));

        // Request focus so the drawing area can capture key events
        set_can_focus(true);
        grab_focus();  // Ensure focus is grabbed for keyboard input
    }

    virtual ~EggCatcherGame() {}

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        // Background
        cr->set_source_rgb(0.53, 0.81, 0.92);  // Light blue
        cr->paint();

        // Draw the magnet
        draw_magnet(cr);

        // Draw the eggs
        for (const auto& egg : eggs) {
            cr->save();
            // Translate the context to the center of the egg
            cr->translate(egg.x + EGG_WIDTH / 2, egg.y + EGG_HEIGHT / 2);
            // Scale the context to make it an oval
            cr->scale(1.0, static_cast<double>(EGG_HEIGHT) / EGG_WIDTH);
            // Draw the oval (as a scaled circle)
            cr->set_source_rgb(egg.color_r, egg.color_g, egg.color_b);
            cr->arc(0, 0, EGG_WIDTH / 2, 0, 2 * M_PI);  // Draw a circle
            cr->fill();
            cr->restore();
        }

        // Draw score and lives
        cr->set_source_rgb(0, 0, 0);
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
        cr->set_font_size(14);
        cr->move_to(20, 30);
        cr->show_text("Lives: " + std::to_string(lives));
        cr->move_to(WINDOW_WIDTH - 100, 30);
        cr->show_text("Score: " + std::to_string(score));

        return true;
    }

    bool on_timeout() {
        // Update egg positions
        for (auto it = eggs.begin(); it != eggs.end();) {
            it->y += EGG_SPEED;
            if (check_caught(*it)) {
                score++;
                it = eggs.erase(it);
            } else if (it->y >= WINDOW_HEIGHT) {
                lives--;
                it = eggs.erase(it);
                if (lives <= 0) {
                    game_over();
                    return false;
                }
            } else {
                ++it;
            }
        }

        queue_draw();  // Redraw the window
        return true;   // Continue timeout
    }

    bool on_key_press(GdkEventKey* key_event) {
        // Move magnet left or right
        if (key_event->keyval == GDK_KEY_Left && magnet_x > 0) {
            magnet_x -= MAGNET_SPEED;
        } else if (key_event->keyval == GDK_KEY_Right && magnet_x + MAGNET_WIDTH < WINDOW_WIDTH) {
            magnet_x += MAGNET_SPEED;
        }
        queue_draw();  // Redraw after movement
        return true;
    }

    bool spawn_egg() {
        // Create a new egg at random position with random color
        Egg egg;
        egg.x = rand() % (WINDOW_WIDTH - EGG_WIDTH);
        egg.y = 0;
        egg.color_r = static_cast<double>(rand()) / RAND_MAX;
        egg.color_g = static_cast<double>(rand()) / RAND_MAX;
        egg.color_b = static_cast<double>(rand()) / RAND_MAX;
        eggs.push_back(egg);

        return true;
    }

private:
    struct Egg {
        int x, y;
        double color_r, color_g, color_b;
    };

    int score;
    int lives;
    int magnet_x;
    std::vector<Egg> eggs;

    void draw_magnet(const Cairo::RefPtr<Cairo::Context>& cr) {
        cr->set_source_rgb(1.0, 0.0, 0.0);  // Red color

        // Left leg of the U
        cr->rectangle(magnet_x, WINDOW_HEIGHT - MAGNET_HEIGHT - 10, MAGNET_LEG_WIDTH, MAGNET_HEIGHT);
        cr->fill();

        // Right leg of the U
        cr->rectangle(magnet_x + MAGNET_WIDTH - MAGNET_LEG_WIDTH, WINDOW_HEIGHT - MAGNET_HEIGHT - 10,
                      MAGNET_LEG_WIDTH, MAGNET_HEIGHT);
        cr->fill();

        // Bottom bar of the U
        cr->rectangle(magnet_x + MAGNET_LEG_WIDTH, WINDOW_HEIGHT - MAGNET_LEG_WIDTH - 10,
                      MAGNET_WIDTH - 2 * MAGNET_LEG_WIDTH, MAGNET_LEG_WIDTH);
        cr->fill();
    }

    bool check_caught(const Egg& egg) {
        return (egg.x + EGG_WIDTH > magnet_x && egg.x < magnet_x + MAGNET_WIDTH &&
                egg.y + EGG_HEIGHT >= WINDOW_HEIGHT - MAGNET_HEIGHT - 10 &&
                egg.y + EGG_HEIGHT <= WINDOW_HEIGHT);
    }

    void game_over() {
        Gtk::MessageDialog dialog("Game Over", false, Gtk::MESSAGE_INFO);
        dialog.set_secondary_text("Your score: " + std::to_string(score));
        dialog.run();
        exit(0);  // Exit the game
    }
};

class EggCatcherWindow : public Gtk::Window {
public:
    EggCatcherWindow() {
        set_title("Egg Catcher Game - Magnet");
        set_default_size(WINDOW_WIDTH, WINDOW_HEIGHT);
        add(game_area);
        show_all_children();
    }

private:
    EggCatcherGame game_area;
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.example.eggcatcher");

    EggCatcherWindow window;
    return app->run(window);
}
