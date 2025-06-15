## Algoritmul lui Kruskal

**Algoritmul lui Kruskal** este un algoritm lacom (greedy) pentru găsirea **Arborelui Parțial de Cost Minim (MST - Minimum Spanning Tree)** într-un graf neorientat, conex și ponderat.

### Definiții

**Arborele Parțial de Cost Minim** este un subgraf care:
- Conectează toate nodurile grafului
- Este un arbore (nu conține cicluri)
- Are suma greutăților muchiilor minimă

### Principiul Algoritmului

Algoritmul funcționează pe principiul **alegerii lacome**: la fiecare pas selectează muchia cu greutatea minimă care nu formează un ciclu cu muchiile deja selectate.

### Pașii Algoritmului

1. **Sortarea muchiilor**
   - Se sortează toate muchiile din graf în ordine crescătoare după greutate
   - Dacă două muchii au aceeași greutate, ordinea nu contează

2. **Inițializarea**
   - Se creează o structură Union-Find (Disjoint Set Union)
   - Fiecare nod formează inițial o mulțime separată

3. **Selecția muchiilor**
   - Se parcurg muchiile în ordinea sortată
   - Pentru fiecare muchie (u, v):
     - Se verifică dacă nodurile u și v sunt în mulțimi diferite
     - Dacă DA: muchia se adaugă în MST și se unesc mulțimile
     - Dacă NU: muchia se respinge (ar crea un ciclu)

4. **Condiția de oprire**
   - Algoritmul se oprește când MST conține V-1 muchii (unde V = numărul de noduri)
   - Sau când s-au procesat toate muchiile

### Pseudocod

```
KRUSKAL(G):
    MST = ∅
    Sortează muchiile din G crescător după greutate
    
    Pentru fiecare nod v din G:
        MAKE-SET(v)
    
    Pentru fiecare muchie (u,v) în ordine sortată:
        dacă FIND-SET(u) ≠ FIND-SET(v):
            MST = MST ∪ {(u,v)}
            UNION(u,v)
    
    returnează MST
```

### Structura Union-Find

Pentru detectarea eficientă a ciclurilor, algoritmul folosește **Union-Find**:

- **MAKE-SET(x)**: Creează o mulțime cu elementul x
- **FIND-SET(x)**: Găsește reprezentantul mulțimii care conține x
- **UNION(x,y)**: Unește mulțimile care conțin x și y

### Optimizări Union-Find

1. **Compresie de cale**: În FIND-SET, se face ca fiecare nod să pointeze direct către rădăcină
2. **Unire după rang**: În UNION, arborele cu înălțimea mai mică se atașează la cel cu înălțimea mai mare

### Complexitatea

- **Timp**: O(E log E) unde E = numărul de muchii
  - Sortarea: O(E log E)
  - Union-Find: O(E α(V)) ≈ O(E) practic
- **Spațiu**: O(V + E)

### Exemplu Pas cu Pas

Pentru graful cu muchiile: (0,1,4), (0,2,2), (1,2,1), (1,3,5), (2,3,8), (2,4,10), (3,4,2), (3,5,6), (4,5,3)

1. **Sortare**: (1,2,1), (0,2,2), (3,4,2), (4,5,3), (0,1,4), (1,3,5), (3,5,6), (2,3,8), (2,4,10)

2. **Procesare**:
   - (1,2,1): Acceptată - unește mulțimile {1} și {2}
   - (0,2,2): Acceptată - unește {0} cu {1,2}
   - (3,4,2): Acceptată - unește {3} și {4}
   - (4,5,3): Acceptată - unește {3,4} cu {5}
   - (0,1,4): Respinsă - 0 și 1 sunt deja conectate
   - (1,3,5): Acceptată - unește {0,1,2} cu {3,4,5}

3. **Rezultat**: MST cu muchiile (1,2), (0,2), (3,4), (4,5), (1,3) și costul total 13

### Avantaje

- Simplu de implementat și înțeles
- Eficient pentru grafuri rare (puține muchii)
- Garantează soluția optimă

### Dezavantaje

- Necesită sortarea muchiilor
- Mai puțin eficient pentru grafuri dense comparativ cu Prim
- Necesită reprezentarea grafului ca listă de muchii

### Aplicații

- Proiectarea rețelelor (telecomunicații, transport)
- Clustering în machine learning
- Aproximarea problemei Traveling Salesman
- Optimizarea costurilor în inginerie

### References

https://youtu.be/JZBQLXgSGfs?si=-2OVB02XvUL4cx9t
