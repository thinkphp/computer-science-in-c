**Algoritmul lui Mo (Mo's Algorithm)**
Este un algoritm eficient pentru procesarea întrebărilor offline asupra unui array. Este util în special pentru query-uri de tip range (interval) când avem multe întrebări și vrem să procesăm toate răspunsurile eficient.

Principalele caracteristici:
1. Funcționează doar pentru query-uri offline (toate întrebările sunt cunoscute dinainte)
2. Complexitatea este O((N+Q)√N * complexity_of_add_remove), unde N e lungimea array-ului și Q numărul de query-uri
3. Se bazează pe sortarea specială a query-urilor pentru a minimiza modificările între răspunsuri consecutive

Pașii algoritmului:
1. Se împarte array-ul în blocuri de dimensiune aproximativ √N
2. Se sortează query-urile după următoarele criterii:
   - Primary: blocul în care se află capătul stâng al intervalului
   - Secondary: poziția capătului drept al intervalului 
3. Se procesează query-urile în ordinea sortată, menținând o "fereastră" curentă
4. Se modifică fereastra prin adăugări/eliminări de elemente pentru a ajunge la intervalul cerut

Să vedem un exemplu practic pentru următoarea problemă:

"Dat un array și Q întrebări de forma [L, R], pentru fiecare întrebare aflați numărul de valori distincte din intervalul [L, R]."



```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int BLOCK = 320; // aproximativ sqrt(N)

struct Query {
    int l, r, idx;
    bool operator<(Query other) const {
        if (l/BLOCK != other.l/BLOCK)
            return l/BLOCK < other.l/BLOCK;
        return r < other.r;
    }
};

int arr[N];
int freq[N];
int distinct;
vector<Query> queries;
vector<int> answers;

void add(int position) {
    freq[arr[position]]++;
    if (freq[arr[position]] == 1) 
        distinct++;
}

void remove(int position) {
    freq[arr[position]]--;
    if (freq[arr[position]] == 0) 
        distinct--;
}

void mo_s_algorithm(int n, int q) {
    sort(queries.begin(), queries.end());
    
    // Procesăm primul query
    int curr_l = queries[0].l;
    int curr_r = queries[0].r;
    
    // Inițializăm fereastra pentru primul interval
    for(int i = curr_l; i <= curr_r; i++)
        add(i);
        
    answers[queries[0].idx] = distinct;
    
    // Procesăm restul query-urilor
    for(int i = 1; i < q; i++) {
        int l = queries[i].l;
        int r = queries[i].r;
        
        // Eliminăm elementele care nu mai sunt în interval
        while(curr_l < l) {
            remove(curr_l);
            curr_l++;
        }
        // Adăugăm elementele noi din stânga
        while(curr_l > l) {
            curr_l--;
            add(curr_l);
        }
        // Eliminăm elementele care nu mai sunt în interval din dreapta
        while(curr_r > r) {
            remove(curr_r);
            curr_r--;
        }
        // Adăugăm elementele noi din dreapta
        while(curr_r < r) {
            curr_r++;
            add(curr_r);
        }
        
        answers[queries[i].idx] = distinct;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    
    // Citim array-ul
    for(int i = 0; i < n; i++)
        cin >> arr[i];
        
    // Citim query-urile
    queries.resize(q);
    answers.resize(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--; // convertim la 0-based indexing
        queries[i].idx = i;
    }
    
    mo_s_algorithm(n, q);
    
    // Afișăm răspunsurile în ordinea originală
    for(int i = 0; i < q; i++)
        cout << answers[i] << "\n";
        
    return 0;
}

```

Să analizăm cum funcționează acest cod:

1. Pentru fiecare query, menținem:
   - Frecvența fiecărui număr în intervalul curent (array-ul freq[])
   - Numărul total de valori distincte (variabila distinct)

2. Funcțiile add() și remove() actualizează aceste informații când adăugăm sau eliminăm un element din fereastra curentă

3. În mo_s_algorithm():
   - Sortăm query-urile folosind criteriile menționate
   - Procesăm primul query direct
   - Pentru restul query-urilor, modificăm fereastra curentă prin:
     * Ajustarea marginii stângi (l)
     * Ajustarea marginii drepte (r)

4. Complexitatea acestei implementări este O((N+Q)√N), deoarece:
   - Sortarea query-urilor: O(Q log Q)
   - Pentru fiecare query, mutăm marginile cu maxim O(N) poziții
   - În total, suma tuturor mișcărilor este O((N+Q)√N)

Pentru a testa codul, puteți folosi următorul input:
```
5 3
1 2 1 3 2
1 3
2 4
1 5
```

Acest input reprezintă:
- Un array de 5 elemente: [1, 2, 1, 3, 2]
- 3 query-uri: [1,3], [2,4], [1,5]

Output-ul va fi:
```
2
3
3
```
### Practice
- https://www.infoarena.ro/problema/suma6
- https://www.pbinfo.ro/probleme/eticheta/354/algoritmul-lui-mo

### References
- https://codeforces.com/blog/entry/81716
- https://www.hackerearth.com/practice/notes/mos-algorithm/
- https://www.hackerrank.com/topics/mos-algorithm


