## Hash Data Structure

If keys are small integers, we can use an array to implement a symbol table, by interpreting the key as an array index so that we can store the value associated with key i in array position i. In this section, we consider hashing, an extension of this simple method that handles more complicated types of keys. We reference key-value pairs using arrays by doing arithmetic operations to transform keys into array indices.

crux of hashing
Search algorithms that use hashing consist of two separate parts. The first step is to compute a hash function that transforms the search key into an array index. Ideally, different keys would map to different indices. This ideal is generally beyond our reach, so we have to face the possibility that two or more different keys may hash to the same array index. Thus, the second part of a hashing search is a collision-resolution process that deals with this situation.

## Practice

https://infoarena.ro/problema/hashuri

### References

https://algs4.cs.princeton.edu/34hash/

https://www.eecs.umich.edu/courses/eecs380/ALG/niemann/s_man.htm

https://www.geeksforgeeks.org/hashing-data-structure/

https://leetcode.com/explore/learn/card/hash-table/
