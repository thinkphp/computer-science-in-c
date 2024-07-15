#include <iostream>
#include <vector>

// Function to calculate number of ways to climb stairs using memoization
int countWays(int n, std::vector<int>& memo) {
    // Base cases
    if (n == 0) return 1; // Base case: There is one way to stay at the ground level (do nothing).
    if (n < 0) return 0; // Base case: Negative steps, no way to climb.

    // If the result is already computed, return it
    if (memo[n] != -1) return memo[n];

    // Compute number of ways and store in memo
    memo[n] = countWays(n - 1, memo) + countWays(n - 2, memo) + countWays(n - 3, memo);
    return memo[n];
}

int main() {
    int n = 5; // Example: Calculate number of ways to climb 5 steps

    std::vector<int> memo(n + 1, -1); // Memoization array initialized with -1
    int result = countWays(n, memo);

    std::cout << "Number of ways to climb " << n << " steps: " << result << std::endl;

    return 0;
}
