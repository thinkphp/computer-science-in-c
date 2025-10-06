#include <iostream>
#include <vector>
#include <stdexcept>  // pentru std::runtime_error

int main() {
    std::vector<double> numere = {5, 0, 2, 10};  // fără "abc" sau None – C++ e tipizat strict

    for (double n : numere) {
        try {
            if (n == 0)
                throw std::runtime_error("Împărțire la zero!");
            
            double rezultat = 10 / n;
            std::cout << "10 împărțit la " << n << " = " << rezultat << '\n';
        } 
        catch (const std::exception &e) {
            std::cout << "Eroare la elementul " << n << ": " << e.what() << '\n';
        }
    }

    std::cout << "Programul a ajuns la final.\n";
    return 0;
}
