#include <iostream>
#include "math_functions.h"

int main() {
    std::cout << "GCD(48, 18) = " << MathFunctions::euclid(48, 18) << std::endl;
    std::cout << "Fibonacci(7) = " << MathFunctions::fibonacci(7) << std::endl;
    std::cout << "Factorial(5) = " << MathFunctions::factorial(5) << std::endl;
    return 0;
}
