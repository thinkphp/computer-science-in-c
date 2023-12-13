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

### Properties of binary relations

```
• A relation R over set S is reflexive means R(a,a) for all a in S
– e.g. The relation “<=“ on the set of integers {1, 2, 3} is
{<1, 1>, <1, 2>, <1, 3>, <2, 2>, <2, 3>, <3, 3>}
It is reflexive because <1, 1>, <2, 2>, <3, 3> are in this relation.
• A relation R on a set S is symmetric if and only if for any a and b in S,
whenever <a, b> is in R , <b, a> is in R .
– e.g. The relation “=“ on the set of integers {1, 2, 3} is
{<1, 1> , <2, 2> <3, 3> } and it is symmetric.
– The relation "being acquainted with" on a set of people is symmetric.
• A binary relation R over set S is transitive means:
If R(a,b) and R(b,c) then R(a,c) for all a,b,c in S
– e.g. The relation “<=“ on the set of integers {1, 2, 3} is transitive, because for
<1, 2> and <2, 3> in “<=“, <1, 3> is also in “<=“ (and similarly for the others)
```

### Equivalence Relations
```
A binary relation R is an equivalence relation if R is
reflexive, symmetric, and transitive
• Examples
– Same gender
– Connected roads in the world
– "Is equal to" on the set of real numbers
– "Has the same birthday as" on the set of all people 
```

### Punch-line

```
Equivalence relations give rise to partitions.
• Every partition induces an equivalence relation
• Every equivalence relation induces a partition
• Suppose P={S1,S2,…,Sn} is a partition
– Define R(x,y) to mean x and y are in the same Si
• R is an equivalence relation
• Suppose R is an equivalence relation over S
– Consider a set of sets S1,S2,…,Sn where
(1) x and y are in the same Si if and only if R(x,y)
(2) Every x is in some Si
• This set of sets is a partition
```

#### Practice

https://codeforces.com/contest/988/problem/A

#### References:

* https://www.codingninjas.com/studio/library/disjoint-set-unions-union-find-algorithm

* https://courses.cs.washington.edu/courses/cse373/14sp/lecture10.pdf

* https://cseweb.ucsd.edu/classes/fa14/cse100/lectures/Lec19_annotated_pdf.pdf

* https://www.infoarena.ro/problema/disjoint

* https://www.pbinfo.ro/articole/6024/paduri-de-multimi-disjuncte
