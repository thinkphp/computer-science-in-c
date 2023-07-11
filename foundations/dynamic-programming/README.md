# Dynamic Programming

Dynamic Programming, like the divide-and-conquer method, solves problemes by combining the solutions to subproblems. "Programming"
in this context refers to a tabular method, not to writing computer code. As we saw in DivideEtImpera algorithms partion the problem
into dijoint subproblems, solve the subproblems recursively, and then combine their solutions to solve the original problem. In contrast,
dynamic programming applies when the subproblems overlap-that is, when subproblems share subsubproblems. In this context, a divideEtImpera
algorithm does more work than necessary, repeatedly solving the common subsubproblems. A dynamic programming algorithm solves each
subsubproblem just once and then saves its answer in a table, thereby avoiding the work of recomputing the answer every time it solves each
subsubproblem.

We typically apply dynamic programming to optimization problems. Such problems can have many possible solutions. Each solution has a value, and
we wish to find a solution with the optimal (minimum or maximum) value. We call such a solution an optimal solution to the problem, as opposed
to the optimal solution, since there may be several solutions that achive the optimal value.

When developing a dynamic programming algorithm, we follow a sequence of four steps:

1. Characterize the structure of an optimal solution.
2. Recursively define the value of an optimal solution.
3. Compute the value of an optimal solution, typically in a bottom-up fashion.
4. Construct an optimal solution from computed information.


### Practice

0. LIS - Longest Increasing Subsequence
   * https://cses.fi/problemset/task/1145
   * https://www.pbinfo.ro/probleme/396/sclm
   * https://www.pbinfo.ro/probleme/1876/sclm2
   * https://www.pbinfo.ro/probleme/2086/sclmprime

2. LCS - Longest Common Subsequence
   * https://ideone.com/6EcvVr
   * https://ideone.com/sfThv1
   * https://ideone.com/kf02K5
   
4. TP - Triangle Problem TP
   * https://ideone.com/PJBk00
   * https://www.pbinfo.ro/probleme/385/sumtri
   * https://www.pbinfo.ro/probleme/386/sumtri1
   
   
5. MSS - Maximum Subsequence Sum
   * https://ideone.com/3jZMWP
   
6. Knapsack Problem.
7. Match Words.
8. Generating Combinations.
9. Matrix Chain Multiplication
10. Levenshtein Distance

## Problem Set

https://www.pbinfo.ro/probleme/categorii/158/programare-dinamica-probleme-de-numarare

https://www.pbinfo.ro/probleme/categorii/53/programare-dinamica

## References

https://www.cs.princeton.edu/courses/archive/spring21/cos226/lectures/DynamicProgramming.pdf

https://www.infoarena.ro/pd

https://www.pbinfo.ro/articole/17951/programare-dinamica-introducere

https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03
