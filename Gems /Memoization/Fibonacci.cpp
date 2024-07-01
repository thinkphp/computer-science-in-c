#include <iostream>
#include <unordered_map>

// Function to calculate Fibonacci using memoization
long long fibonacci(int n, std::unordered_map<int, long long>& memo) {
    // Check if the value is already computed
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // Base cases
    if (n <= 1) {
        return n;
    }

    // Recursive call with memoization
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    std::unordered_map<int, long long> memo; // Memoization table
    int n;

    std::cout << "Enter a number: ";
    std::cin >> n;

    // Compute Fibonacci number
    long long result = fibonacci(n, memo);
    std::cout << "Fibonacci(" << n << ") = " << result << std::endl;

    return 0;
}
