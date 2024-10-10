# Binary Search Algorithm in C++

This repository contains implementations of the Binary Search Algorithm in both iterative and recursive approaches using C++.

## Table of Contents

- [Introduction](#introduction)
- [Iterative Binary Search](#iterative-binary-search)
- [Recursive Binary Search](#recursive-binary-search)
- [How to Use](#how-to-use)
- [Complexity Analysis](#complexity-analysis)

## Introduction

Binary Search is a highly efficient algorithm for finding an element in a sorted array. It works by repeatedly dividing the search interval in half, making it a logarithmic time complexity algorithm, O(log n).

In this repository, you will find two implementations:
- **Iterative Binary Search**
- **Recursive Binary Search**

Both implementations assume the input array is sorted in ascending order.

## Iterative Binary Search

The iterative binary search uses a `while` loop to keep halving the search interval until the target element is found or the search space is exhausted.

### C++ Code

```cpp
#include <iostream>
#include <vector>

int iterativeBinarySearch(const std::vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            start = mid + 1; // Search right half
        } else {
            end = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    int result = iterativeBinarySearch(arr, target);
    
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0;
}
```

## Recursive Binary Search

In the recursive version, the function calls itself with updated `start` and `end` bounds after comparing the middle element to the target.

### C++ Code

```cpp
#include <iostream>
#include <vector>

int recursiveBinarySearch(const std::vector<int>& arr, int start, int end, int target) {
    if (start > end) {
        return -1; // Target not found
    }
    
    int mid = start + (end - start) / 2;
    
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, end, target); // Search right half
    } else {
        return recursiveBinarySearch(arr, start, mid - 1, target); // Search left half
    }
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    int result = recursiveBinarySearch(arr, 0, arr.size() - 1, target);
    
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0;
}
```

## How to Use

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/binary-search-algorithm-cpp.git
    ```
2. Compile and run the code in your terminal:
    ```bash
    g++ iterative_binary_search.cpp -o iterative
    ./iterative
    
    g++ recursive_binary_search.cpp -o recursive
    ./recursive
    ```

Replace the array and target values with your own inputs to test the algorithm.

## Complexity Analysis

- **Time Complexity**: O(log n), where `n` is the number of elements in the array.
- **Space Complexity**:
  - Iterative: O(1)
  - Recursive: O(log n) due to recursion stack.

## Conclusion

Binary Search is an essential algorithm for efficient searching in sorted arrays. This repository demonstrates both the iterative and recursive implementations in C++. Feel free to explore the code and modify it for different use cases.
```

Acest fișier `README.md` este optimizat pentru implementările în C++ ale algoritmului de căutare binară și conține instrucțiuni pentru compilare și rulare.

## Examples:

https://ideone.com/0WVBSi

### Using Bitwise

https://ideone.com/fR8nF8

## Problem Set:

https://www.pbinfo.ro/probleme/4646/cb1

https://leetcode.com/tag/binary-search/

https://codeforces.com/problemset/problem/1945/E

https://infoarena.ro/problema/cautbin

https://www.pbinfo.ro/probleme/categorii/155/tablouri-unidimensionale-vectori-cautare-binara

https://leetcode.com/problems/valid-triangle-number/

https://leetcode.com/problems/valid-perfect-square/description/
