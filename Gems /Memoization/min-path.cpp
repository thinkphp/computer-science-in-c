#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

// Function to calculate the minimum path sum and track the path with memoization
int minPathSumAndTrack(const std::vector<std::vector<int>>& grid, int m, int n,
                       std::vector<std::vector<int>>& memo, std::vector<std::vector<std::pair<int, int>>>& path) {
    // Base case: if we are at the top-left corner, return its value
    if (m == 0 && n == 0) {
        path[m][n] = {-1, -1}; // No parent for the starting cell
        return grid[0][0];
    }

    // If we are out of bounds, return a large number to indicate an invalid path
    if (m < 0 || n < 0) return INT_MAX;

    // If the result is already computed, return it
    if (memo[m][n] != -1) return memo[m][n];

    // Calculate minimum path sum from top or left
    int fromTop = minPathSumAndTrack(grid, m - 1, n, memo, path);
    int fromLeft = minPathSumAndTrack(grid, m, n - 1, memo, path);

    // Choose the smaller path and update memo and path table
    if (fromTop < fromLeft) {
        memo[m][n] = grid[m][n] + fromTop;
        path[m][n] = {m - 1, n}; // From top
    } else {
        memo[m][n] = grid[m][n] + fromLeft;
        path[m][n] = {m, n - 1}; // From left
    }

    return memo[m][n];
}

// Function to retrieve and print the minimum path
void printPath(const std::vector<std::vector<std::pair<int, int>>>& path, int m, int n) {
    std::vector<std::pair<int, int>> result;
    std::pair<int, int> curr = {m, n};

    while (curr.first != -1 && curr.second != -1) {
        result.push_back(curr);
        curr = path[curr.first][curr.second];
    }

    std::cout << "Path from (0, 0) to (" << m << ", " << n << "): ";
    for (int i = result.size() - 1; i >= 0; --i) {
        std::cout << "(" << result[i].first << ", " << result[i].second << ")";
        if (i > 0) std::cout << " -> ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1)); // Initialize memoization vector with -1
    std::vector<std::vector<std::pair<int, int>>> path(m, std::vector<std::pair<int, int>>(n)); // Path tracking table

    int minPathSum = minPathSumAndTrack(grid, m - 1, n - 1, memo, path);

    std::cout << "Minimum path sum is " << minPathSum << std::endl;
    printPath(path, m - 1, n - 1);

    return 0;
}
