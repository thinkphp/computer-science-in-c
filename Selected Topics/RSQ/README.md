# Range Sum Query Time/Space Complexity

### Brute Force 

```
| -------- | ------------ |
| Query    | O(n)         |
| Update   | O(1)         |
| Space    | O(n)         |
| -------- | ------------ |
```

### Segment Tree 
```
| -------- | ------------ |
| Build    | O(n)         |
| Query    | O(log n)     |
| Update   | O(log n)     |
| Space    | O(n) (≈ 4n)  |
| -------- | ------------ |
```

### SQRT Decomposition
```
| -------- | ------------ |
| Build    | O(n)         |
| Update   | O(1)         |
| Query    | O(√n)        |
| Space    | O(n)         |
| -------- | ------------ |
```

### Binary Indexed Tree 

```
| -------- | ------------------- |
| Build    | O(n) sau O(n log n) |
| Update   | O(log n)            |
| Query    | O(log n)            |
| Space    | O(n)                |
| -------- | ------------------- |
```

### Problem Set

- Range Sum Query https://leetcode.com/problems/range-sum-query-immutable/description/
- Range Sum Query Mutable https://leetcode.com/problems/range-sum-query-mutable/description/
- Arbori de intervale https://infoarena.ro/problema/arbint
