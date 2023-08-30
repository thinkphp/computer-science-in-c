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

1. LIS - Longest Increasing Subsequence
   * https://infoarena.ro/problema/scmax
   * https://cses.fi/problemset/task/1145
   * https://www.pbinfo.ro/probleme/396/sclm
   * https://www.pbinfo.ro/probleme/1876/sclm2
   * https://www.pbinfo.ro/probleme/2086/sclmprime

3. LCS - Longest Common Subsequence
   * https://leetcode.com/problems/longest-common-subsequence/
   * https://infoarena.ro/problema/cmlsc
   * https://ideone.com/6EcvVr
   * https://ideone.com/sfThv1
   * https://ideone.com/kf02K5
   * https://ideone.com/Cr2Kat for int arr1[], int arr2[]
   * https://ideone.com/tv5Ms7 for string word1, string word2
   
5. TP - Triangle Problem
   * https://ideone.com/PJBk00
   * https://www.pbinfo.ro/probleme/385/sumtri
   * https://www.pbinfo.ro/probleme/386/sumtri1
   
   
4. MSS - Maximum Subsequence Sum
   * https://ideone.com/3jZMWP
   
5. Knapsack Discret Problem.
   * https://ideone.com/dTwyz6

6. Matrix Chain Multiplication
   * https://ideone.com/GAFmpt
   * https://ideone.com/WMqdeW

8. Levenshtein Distance
   * https://leetcode.com/problems/edit-distance/
   * https://cses.fi/problemset/task/1639/
   * https://www.pbinfo.ro/solutii/user/thinkphp/problema/3655/distanta-de-editare
   * https://ideone.com/cmwTX3

10. Match Words.

11. Finding Comb(n,k)
   * https://ideone.com/ZYjGlM

## Problem Set

https://www.pbinfo.ro/probleme/categorii/158/programare-dinamica-probleme-de-numarare

https://www.pbinfo.ro/probleme/categorii/53/programare-dinamica

https://cses.fi/problemset/task/1639/

https://www.infoarena.ro/problema/rucsac

https://www.pbinfo.ro/probleme/1886/rucsac1

## References

https://www.cs.princeton.edu/courses/archive/spring21/cos226/lectures/DynamicProgramming.pdf

https://www.infoarena.ro/pd

https://www.pbinfo.ro/articole/17951/programare-dinamica-introducere

https://www.programiz.com/dsa/longest-common-subsequence

https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03

https://web.stanford.edu/class/cs124/lec/med.pdf

https://usaco.guide/gold/intro-dp?lang=cpp

https://usaco.guide/gold/lis?lang=cpp


## Ideone

https://ideone.com/thinkphp/dynamicprogramming
