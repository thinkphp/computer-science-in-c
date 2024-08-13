#include <gtkmm.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

class Calculator : public Gtk::Window
{
public:
    Calculator()
    {
        set_title("Simple Calculator");
        set_default_size(300, 400);

        // Set up the layout
        vbox.set_orientation(Gtk::ORIENTATION_VERTICAL);
        add(vbox);

        // Entry for displaying the expression and result
        entry.set_editable(false);
        entry.set_alignment(Gtk::ALIGN_END);
        vbox.pack_start(entry, Gtk::PACK_SHRINK);

        // Grid for buttons
        grid.set_row_homogeneous(true);
        grid.set_column_homogeneous(true);
        vbox.pack_start(grid);

        // Create and place buttons
        const std::vector<std::string> buttons = {
            "7", "8", "9", "+",
            "4", "5", "6", "-",
            "1", "2", "3", "*",
            "0", "C", "=", "/"
        };

        int i = 0;
        for (const auto& label : buttons)
        {
            auto button = Gtk::manage(new Gtk::Button(label));
            button->signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Calculator::on_button_clicked), label));
            grid.attach(*button, i % 4, i / 4, 1, 1);
            ++i;
        }

        show_all_children();
    }

protected:
    void on_button_clicked(const std::string& button_label)
    {
        if (button_label == "C")
        {
            expression.clear();
            entry.set_text("");
        }
        else if (button_label == "=")
        {
            try
            {
                auto result = evaluate_expression(expression);
                entry.set_text(result);
                expression = result;
            }
            catch (const std::exception& e)
            {
                entry.set_text("Error");
                expression.clear();
            }
        }
        else
        {
            expression += button_label;
            entry.set_text(expression);
        }
    }

    std::string evaluate_expression(const std::string& expr)
    {
        // Simple evaluation using a basic parser
        std::istringstream iss(expr);
        double result = 0.0;
        char op = '+';
        double number;
        while (iss >> number)
        {
            switch (op)
            {
                case '+': result += number; break;
                case '-': result -= number; break;
                case '*': result *= number; break;
                case '/': result /= number; break;
                default: throw std::runtime_error("Unknown operator");
            }
            iss >> op;
        }
        std::ostringstream oss;
        oss << result;
        return oss.str();
    }

private:
    Gtk::Box vbox{Gtk::ORIENTATION_VERTICAL};
    Gtk::Entry entry;
    Gtk::Grid grid;
    std::string expression;
};

int main(int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.calculator");

    Calculator calculator;

    return app->run(calculator);
}
