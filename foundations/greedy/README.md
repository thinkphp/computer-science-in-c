## Greedy Technique Paradigm 

Metoda Greedy se aplica problemelor de optimizare. Aceasta
metoda determina intotdeauna o singura solutie. Ea construieste
solutia treptat: initial solutia este vida, apoi se
adauga cate un element care este cel mai promitator
la momentul respectiv (de unde provine si denumirea de greedy = lacom).
Alegand in orice moment elementul optim pentru solutia locala, se asigura
un optim local, dar nu se garanteaza ca se optine optimul global. Pentru
a se garanta acest lucru, ar trebui demonstrat sau cunoscut faptul ca
in contextul problemei, aceasta modalitate de alergere duce
la obtirea unei solutii optime. Algoritmii care implementeaza aceasta
metoda sunt performanti, chiar si-n cazul problemelor
de dimensiune foarte mari (timpul este liniar). Pentru anumite probleme
se pot proiecta algoritmi Greedy care nu furnizeaza solutia optima.
Aceasta metoda se aseamana cu Backtracking prin faptul ca vectorul-solutie se
construieste progresiv, dar nu se mai executa o intoarcere la nivelul inferior(ceea ce
explica si diferenta enorma de timp de executie relativ la cele doua metode), ci se
trece la alegerea directa a urmatorului element.

```
S1 <--- S
SOL <--- VOID
while (not finished) execute
   Choose x of S1 based on local optim
   S1 <-- S1 U {x}
   IF SOL U {x} satisfacted the criteria Then
   SOL <-- Sol U {x}
END
```
### 🟢 Basic
- Sum Problem https://ideone.com/pKkBga
- Max Problem https://ideone.com/X1vShx
- Scheduling with deadline Job Sequencing
- Huffman Coding.
- Gas Station
- Jump Game
- Egyptean Fraction

### 🟢 Greedy pe grafuri
- Kruskal's Algorithm
- Prim's Algorithm
- Dijkstra's Algorithm

### 🟢 Interval
- Spectacole Problem
- Activity Selection https://ideone.com/6324Jv
- Minimum number of platforms
- Merge Intervals (parte greedy în unele variante)
- Fractional Knapsack.

### 🟢 Greedy Heuristic
- Travelling Salesman Problem → Nearest Neighbor.
- Knight's Tour → Warnsdorff.
- Payment Method.
- Graph Coloring.


## Problem Set
- Non Overlapping https://leetcode.com/problems/non-overlapping-intervals/description/
- False Alarm https://codeforces.com/contest/2117/problem/A
- Valid Palindrome 2 https://leetcode.com/problems/valid-palindrome-ii/description/
- Remove Duplicate Letters https://leetcode.com/problems/remove-duplicate-letters/description
- https://leetcode.com/tag/greedy/
- https://www.pbinfo.ro/probleme/categorii/25/metoda-greedy
- https://www.geeksforgeeks.org/category/dsa/algorithm/greedy/

## References 

- https://www.freecodecamp.org/news/greedy-algorithms/
- https://ideone.com/thinkphp/greedy
- https://infoarena.ro/metoda-greedy-si-problema-fractionara-a-rucsacului




