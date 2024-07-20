#include <iostream>
#include <stdexcept>

void setAge(int age) {
    if (age < 0 || age > 150) {
        throw std::invalid_argument("Age must be between 0 and 150.");
    }
    std::cout << "Age set to: " << age << std::endl;
}

int main() {
    try {
        setAge(25);    // Valid age
        setAge(-1);    // Invalid age, will throw an exception
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
