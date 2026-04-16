#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

class TOH {
    int size;
    int moves;
    std::vector<std::vector<int>> towers;

    std::string makeRow(int disc) {
        if (disc == 0)
            return std::string(size + 2, ' ') + "||" + std::string(size + 2, ' ');
        if (disc == size + 1)
            return " " + std::string((size + 2) * 2, '=') + " ";
        std::string str1 = "  " + std::string(size - disc, ' ') + std::string(disc, '*');
        std::string str2 = std::string(disc, '*') + std::string(size - disc, ' ') + "  ";
        return str1 + "**" + str2;
    }

public:
    TOH(int difficulty) : size(difficulty), moves(0) {
        if (difficulty < 3 || difficulty > 10)
            throw std::invalid_argument("Incorrect Difficulty. Please provide a number between 3 and 10.");
        towers.resize(3);
        for (int i = size; i >= 1; --i)
            towers[0].push_back(i);
    }

    bool validMove(int from, int to) {
        if (from < 0 || from > 2) return false;
        if (to   < 0 || to   > 2) return false;
        if (towers[from].empty())  return false;
        if (towers[to].empty())    return true;
        return towers[from].back() < towers[to].back();
    }

    void move(int from, int to) {
        if (validMove(from, to)) {
            std::cout << "Moving disc from tower " << from << " to tower " << to << "\n\n";
            towers[to].push_back(towers[from].back());
            towers[from].pop_back();
            ++moves;
            render();
        } else {
            std::cout << "Invalid Move\n";
        }
    }

    void render() {
        std::string topRow = makeRow(0);
        std::cout << topRow << topRow << topRow << "\n";
        for (int r = size - 1; r >= 0; --r) {
            for (int t = 0; t < 3; ++t) {
                int disc = (r < (int)towers[t].size()) ? towers[t][r] : 0;
                std::cout << makeRow(disc);
            }
            std::cout << "\n";
        }
        std::string botRow = makeRow(size + 1);
        std::cout << botRow << botRow << botRow << "\n\n";
    }

    bool won() {
        return (int)towers[1].size() == size || (int)towers[2].size() == size;
    }

    // ─── Algoritmul recursiv ───────────────────────────────────────────────
    // Mută `n` discuri de pe `src` pe `dst`, folosind `aux` ca tijă auxiliară.
    // Complexitate: 2^n - 1 mutări (optimal).
    void solveRecursive(int n, int src, int dst, int aux) {
        if (n == 0) return;
        solveRecursive(n - 1, src, aux, dst);   // mută n-1 discuri pe aux
        move(src, dst);                          // mută discul cel mai mare
        std::this_thread::sleep_for(std::chrono::milliseconds(600)); // pauză vizuală
        solveRecursive(n - 1, aux, dst, src);   // mută n-1 discuri de pe aux pe dst
    }

    void autoSolve() {
        std::cout << "\n=== MOD AUTO-SOLVE ===\n";
        std::cout << "Algoritmul va muta toate discurile de pe tija 0 pe tija 2.\n";
        std::cout << "Numar optim de mutari: " << ((1 << size) - 1) << "\n\n";
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
        solveRecursive(size, 0, 2, 1);  // src=0, dst=2, aux=1
        std::cout << "Puzzle rezolvat automat in " << moves << " mutari!\n";
        int optimal = (1 << size) - 1;
        if (moves == optimal)
            std::cout << "Solutie optima. \n";
    }
    // ──────────────────────────────────────────────────────────────────────

    void play() {
        srand(static_cast<unsigned>(time(nullptr)));
        char letter = 'A' + rand() % 26;
        std::cout << "\n\nWelcome back to another exciting game of Towers of Hanoi!\n";
        std::cout << "This game is brought to you by the letter '" << letter << "'\n\n";
        std::cout << "This game's difficulty is set to " << size << "\n";
        std::cout << "Move discs by entering which tower you would like to take from and where you would like to place it.\n";
        std::cout << "Type 'quit' to exit, 'solve' to auto-solve.\n";
        std::cout << "Good luck and have fun!\n\n";
        render();

        while (!won()) {
            std::cout << "Enter your move (Ex: '0 1'): ";
            std::string line;
            std::getline(std::cin, line);

            if (line == "quit" || line == "Quit" || line == "QUIT") {
                std::cout << "Quitting the game...\n";
                return;
            }
            if (line == "solve" || line == "SOLVE") {
                autoSolve();
                return;
            }

            int from, to;
            if (sscanf(line.c_str(), "%d %d", &from, &to) != 2) {
                std::cout << "Invalid input. Try again.\n";
                continue;
            }
            move(from, to);
        }

        std::cout << "You've solved the puzzle!\nCongratulations!\n";
        std::cout << "It took you " << moves << " moves\n";
        int optimal = (1 << size) - 1;
        if (moves == optimal)
            std::cout << "This was an optimal solution. Great Job!\n";
        else
            std::cout << "The optimal solution for this difficulty is " << optimal << " moves.\n";
    }
};

int main() {
    int difficulty;
    std::cout << "Enter a difficulty (3 - 10): ";
    std::cin >> difficulty;
    std::cin.ignore();
    try {
        TOH game(difficulty);
        game.play();
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
    return 0;
}
