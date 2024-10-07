#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    fs::path path = "."; // Directorul curent

    try {
        std::cout << "Fișiere în directorul " << path << ":\n";
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << entry.path() << "\n"; // Afișează calea fișierului
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Eroare la citirea directorului: " << e.what() << "\n";
    }

    return 0;
}
