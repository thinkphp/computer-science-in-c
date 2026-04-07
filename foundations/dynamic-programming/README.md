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


### Classical Problems

1. LIS - Longest Increasing Subsequence
   * https://infoarena.ro/problema/scmax
   * https://cses.fi/problemset/task/1145 Increasing Subsequence
   * https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem
   * https://www.pbinfo.ro/probleme/396/sclm
   * https://www.pbinfo.ro/probleme/1876/sclm2
   * https://www.pbinfo.ro/probleme/2086/sclmprime
   

3. LCS - Longest Common Subsequence
   * https://leetcode.com/problems/longest-common-subsequence/
   * https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem
   * https://infoarena.ro/problema/cmlsc
   * https://ideone.com/6EcvVr
   * https://ideone.com/sfThv1
   * https://ideone.com/kf02K5
   * https://ideone.com/Cr2Kat for int arr1[], int arr2[]
   * https://ideone.com/tv5Ms7 for string word1, string word2
   
4. Triangle Problem
   * https://leetcode.com/problems/triangle/
   * https://ideone.com/PJBk00
   * https://www.pbinfo.ro/probleme/385/sumtri
   * https://www.pbinfo.ro/probleme/386/sumtri1
   
5. SubSet Sum Problem 
   - Partition Equal Subset Sum https://leetcode.com/problems/partition-equal-subset-sum/description/
   - Target Sum https://leetcode.com/problems/target-sum/description/
   
7. MSS - Maximum Subsequence Sum
   * https://ideone.com/3jZMWP
   
8. Knapsack Discret Problem 0/1
   - https://www.infoarena.ro/problema/rucsac
   - https://www.pbinfo.ro/probleme/1886/rucsac1
   - https://www.hackerrank.com/challenges/unbounded-knapsack/problem
   - https://ideone.com/dTwyz6

9. Matrix Chain Multiplication
   * https://ideone.com/GAFmpt
   * https://ideone.com/WMqdeW

10. Levenshtein Distance
   * https://leetcode.com/problems/edit-distance/
   * Edit Distance https://cses.fi/problemset/task/1639/
   * https://www.pbinfo.ro/solutii/user/thinkphp/problema/3655/distanta-de-editare
   * https://ideone.com/cmwTX3   
  
11. Finding Comb(n,k)
   - https://ideone.com/ZYjGlM

11. Minimum Path Sum
    - https://leetcode.com/problems/minimum-path-sum/description/

12. Climbing Stairs
    - https://leetcode.com/problems/climbing-stairs/
    
13. Removing digits
    - https://cses.fi/problemset/task/1637/

14. Frog
    - https://atcoder.jp/contests/dp/tasks/dp_a
   
15. Best Time To Buy Stocks
    - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
   
16. Stone Tile
    - https://acm.timus.ru/problem.aspx?space=1&num=1005

17. Integer Break
    - https://leetcode.com/problems/integer-break/description/

18. House Robber
    - https://leetcode.com/problems/house-robber/description/

19. Word Break
    - https://leetcode.com/problems/word-break/description/

20. Longest Palindromic Substring
    - https://leetcode.com/problems/longest-palindromic-substring/description/

21. First and Second
    - https://codeforces.com/contest/2178/problem/C

22. The Coin Change
    - https://www.hackerrank.com/challenges/coin-change/problem

23. Coin Combinations 1
    - https://cses.fi/problemset/task/1635 

24. Coin Combinations 2
    - https://cses.fi/problemset/task/1636

## Problem Set 

https://leetcode.com/tag/dynamic-programming/

https://atcoder.jp/contests/dp/tasks

https://www.pbinfo.ro/probleme/categorii/158/programare-dinamica-probleme-de-numarare

https://www.pbinfo.ro/probleme/categorii/53/programare-dinamica

https://www.pbinfo.ro/probleme/4439/limbajformal

https://www.pbinfo.ro/probleme/4576/bilbob

## References

https://www.hackerrank.com/topics/dynamic-programming

https://www.cs.princeton.edu/courses/archive/spring21/cos226/lectures/DynamicProgramming.pdf

https://www.cs.ox.ac.uk/files/13359/dynamic.pdf

https://www.infoarena.ro/pd

https://www.pbinfo.ro/articole/17951/programare-dinamica-introducere

https://www.programiz.com/dsa/longest-common-subsequence

https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03

https://web.stanford.edu/class/cs124/lec/med.pdf

https://usaco.guide/gold/intro-dp?lang=cpp

https://usaco.guide/gold/lis?lang=cpp


## Ideone

https://ideone.com/thinkphp/dynamicprogramming
