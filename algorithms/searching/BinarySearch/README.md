# Binary Search Algorithm

This repository contains implementations of the Binary Search Algorithm in both iterative and recursive approaches.

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

### Pseudocode

```text
binarySearch(arr, target):
  start = 0
  end = length(arr) - 1
  
  while start <= end:
    mid = start + (end - start) / 2
    if arr[mid] == target:
      return mid
    else if arr[mid] < target:
      start = mid + 1
    else:
      end = mid - 1
    
  return -1  # Target not found
```

## Recursive Binary Search

In the recursive version, the function calls itself with updated `start` and `end` bounds after comparing the middle element to the target.

### Pseudocode

```text
binarySearch(arr, start, end, target):
  if start > end:
    return -1  # Target not found
  
  mid = start + (end - start) / 2
  
  if arr[mid] == target:
    return mid
  else if arr[mid] < target:
    return binarySearch(arr, mid + 1, end, target)
  else:
    return binarySearch(arr, start, mid - 1, target)
```

## How to Use

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/binary-search-algorithm.git
    ```
2. Run the code in your desired environment:
    ```bash
    python iterative_binary_search.py
    python recursive_binary_search.py
    ```

Replace the array and target values with your own inputs to test the algorithm.

## Complexity Analysis

- **Time Complexity**: O(log n), where `n` is the number of elements in the array.
- **Space Complexity**:
  - Iterative: O(1)
  - Recursive: O(log n) due to recursion stack.

## Conclusion

Binary Search is an essential algorithm for efficient searching in sorted arrays. This repository demonstrates both the iterative and recursive implementations. Feel free to explore the code and modify it for different use cases.

---
Acest fișier README.md este un exemplu simplu și poate fi ajustat în funcție de limbajul în care implementezi algoritmii sau alte cerințe specifice proiectului tău.



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
