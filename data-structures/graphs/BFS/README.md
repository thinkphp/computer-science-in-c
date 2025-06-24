# Breadth First Search Traversal

Funcția `int shortest_path_bfs(int start_vertex, int end_vertex)` **algoritmul Breadth-First Search (BFS)** pentru a determina **cea mai scurtă cale** între două noduri într-un graf neponderat, reprezentat prin matrice de adiacență.

---

## 📘 Ce face BFS?

Algoritmul **BFS** parcurge graful în lățime, adică explorează mai întâi vecinii apropiați ai unui nod și apoi trece la vecinii acestora. Într-un graf neponderat, BFS garantează că prima dată când ajungi la un nod o faci pe calea cea mai scurtă (adică cu cele mai puține muchii).

---

## 📌 Structura folosită: `QueueNode`

```cpp
struct QueueNode {
    int vertex;
    int distance;
};
```

Această structură reține:

* `vertex`: nodul curent;
* `distance`: distanța (numărul de muchii) de la nodul de start până la `vertex`.

---

## 🔍 Pas cu pas în funcția `shortest_path_bfs`

### 1. **Caz special – nodurile sunt identice**

```cpp
if (start_vertex == end_vertex) return 0;
```

Dacă vrem să mergem de la un nod la el însuși, distanța este 0.

---

### 2. **Verificare validitate noduri**

```cpp
if (start_vertex < 0 || start_vertex >= n_vertices || end_vertex < 0 || end_vertex >= n_vertices) {
    // Noduri invalide (în afara grafului)
    return -1;
}
```

---

### 3. **Inițializare BFS**

```cpp
queue<QueueNode> q;
fill(begin(visited), end(visited), false); // Resetăm vectorul de vizite

q.push({start_vertex, 0}); // Adăugăm nodul de start în coadă
visited[start_vertex] = true;
```

* Se folosește o **coadă** (FIFO), specifică BFS-ului.
* Nodul de start este vizitat și adăugat în coadă cu distanța 0.

---

### 4. **Începerea parcurgerii BFS**

```cpp
while (!q.empty()) {
    QueueNode current = q.front();
    q.pop();
```

* Cât timp mai avem noduri de explorat în coadă, continuăm.

---

### 5. **Explorarea vecinilor nodului curent**

```cpp
for (int neighbor = 0; neighbor < n_vertices; neighbor++) {
    if (graph[current.vertex][neighbor] == 1 && !visited[neighbor]) {
        ...
    }
}
```

* Verificăm **toți vecinii** nodului curent.
* `graph[current.vertex][neighbor] == 1` înseamnă că există o muchie între `current.vertex` și `neighbor`.
* `!visited[neighbor]` – verificăm doar nodurile **nevizitate**.

---

### 6. **Dacă găsim nodul final**

```cpp
if (neighbor == end_vertex) {
    return current.distance + 1;
}
```

* Dacă vecinul este chiar nodul căutat (`end_vertex`), returnăm distanța + 1 (pentru muchia curentă).
* Fiind BFS, acesta este garantat cel mai scurt drum.

---

### 7. **Altfel, adăugăm vecinul în coadă**

```cpp
visited[neighbor] = true;
q.push({neighbor, current.distance + 1});
```

* Îl marcăm ca vizitat și îl adăugăm în coadă cu distanța incrementată.

---

### 8. **Dacă am epuizat toate opțiunile**

```cpp
return -1;
```

* Dacă ieșim din `while` fără să găsim nodul final, nu există nicio cale între `start_vertex` și `end_vertex`.

---

## ✅ Rezumat logică:

| Pas | Descriere                                                |
| --- | -------------------------------------------------------- |
| 1   | Inițializează coada cu nodul de start și distanța 0      |
| 2   | Cât timp coada nu e goală, scoate nodul din față         |
| 3   | Verifică fiecare vecin nevizitat                         |
| 4   | Dacă vecinul este destinația, returnează distanța        |
| 5   | Altfel, adaugă vecinul în coadă cu distanța incrementată |
| 6   | Dacă nu găsește destinația, returnează -1                |

---

Dacă vrei și reconstrucția drumului, adică să știi **prin ce noduri ai trecut**, trebuie să adaugi un vector `parent[]`. Vrei să-ți arăt și varianta cu traseu complet?
