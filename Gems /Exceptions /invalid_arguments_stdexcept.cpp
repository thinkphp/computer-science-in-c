#include <iostream>
#include <stdexcept> // For std::invalid_argument

void processNumber(int number) {
    if (number < 0) {
        throw std::invalid_argument("Negative number is not allowed.");
    }
    // Function logic for valid number
    std::cout << "Processing number: " << number << std::endl;
}

int main() {
    try {
        processNumber(10); // Valid call
        processNumber(-5); // This will throw an exception
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
