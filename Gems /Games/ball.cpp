#include <gtkmm.h>
#include <cairomm/context.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;
const int BALL_RADIUS = 20;

class BouncingBall : public Gtk::DrawingArea {
public:
    BouncingBall() : x(WIDTH / 2), y(HEIGHT / 2), dx(2), dy(2) {
        add_events(Gdk::KEY_PRESS_MASK);
        Glib::signal_timeout().connect(sigc::mem_fun(*this, &BouncingBall::on_timeout), 16);
    }

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        cr->set_source_rgb(1.0, 1.0, 1.0); // White background
        cr->rectangle(0, 0, WIDTH, HEIGHT);
        cr->fill();

        cr->set_source_rgb(1.0, 0.0, 0.0); // Red ball
        cr->arc(x, y, BALL_RADIUS, 0, 2 * M_PI);
        cr->fill();

        return true;
    }

private:
    double x, y; // Ball position
    double dx, dy; // Ball speed

    bool on_timeout() {
        // Update ball position
        x += dx;
        y += dy;

        // Check for collision with window edges
        if (x < BALL_RADIUS || x > WIDTH - BALL_RADIUS) {
            dx = -dx;
        }
        if (y < BALL_RADIUS || y > HEIGHT - BALL_RADIUS) {
            dy = -dy;
        }

        queue_draw(); // Redraw the window
        return true; // Continue calling this function
    }
};

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    Gtk::Window window;
    window.set_default_size(WIDTH, HEIGHT);

    BouncingBall bouncingBall;
    window.add(bouncingBall);
    bouncingBall.show();

    return app->run(window);
}
