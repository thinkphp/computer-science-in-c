#include <gtkmm.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

////g++ -std=c++11 todo_list.cpp -o todo_list `pkg-config gtkmm-3.0 --cflags --libs`

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string &desc, bool comp = false) : description(desc), completed(comp) {}

    std::string to_string() const {
        return (completed ? "[X] " : "[ ] ") + description;
    }
};

class ToDoListWindow : public Gtk::Window {
public:
    ToDoListWindow() {
        set_title("To-Do List");
        set_default_size(400, 300);

        // Layout
        vbox.set_spacing(10);
        add(vbox);

        // Task List
        task_list.set_size_request(350, 200);
        vbox.pack_start(task_list);

        // Task Entry
        task_entry.set_placeholder_text("Enter a new task");
        vbox.pack_start(task_entry);

        // Buttons
        button_box.set_spacing(5);
        vbox.pack_start(button_box);

        add_button.set_label("Add Task");
        add_button.signal_clicked().connect(sigc::mem_fun(*this, &ToDoListWindow::on_add_task));
        button_box.pack_start(add_button);

        complete_button.set_label("Mark Completed");
        complete_button.signal_clicked().connect(sigc::mem_fun(*this, &ToDoListWindow::on_mark_completed));
        button_box.pack_start(complete_button);

        update_button.set_label("Update Task");
        update_button.signal_clicked().connect(sigc::mem_fun(*this, &ToDoListWindow::on_update_task));
        button_box.pack_start(update_button);

        delete_button.set_label("Delete Task");
        delete_button.signal_clicked().connect(sigc::mem_fun(*this, &ToDoListWindow::on_delete_task));
        button_box.pack_start(delete_button);

        load_tasks();
        signal_hide().connect(sigc::mem_fun(*this, &ToDoListWindow::on_close));
        show_all_children();
    }

    ~ToDoListWindow() {
        save_tasks();
    }

protected:
    Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL};
    Gtk::Entry task_entry;
    Gtk::ListBox task_list;
    Gtk::Box button_box{Gtk::ORIENTATION_HORIZONTAL};
    Gtk::Button add_button, complete_button, update_button, delete_button;

    std::vector<Task> tasks;
    const std::string save_file = "tasks.dat";

    void on_add_task() {
        std::string description = task_entry.get_text();
        if (!description.empty()) {
            Task new_task(description);
            tasks.push_back(new_task);
            add_task_to_list(new_task);
            task_entry.set_text("");
            save_tasks();
        }
    }

    void on_mark_completed() {
        auto selected_row = task_list.get_selected_row();
        if (selected_row) {
            int index = selected_row->get_index();
            tasks[index].completed = true;
            update_task_in_list(index);
            save_tasks();
        }
    }

    void on_update_task() {
        auto selected_row = task_list.get_selected_row();
        if (selected_row) {
            int index = selected_row->get_index();
            Gtk::MessageDialog dialog(*this, "Update Task", false, Gtk::MESSAGE_QUESTION);
            dialog.set_secondary_text("Enter new task description:");
            dialog.add_button("_OK", Gtk::RESPONSE_OK);
            dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);

            Gtk::Entry entry;
            entry.set_text(tasks[index].description);
            dialog.get_vbox()->pack_end(entry);
            entry.show();

            int response = dialog.run();
            if (response == Gtk::RESPONSE_OK) {
                tasks[index].description = entry.get_text();
                update_task_in_list(index);
                save_tasks();
            }
        }
    }

    void on_delete_task() {
        auto selected_row = task_list.get_selected_row();
        if (selected_row) {
            int index = selected_row->get_index();
            tasks.erase(tasks.begin() + index);
            task_list.remove(*selected_row);
            save_tasks();
        }
    }

    void load_tasks() {
        std::ifstream file(save_file, std::ios::binary);
        if (file) {
            std::string desc;
            bool completed;
            while (file.read(reinterpret_cast<char*>(&completed), sizeof(completed))) {
                std::getline(file, desc, '\0');
                tasks.emplace_back(desc, completed);
                add_task_to_list(tasks.back());
            }
        }
    }

    void save_tasks() {
        std::ofstream file(save_file, std::ios::binary | std::ios::trunc);
        if (file) {
            for (const auto& task : tasks) {
                file.write(reinterpret_cast<const char*>(&task.completed), sizeof(task.completed));
                file.write(task.description.c_str(), task.description.size() + 1);
            }
        }
    }

    void add_task_to_list(const Task &task) {
        auto row = Gtk::make_managed<Gtk::ListBoxRow>();
        auto label = Gtk::make_managed<Gtk::Label>(task.to_string());
        row->add(*label);
        task_list.append(*row);
        row->show_all();
    }

    void update_task_in_list(int index) {
        auto row = task_list.get_row_at_index(index);
        auto label = dynamic_cast<Gtk::Label*>(row->get_child());
        if (label) {
            label->set_text(tasks[index].to_string());
        }
    }

    void on_close() {
        save_tasks();
    }
};

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.todo");

    ToDoListWindow window;

    return app->run(window);
}
