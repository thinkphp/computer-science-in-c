#include <iostream>
#include <vector>
#include <algorithm>

int fibonacciSearch(const std::vector<int>& arr, int x) {
    int n = arr.size();
    
    // Initialize Fibonacci numbers
    int fib2 = 0;   // (m-2)'th Fibonacci number
    int fib1 = 1;   // (m-1)'th Fibonacci number
    int fib = fib1 + fib2;  // m'th Fibonacci number
    
    // Find the smallest Fibonacci number greater than or equal to n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    
    // Initialize the offset
    int offset = -1;
    
    while (fib > 1) {
        // Check if fib2 is a valid index
        int i = std::min(offset + fib2, n - 1);
        
        // If x is greater than the value at index i, cut the subarray from offset to i
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        // If x is less than the value at index i, cut the subarray after i+1
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        // Element found
        else {
            return i;
        }
    }
    
    // Compare last element with x
    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }
    
    // Element not found
    return -1;
}

int main() {
    std::vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int x = 85;
    
    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    int result = fibonacciSearch(arr, x);
    
    if (result != -1) {
        std::cout << "Element " << x << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << x << " not found in the array" << std::endl;
    }
    
    // Additional test cases
    std::vector<std::pair<std::vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1},  // Element at the beginning
        {{10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, 100},  // Element at the end
        {{1, 3, 5, 7, 9, 11, 13, 15}, 8},  // Element not in the array
        {{}, 5}  // Empty array
    };
    
    for (const auto& test : testCases) {
        result = fibonacciSearch(test.first, test.second);
        std::cout << "\nSearching for " << test.second << " in array: ";
        for (int num : test.first) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        if (result != -1) {
            std::cout << "Element found at index " << result << std::endl;
        } else {
            std::cout << "Element not found in the array" << std::endl;
        }
    }
    
    return 0;
}
