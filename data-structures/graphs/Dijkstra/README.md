 Algoritmul lui Dijkstra - Drumul cel mai scurt

## Descriere

**Algoritmul lui Dijkstra** este un algoritm pentru găsirea drumului cel mai scurt între un nod sursă și toate celelalte noduri într-un graf ponderat cu greutăți pozitive. Dezvoltat de Edsger W. Dijkstra în 1956, este unul dintre algoritmii fundamentali în teoria grafurilor.

## Principiul Algoritmului

Algoritmul funcționează pe principiul **programării dinamice** și al **strategiei lacome**:
- Menține o estimare a distanței minime de la sursa la fiecare nod
- La fiecare pas, selectează nodul cu distanța minimă din mulțimea nodurilor neprocesate
- Actualizează distanțele către nodurile vecine folosind **relaxarea muchiilor**

## Cum Funcționează

### Pașii Algoritmului

1. **Inițializare**
   - Distanța de la sursa la ea însăși = 0
   - Distanța de la sursa la toate celelalte noduri = ∞
   - Toate nodurile sunt marcate ca neprocesate

2. **Procesare iterativă**
   - Se selectează nodul neprocesat cu distanța minimă
   - Se marchează nodul ca procesat
   - Pentru fiecare vecin al nodului curent:
     - Se calculează distanța prin nodul curent
     - Dacă această distanță < distanța actuală, se actualizează

3. **Condiția de oprire**
   - Când toate nodurile au fost procesate
   - Sau când nodul destinație a fost procesat

### Pseudocod

```
DIJKSTRA(Graf, sursa):
    dist[sursa] = 0
    pentru fiecare nod v ≠ sursa:
        dist[v] = ∞
        parent[v] = NEDEFINIT
    
    Q = toate nodurile din graf
    
    câtă vreme Q nu este vid:
        u = nodul din Q cu dist[u] minimă
        elimină u din Q
        
        pentru fiecare vecin v al lui u:
            alt = dist[u] + greutate(u, v)
            dacă alt < dist[v]:
                dist[v] = alt
                parent[v] = u
    
    returnează dist, parent
```

## Exemplu Pas cu Pas

Să urmărim algoritmul pe graful:
```
    4     5
A ----B----C
|     |    |
2|    1|   |8
|     |    |
D-----E----F
   10    3
```

**Sursa: A, Destinația: F**

| Pas | Nod Curent | Distanțe | Noduri Neprocesate |
|-----|------------|----------|-------------------|
| 0   | -          | A:0, B:∞, C:∞, D:∞, E:∞, F:∞ | {A,B,C,D,E,F} |
| 1   | A (0)      | A:0, B:4, C:∞, D:2, E:∞, F:∞ | {B,C,D,E,F} |
| 2   | D (2)      | A:0, B:4, C:∞, D:2, E:12, F:∞ | {B,C,E,F} |
| 3   | B (4)      | A:0, B:4, C:9, D:2, E:5, F:∞ | {C,E,F} |
| 4   | E (5)      | A:0, B:4, C:9, D:2, E:5, F:8 | {C,F} |
| 5   | F (8)      | A:0, B:4, C:9, D:2, E:5, F:8 | {C} |

**Rezultat**: Drumul cel mai scurt A → F = 8 (A → B → E → F)

## Complexitatea

### Complexitatea Temporală
- **Cu listă de adiacență și heap binar**: O((V + E) log V)
- **Cu matrice de adiacență**: O(V²)
- **Cu heap Fibonacci**: O(E + V log V)

### Complexitatea Spațială
- O(V) pentru stocarea distanțelor și părinților

## Implementare în C

### Structuri de Date

```c
#define MAX_VERTICES 100
#define INF INT_MAX

// Reprezentarea grafului prin matricea de adiacență
int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];    // Distanțele minime
int visited[MAX_VERTICES]; // Nodurile procesate
int parent[MAX_VERTICES];  // Pentru reconstruirea drumului
```

### Funcții Principale

1. **`dijkstra()`** - Implementarea algoritmului principal
2. **`find_min_distance()`** - Găsește nodul cu distanța minimă
3. **`print_path()`** - Reconstituie și afișează drumul
4. **`print_solution()`** - Afișează rezultatele

## Condiții și Limitări

### Condiții de Aplicabilitate
- ✅ Grafuri orientate sau neorientate
- ✅ Greutăți pozitive ale muchiilor
- ✅ Graf conex (pentru a găsi drumuri către toate nodurile)

### Limitări
- ❌ **Nu funcționează** cu greutăți negative
- ❌ Pentru greutăți negative, folosiți **algoritmul Bellman-Ford**
- ❌ Ineficient pentru grafuri foarte mari cu implementarea naivă

## Comparații cu Alți Algoritmi

| Algoritm | Greutăți Negative | Complexitate | Tip Problemă |
|----------|-------------------|--------------|--------------|
| Dijkstra | ❌ | O(V²) sau O(E log V) | Un singur sursa |
| Bellman-Ford | ✅ | O(VE) | Un singur sursa |
| Floyd-Warshall | ✅ | O(V³) | Toate perechile |
| A* | ❌ | Depinde de euristică | Punct la punct |

## Aplicații Practice

### Rețele și Telecomunicații
- Rutarea pachetelor în rețele
- Găsirea celei mai scurte căi în Internet
- Optimizarea latențelor în rețele

### Transport și Logistică
- Navigația GPS
- Planificarea traseelor de transport
- Optimizarea livărilor

### Gaming și Simulări
- Pathfinding în jocuri video
- Inteligența artificială pentru NPC-uri
- Simularea mișcării în medii virtuale

### Alte Domenii
- Analiza rețelelor sociale
- Bioinformatică (analiza secvențelor)
- Optimizarea în inginerie

## Avantaje și Dezavantaje

### Avantaje ✅
- **Corectitudine**: Garantează soluția optimă
- **Eficiență**: Bună pentru grafuri cu greutăți pozitive
- **Versatilitate**: Funcționează pe diverse tipuri de grafuri
- **Simplitate**: Relativ ușor de implementat și înțeles

### Dezavantaje ❌
- **Limitare**: Nu funcționează cu greutăți negative
- **Memorie**: Poate necesita mult spațiu pentru grafuri mari
- **Complexitate**: O(V²) în implementarea naivă

## Optimizări Posibile

### 1. Folosirea Heap-ului
```c
// În loc de căutare liniară O(V)
int min_vertex = find_min_distance(dist, visited, vertices);

// Se poate folosi min-heap O(log V)
// Reduce complexitatea de la O(V²) la O(E log V)
```

### 2. Oprirea Timpurie
```c
// Dacă căutăm drumul către un nod specific
if (current_vertex == destination) {
    break; // Oprește algoritmul
}
```

### 3. Optimizarea Memoriei
- Folosirea listelor de adiacență în loc de matrice
- Stocarea doar a nodurilor accesibile

## Exemplo de Utilizare

```c
// Compilare
gcc dijkstra.c -o dijkstra

// Rulare
./dijkstra

// Input
Enter number of vertices: 5
Enter adjacency matrix:
0 4 2 0 0
4 0 1 5 0
2 1 0 8 10
0 5 8 0 2
0 0 10 2 0

Enter source vertex: 0
Enter destination vertex: 4

// Output
Shortest distance from 0 to 4: 8
Shortest path: 0 -> 1 -> 2 -> 3 -> 4
```

## Concluzie

Algoritmul lui Dijkstra rămâne unul dintre cei mai importanți algoritmi pentru problemele de drum cel mai scurt. Deși are limitările sale (greutăți pozitive), eficiența și corectitudinea sa îl fac indispensabil în multe aplicații practice. Înțelegerea acestui algoritm este fundamentală pentru oricine lucrează cu grafuri și optimizare.
Pentru grafuri cu greutăți negative, considerați algoritmul Bellman-Ford. Pentru toate perechile de noduri, Floyd-Warshall poate fi mai potrivit.

##### Practice
0. https://ideone.com/thinkphp/dijkstra
1. https://ideone.com/NCMV8S vector < pair <int, int> > G[50005]; set < pair <int, int> > s;
2. https://ideone.com/MFrfx7  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
3. https://ideone.com/vc0dRN vector<int> V[ MAXN ]; vector<int> C[ MAXN ]; int distMin[ MAXN ]; queue<int> Queue; bitset<MAXN> inQueue(0);

### Problem Set

 - San Francisco https://kilonova.ro/problems/2411

 - Ateleport https://kilonova.ro/problems/17/

 - Algoritmul lui Dijkstra https://www.infoarena.ro/problema/dijkstra

 - SHPATH - The Shortest Path https://www.spoj.com/problems/SHPATH/

 - TRVCOST - Travelling cost https://www.spoj.com/problems/TRVCOST/

 - Catun https://infoarena.ro/problema/catun
