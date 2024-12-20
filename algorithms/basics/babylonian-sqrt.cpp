#include <iostream>
#include <cmath>

double babylonianSquareRoot(double n) {
    if (n < 0) {
        std::cerr << "Error: Cannot compute square root of a negative number." << std::endl;
        return -1; // Return -1 for invalid input
    }

    double x = n;       // Initial guess
    double y = 1.0;     // Second guess
    double e = 0.000001; // Tolerance for convergence

    while ((x - y) > e) {
        x = (x + y) / 2.0; // Update x as the average of x and y
        y = n / x;         // Update y as n divided by the new x
    }

    return x; // Return the computed square root
}

int main() {
    double number;

    std::cout << "Enter a number to compute its square root: ";
    std::cin >> number;

    double result = babylonianSquareRoot(number);

    if (result != -1) { // Check for valid result
        std::cout << "The square root of " << number << " is approximately: " << result << std::endl;
    }

    return 0;
}
