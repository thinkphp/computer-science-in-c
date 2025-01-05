# Catalan Numbers

## Definiție
Numerele Catalan reprezintă o secvență de numere naturale care apar în diverse probleme combinatorice. Ele sunt numite după matematicianul belgian Eugène Charles Catalan (1814-1894).

## Formula generală
Al n-lea număr Catalan, notat cu Cn, poate fi calculat folosind următoarea formulă:

Cn = (1/(n+1)) * (2n n)

sau alternativ:

Cn = (2n)! / ((n+1)!n!)

## Primele numere Catalan
Primele 10 numere Catalan sunt:
1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862

## Aplicații și exemple
Numerele Catalan apar în multe probleme combinatorice, inclusiv:

1. **Paranteze valide**: Numărul de moduri în care se pot aranja n perechi de paranteze astfel încât să fie corect închise.
   Exemplu pentru n=3: ((())), ()(()), ()()(), (())(), (()())

2. **Triangularea poligoanelor**: Numărul de modalități de a triangula un poligon convex cu (n+2) laturi.

3. **Arbori binari**: Numărul de arbori binari diferiți care pot fi construiți cu n noduri.

## Proprietăți importante
1. Recurența: Cn+1 = Σ(i=0 to n) CiCn-i
2. Numerele Catalan sunt întotdeauna numere întregi
3. Cresc foarte rapid: aproximativ exponențial

## Demonstrație pentru primele cazuri

Pentru n = 0: C0 = 1
Pentru n = 1: C1 = 1
Pentru n = 2: C2 = 2
Pentru n = 3: C3 = 5

Acest șir de numere poate fi generat folosind formula recurentă sau formula directă prezentată mai sus.

### Practice

https://www.pbinfo.ro/probleme/2917/catalan
https://cses.fi/problemset/task/2064/
https://cses.fi/problemset/task/2187/
https://www.pbinfo.ro/probleme/eticheta/219/numarul-lui-catalan

### Reference 
https://www.geeksforgeeks.org/program-nth-catalan-number/
https://www.pbinfo.ro/articole/28535/numerele-catalane

