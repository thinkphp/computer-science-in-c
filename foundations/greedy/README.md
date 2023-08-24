## Greedy Algorithm Paradigm

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
## Solutions:

1. Fractional Knapsack Problem  https://ideone.com/oaoo2H
2. Maps Coloring https://ideone.com/IJ88Fb
3. Payment Method https://ideone.com/P8qo5M

## Problem Set

https://www.pbinfo.ro/probleme/categorii/25/metoda-greedy

## References 

https://infoarena.ro/metoda-greedy-si-problema-fractionara-a-rucsacului
