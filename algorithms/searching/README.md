# Search Algorithms

Here are some popular search algorithms:

1. Linear Search:
   - Simplest method
   - Checks each element sequentially
   - Time complexity: O(n)
   - Useful for unsorted lists

2. Binary Search:
   - Efficient for sorted arrays
   - Repeatedly divides the search interval in half
   - Time complexity: O(log n)
   - Requires the list to be sorted

3. Interpolation Search:
   - Improvement over binary search for uniformly distributed sorted arrays
   - Uses position of target value to narrow search
   - Average time complexity: O(log log n)
   - Best for uniformly distributed data

4. Exponential Search:
   - Combines binary search with unbounded search
   - Useful for unbounded or infinite lists
   - Time complexity: O(log n)

5. Fibonacci Search:
   - Similar to binary search but uses Fibonacci numbers to divide the array
   - Useful when binary search is costly (e.g., for arrays stored on tape)
   - Time complexity: O(log n)

6. Sublist Search (Search a linked list in another list):
   - Searches for the occurrence of a linked list as a sublist in another linked list
   - Time complexity: O(m*n) where m and n are lengths of the two lists

7. Ternary Search:
   - Similar to binary search but divides the array into three parts instead of two
   - Time complexity: O(log3 n)

Each of these algorithms has its own strengths and is suited for different scenarios. The choice of algorithm often depends on factors like:
- Whether the data is sorted
- The size of the dataset
- The distribution of the data
- The specific requirements of the application (e.g., memory constraints, speed requirements)


#### Problem Set

https://leetcode.com/tag/sorting/
