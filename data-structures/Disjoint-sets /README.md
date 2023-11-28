# Disjoint-Sets or Union Find

### Disjoint Sets

A set is a collection of elements (no-repeats) 

* In computer science, two sets are said to be disjoint if they have
no element in common. 

* For example, {1, 2, 3} and {4, 5, 6} are disjoint sets

• For example, {x, y, z} and {t, u, x} are not disjoint.

### Partitions

A partition P of a set S is a set of sets {S1,S2,…,Sn} such that
every element of S is in exactly one Si 

Put another way:
```
– S1 ∪ S2 ∪ . . . ∪ Sk = S
– i ≠ j implies Si ∩ Sj
 = ∅ (sets are disjoint with each other)
```
Example:
```
– Let S be {a,b,c,d,e}
– One partition: {a}, {d,e}, {b,c}
– Another partition: {a,b,c}, ∅, {d}, {e}
– A third: {a,b,c,d,e}
– Not a partition: {a,b,d}, {c,d,e} …. element d appears twice
– Not a partition of S: {a,b}, {e,c} …. missing element d
```

### Binary relations

```
• S x S is the set of all pairs of elements of S (cartesian product)
– Example: If S = {a,b,c}
 then S x S = {(a,a),(a,b),(a,c),(b,a),(b,b),(b,c), (c,a),(c,b),(c,c)}
• A binary relation R on a set S is any subset of S x S
– i.e. a collection of ordered pairs of elements of S.
– Write R(x,y) to mean (x,y) is “in the relation”
– (Unary, ternary, quaternary, … relations defined similarly)
• Examples for S = people-in-this-room
– Sitting-next-to-each-other relation
– First-sitting-right-of-second relation
– Went-to-same-high-school relation
– First-is-younger-than-second relation 
```

#### References:

* https://courses.cs.washington.edu/courses/cse373/14sp/lecture10.pdf

* https://cseweb.ucsd.edu/classes/fa14/cse100/lectures/Lec19_annotated_pdf.pdf

* https://www.infoarena.ro/problema/disjoint

* https://www.pbinfo.ro/articole/6024/paduri-de-multimi-disjuncte
