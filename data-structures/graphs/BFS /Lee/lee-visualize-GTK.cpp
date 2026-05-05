// Compilare:
//   g++ lee_visualizer.cpp -o lee_visualizer $(pkg-config --cflags --libs gtkmm-3.0) -std=c++17
//
// Necesar: libgtkmm-3.0-dev
//   sudo apt install libgtkmm-3.0-dev

#include <gtkmm.h>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

// ======================= LOGIC ENGINE =======================
class Pathfinder {
public:
    static const int N = 6;
    static const int M = 6;

    int grid[N][M] = {
        {0,0,0,1,0,0},
        {1,1,0,1,0,1},
        {0,0,0,0,0,0},
        {0,1,1,1,1,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    int dist[N][M];
    pair<int,int> parent[N][M];
    vector<pair<int,int>> bfs_queue;   // manual queue for inQueue lookup
    set<pair<int,int>> in_queue_set;
    int qhead = 0;

    int sx=0, sy=0, ex=4, ey=5;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    enum Phase { BFS, BUILD_PATH, DONE } phase = BFS;
    vector<pair<int,int>> path;
    int step_count = 0;
    string status_msg;

    Pathfinder() { reset(); }

    void reset() {
        bfs_queue.clear();
        in_queue_set.clear();
        qhead = 0;
        path.clear();
        phase = BFS;
        step_count = 0;
        status_msg = "Apasă Start sau Pas pentru a rula algoritmul.";

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++) {
                dist[i][j] = -1;
                parent[i][j] = {-1,-1};
            }
        dist[sx][sy] = 0;
        bfs_queue.push_back({sx,sy});
        in_queue_set.insert({sx,sy});
    }

    // Returns true if more steps available
    bool step() {
        if(phase == DONE) return false;

        if(phase == BUILD_PATH) {
            build_path();
            phase = DONE;
            if(path.size() > 0)
                status_msg = "Drum gasit! Lungime: " + to_string((int)path.size()-1)
                           + " pasi (" + to_string(step_count) + " noduri procesate)";
            else
                status_msg = "Nu exista drum! (" + to_string(step_count) + " noduri procesate)";
            return false;
        }

        // BFS phase
        if(qhead >= (int)bfs_queue.size()) {
            phase = BUILD_PATH;
            return step();
        }

        auto [x,y] = bfs_queue[qhead++];
        in_queue_set.erase({x,y});
        step_count++;

        if(x == ex && y == ey) {
            // Flush queue
            qhead = (int)bfs_queue.size();
            in_queue_set.clear();
            phase = BUILD_PATH;
            return step();
        }

        for(int k=0;k<4;k++) {
            int nx=x+dx[k], ny=y+dy[k];
            if(nx>=0 && nx<N && ny>=0 && ny<M
               && grid[nx][ny]==0 && dist[nx][ny]==-1) {
                dist[nx][ny] = dist[x][y]+1;
                parent[nx][ny] = {x,y};
                bfs_queue.push_back({nx,ny});
                in_queue_set.insert({nx,ny});
            }
        }

        ostringstream oss;
        oss << "Procesare nod (" << x << "," << y << ") dist=" << dist[x][y]
            << "  |  Coada: " << (int)(bfs_queue.size()-qhead) << " noduri";
        status_msg = oss.str();
        return true;
    }

    void build_path() {
        path.clear();
        if(dist[ex][ey]==-1) return;
        pair<int,int> cur={ex,ey};
        while(cur.first != -1) {
            path.push_back(cur);
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
    }

    bool is_in_queue(int i, int j) const {
        return in_queue_set.count({i,j}) > 0;
    }

    bool is_on_path(int i, int j) const {
        for(auto &p : path)
            if(p.first==i && p.second==j) return true;
        return false;
    }
};

// ======================= DRAWING AREA =======================
class LeeCanvas : public Gtk::DrawingArea {
public:
    Pathfinder *engine = nullptr;
    static const int CELL = 70;

    LeeCanvas() {
        set_size_request(Pathfinder::M * CELL, Pathfinder::N * CELL);
    }

protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        if(!engine) return true;

        const int N = Pathfinder::N, M = Pathfinder::M;

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                double px = j*CELL, py = i*CELL;

                // Base fill
                if(engine->grid[i][j] == 1) {
                    cr->set_source_rgb(0.067, 0.067, 0.067);  // near-black wall
                } else {
                    cr->set_source_rgb(0.976, 0.980, 0.984);  // light gray empty
                }
                cr->rectangle(px, py, CELL, CELL);
                cr->fill();

                if(engine->grid[i][j] == 0) {
                    bool on_path   = engine->phase == Pathfinder::DONE && engine->is_on_path(i,j);
                    bool in_queue  = engine->is_in_queue(i,j);
                    bool visited   = engine->dist[i][j] != -1;

                    if(on_path) {
                        cr->set_source_rgba(0.980, 0.800, 0.082, 0.93); // yellow
                    } else if(in_queue) {
                        cr->set_source_rgba(0.655, 0.545, 0.980, 0.50); // purple
                    } else if(visited) {
                        cr->set_source_rgba(0.231, 0.510, 0.965, 0.25); // blue tint
                    } else {
                        goto skip_overlay;
                    }
                    cr->rectangle(px, py, CELL, CELL);
                    cr->fill();
                    skip_overlay:;

                    // Distance number
                    if(engine->dist[i][j] != -1) {
                        cr->set_source_rgba(0.1, 0.1, 0.1, 0.55);
                        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
                        cr->set_font_size(14);
                        string s = to_string(engine->dist[i][j]);
                        Cairo::TextExtents te;
                        cr->get_text_extents(s, te);
                        cr->move_to(px + CELL/2.0 - te.width/2 - te.x_bearing,
                                    py + CELL/2.0 - te.height/2 - te.y_bearing);
                        cr->show_text(s);
                    }
                }

                // Grid lines
                cr->set_source_rgba(0, 0, 0, 0.10);
                cr->set_line_width(0.5);
                cr->rectangle(px, py, CELL, CELL);
                cr->stroke();
            }
        }

        // Start cell (green rounded square)
        draw_marker(cr, engine->sy, engine->sx, 0.133, 0.773, 0.368, "S");
        // End cell (red rounded square)
        draw_marker(cr, engine->ey, engine->ex, 0.937, 0.267, 0.267, "E");

        return true;
    }

private:
    void draw_marker(const Cairo::RefPtr<Cairo::Context>& cr,
                     int col, int row,
                     double r, double g, double b,
                     const string& label)
    {
        double px = col*CELL + 4, py = row*CELL + 4;
        double w = CELL - 8, h = CELL - 8;
        double rad = 6;
        cr->set_source_rgb(r,g,b);
        cr->move_to(px+rad, py);
        cr->line_to(px+w-rad, py);
        cr->arc(px+w-rad, py+rad, rad, -M_PI/2, 0);
        cr->line_to(px+w, py+h-rad);
        cr->arc(px+w-rad, py+h-rad, rad, 0, M_PI/2);
        cr->line_to(px+rad, py+h);
        cr->arc(px+rad, py+h-rad, rad, M_PI/2, M_PI);
        cr->line_to(px, py+rad);
        cr->arc(px+rad, py+rad, rad, M_PI, 3*M_PI/2);
        cr->close_path();
        cr->fill();

        cr->set_source_rgb(1,1,1);
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_BOLD);
        cr->set_font_size(15);
        Cairo::TextExtents te;
        cr->get_text_extents(label, te);
        cr->move_to(col*CELL + CELL/2.0 - te.width/2 - te.x_bearing,
                    row*CELL + CELL/2.0 - te.height/2 - te.y_bearing);
        cr->show_text(label);
    }
};

// ======================= LEGEND =======================
class LegendBar : public Gtk::DrawingArea {
public:
    LegendBar() { set_size_request(-1, 32); }
protected:
    bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override {
        struct Item { double r,g,b,a; const char* lbl; };
        Item items[] = {
            {0.067,0.067,0.067,1.0, "Obstacol"},
            {0.133,0.773,0.368,1.0, "Start"},
            {0.937,0.267,0.267,1.0, "Destinatie"},
            {0.231,0.510,0.965,0.30,"Vizitat"},
            {0.655,0.545,0.980,0.50,"In coada"},
            {0.980,0.800,0.082,0.93,"Drum optim"},
        };
        double x = 8;
        cr->select_font_face("Sans", Cairo::FONT_SLANT_NORMAL, Cairo::FONT_WEIGHT_NORMAL);
        cr->set_font_size(11);
        for(auto &it : items) {
            cr->set_source_rgba(it.r,it.g,it.b,it.a);
            cr->rectangle(x, 9, 13, 13);
            cr->fill();
            cr->set_source_rgba(0,0,0,0.25);
            cr->set_line_width(0.5);
            cr->rectangle(x, 9, 13, 13);
            cr->stroke();
            cr->set_source_rgb(0.2,0.2,0.2);
            Cairo::TextExtents te;
            cr->get_text_extents(it.lbl, te);
            cr->move_to(x+17, 9 + 13/2.0 - te.height/2 - te.y_bearing);
            cr->show_text(it.lbl);
            x += 17 + te.width + 16;
        }
        return true;
    }
};

// ======================= MAIN WINDOW =======================
class AppWindow : public Gtk::Window {
public:
    AppWindow();
private:
    Pathfinder engine;
    LeeCanvas  canvas;
    LegendBar  legend;

    Gtk::Box   vbox{Gtk::ORIENTATION_VERTICAL, 0};
    Gtk::Box   btn_box{Gtk::ORIENTATION_HORIZONTAL, 8};
    Gtk::Box   speed_box{Gtk::ORIENTATION_HORIZONTAL, 8};

    Gtk::Button btn_start{"▶  Start"};
    Gtk::Button btn_step {"  Pas  "};
    Gtk::Button btn_reset{"↺  Reset"};

    Gtk::Label  lbl_speed{"Viteză:"};
    Gtk::Scale  slider_speed{Gtk::ORIENTATION_HORIZONTAL};
    Gtk::Label  lbl_speed_val{"300 ms"};

    Gtk::Label  lbl_status;

    bool running = false;
    sigc::connection timer_conn;

    void on_start_clicked();
    void on_step_clicked();
    void on_reset_clicked();
    bool on_timer();
    void update_status();
    void reconnect_timer();
};

AppWindow::AppWindow() {
    set_title("Lee Algorithm Visualizer");
    set_resizable(false);

    // CSS styling
    auto css = Gtk::CssProvider::create();
    css->load_from_data(R"(
        window { background-color: #f8f8f8; }
        button {
            padding: 6px 18px;
            border-radius: 7px;
            border: 1px solid rgba(0,0,0,0.18);
            background: white;
            font-size: 13px;
        }
        button:hover { background: #f0f0f0; }
        button:active { background: #e4e4e4; }
        label#status {
            font-size: 12px;
            color: #666;
        }
        label#speed-val {
            font-size: 12px;
            font-weight: bold;
            min-width: 52px;
            color: #333;
        }
        label#speed-lbl { font-size: 12px; color: #555; }
    )");
    get_style_context()->add_provider_for_screen(
        Gdk::Screen::get_default(), css,
        GTK_STYLE_PROVIDER_PRIORITY_USER);

    canvas.engine = &engine;

    // Speed slider: 50..800, default 300
    slider_speed.set_range(50, 800);
    slider_speed.set_value(300);
    slider_speed.set_size_request(140, -1);
    slider_speed.set_draw_value(false);
    slider_speed.signal_value_changed().connect([&](){
        int v = (int)slider_speed.get_value();
        lbl_speed_val.set_text(to_string(v) + " ms");
        if(running) {
            timer_conn.disconnect();
            reconnect_timer();
        }
    });

    lbl_speed.set_name("speed-lbl");
    lbl_speed_val.set_name("speed-val");
    lbl_status.set_name("status");
    lbl_status.set_text(engine.status_msg);
    lbl_status.set_xalign(0.5);

    // Button signals
    btn_start.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_start_clicked));
    btn_step .signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_step_clicked));
    btn_reset.signal_clicked().connect(sigc::mem_fun(*this, &AppWindow::on_reset_clicked));

    // Layout
    btn_box.set_halign(Gtk::ALIGN_CENTER);
    btn_box.pack_start(btn_start, false, false);
    btn_box.pack_start(btn_step,  false, false);
    btn_box.pack_start(btn_reset, false, false);

    speed_box.set_halign(Gtk::ALIGN_CENTER);
    speed_box.pack_start(lbl_speed,      false, false);
    speed_box.pack_start(slider_speed,   false, false);
    speed_box.pack_start(lbl_speed_val,  false, false);

    vbox.set_margin_top(14);
    vbox.set_margin_bottom(14);
    vbox.set_margin_start(14);
    vbox.set_margin_end(14);
    vbox.set_spacing(10);

    vbox.pack_start(canvas,     false, false);
    vbox.pack_start(legend,     false, false);
    vbox.pack_start(btn_box,    false, false);
    vbox.pack_start(speed_box,  false, false);
    vbox.pack_start(lbl_status, false, false);

    add(vbox);
    show_all_children();
}

void AppWindow::reconnect_timer() {
    int ms = max(50, (int)slider_speed.get_value());
    timer_conn = Glib::signal_timeout().connect(
        sigc::mem_fun(*this, &AppWindow::on_timer), ms);
}

void AppWindow::on_start_clicked() {
    if(engine.phase == Pathfinder::DONE) {
        on_reset_clicked();
        return;
    }
    running = !running;
    if(running) {
        btn_start.set_label("⏸  Pauză");
        btn_step.set_sensitive(false);
        reconnect_timer();
    } else {
        btn_start.set_label("▶  Start");
        btn_step.set_sensitive(true);
        timer_conn.disconnect();
    }
}

void AppWindow::on_step_clicked() {
    if(engine.phase == Pathfinder::DONE) return;
    bool cont = engine.step();
    canvas.queue_draw();
    update_status();
    if(!cont) {
        btn_step.set_sensitive(false);
        btn_start.set_label("↺  Restart");
    }
}

void AppWindow::on_reset_clicked() {
    running = false;
    timer_conn.disconnect();
    engine.reset();
    btn_start.set_label("▶  Start");
    btn_step.set_sensitive(true);
    canvas.queue_draw();
    update_status();
}

bool AppWindow::on_timer() {
    if(!running) return false;
    bool cont = engine.step();
    canvas.queue_draw();
    update_status();
    if(!cont) {
        running = false;
        btn_start.set_label("↺  Restart");
        btn_step.set_sensitive(false);
        return false;
    }
    return true;
}

void AppWindow::update_status() {
    lbl_status.set_text(engine.status_msg);
}

// ======================= MAIN =======================
int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "lee.visualizer");
    AppWindow win;
    return app->run(win);
}
