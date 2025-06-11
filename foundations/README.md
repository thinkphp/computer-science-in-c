## Algorithm Design Techniques


#### What is computer programming?

Computer programming is the process of writing instructions that are to be executed by computers. These written instructions are often called “code,” as they are written in one of several special programming languages which the computer can understand. Those who can write instructions in one of these codes are called coders, or programmers.  

A programmer’s tasks include understanding project requirements, determining the right programming language to use, designing the solution, coding it, testing and debugging the code, and finally writing documentation that allows their solution to be easily understood by other programmers.

Computer programming is at the heart of computer science and is the implementation portion of software development, application development, and software engineering efforts. It transforms ideas and theories into working solutions.

Basic computer programming involves analyzing a problem and developing a logical sequence of instructions to solve it. There can be numerous paths to a solution, but some are much faster than others. That is why the computer programmer seeks to design the most efficient code.


1. [Introducere în Tehnicile de Programare](#introducere)
2. [Backtracking - Explorarea cu Revenire](#backtracking)
3. [Divide et Impera - Divide și Stăpânește](#divide-et-impera)
4. [Greedy - Tehnica Lacomă](#greedy)
5. [Analiza Comparativă și Aplicații](#analiza-comparativa)
6. [Studii de Caz și Implementări](#studii-de-caz)

---

## 1. Introducere în Tehnicile de Programare {#introducere}

### 1.1 Context și Motivație

Tehnicile de programare reprezintă paradigme fundamentale în informatică pentru rezolvarea problemelor computaționale complexe. Acestea oferă cadre conceptuale și metodologice pentru abordarea sistematică a problemelor algoritmice, permitând dezvoltarea de soluții eficiente și elegante.

### 1.2 Clasificarea Tehnicilor Algoritmice

**Tehnici Complete vs. Aproximative:**
- **Complete**: Garantează găsirea soluției optime (Backtracking, Divide et Impera)
- **Aproximative**: Oferă soluții rapide, nu neapărat optime (Greedy în unele cazuri)

**Strategii de Explorare:**
- **Exhaustivă**: Explorează tot spațiul soluțiilor (Backtracking)
- **Diviziune**: Împarte problema în subprobleme (Divide et Impera)
- **Locală**: Face alegeri locale optime (Greedy)

### 1.3 Criterii de Evaluare

- **Corectitudine**: Algoritmul produce soluția corectă
- **Complexitate temporală**: Timpul de execuție în funcție de dimensiunea inputului
- **Complexitate spațială**: Memoria necesară pentru execuție
- **Optimalitate**: Capacitatea de a găsi soluția optimă
- **Implementabilitate**: Ușurința de implementare și debugging

---

## 2. Backtracking - Explorarea cu Revenire {#backtracking}

### 2.1 Fundamente Teoretice

Backtracking este o tehnică algoritmică care explorează sistematic spațiul soluțiilor prin construirea incrementală a soluțiilor candidate și abandonarea ("backtrack") acelor candidate care nu pot fi completate la o soluție validă.

**Principii Fundamentale:**
- **Explorare sistematică**: Toate soluțiile posibile sunt considerate
- **Construcție incrementală**: Soluția se construiește element cu element
- **Pruning**: Eliminarea timpurie a căilor care nu duc la soluții valide
- **Recursivitate**: Implementare naturală prin apeluri recursive

### 2.2 Cadrul Formal al Backtracking

**Spațiul Soluțiilor:**
Fie S = {s₁, s₂, ..., sₙ} mulțimea tuturor soluțiilor posibile pentru o problemă dată. Backtracking explorează acest spațiu prin construirea unui arbore de soluții parțiale.

**Schema Generală Formală:**
```
ALGORITM Backtrack(k)
INTRARE: k - nivelul curent în arborele de soluții
IEȘIRE: toate soluțiile valide

ÎNCEPE
    pentru fiecare valoare v din Domeniu(k) execută
        dacă Promițător(k, v) atunci
            x[k] ← v
            dacă k = n atunci
                ProcesareSoluție(x)
            altfel
                Backtrack(k + 1)
            sfârșit dacă
        sfârșit dacă
    sfârșit pentru
SFÂRȘIT
```

### 2.3 Componente Esențiale

**1. Reprezentarea Soluției:**
- Vector de soluție x[1..n]
- Fiecare poziție reprezentă o decizie
- Domeniul valorilor pentru fiecare poziție

**2. Funcția de Promisiune:**
```
function Promițător(k, v):
    // Verifică dacă alegerea v la nivelul k poate duce la o soluție validă
    return verifică_constrângeri_locale(k, v) AND 
           verifică_constrângeri_globale(k, v)
```

**3. Condiția de Terminare:**
```
function SoluțieCompletă(k):
    return k == dimensiunea_problemei
```

### 2.4 Tehnici de Optimizare

**2.4.1 Pruning (Tăierea Ramurilor)**
- **Forward Checking**: Verificarea constrângerilor înainte de extindere
- **Arc Consistency**: Menținerea consistenței între variabile
- **Bound and Branch**: Folosirea limitelor pentru eliminarea căilor

**2.4.2 Ordering Heuristics**
- **Most Constrained Variable**: Alegerea variabilei cu cele mai puține valori posibile
- **Most Constraining Variable**: Alegerea variabilei care constrainge cel mai mult pe altele
- **Least Constraining Value**: Alegerea valorii care elimină cele mai puține opțiuni

### 2.5 Exemple Detaliate

**2.5.1 Problema celor N Dame**

**Formularea Problemei:**
Să se plaseze N dame pe o tablă de șah N×N astfel încât să nu se atace reciproc.

**Reprezentarea:**
- x[i] = coloana damei de pe linia i
- Constrângeri: nu există două dame pe aceeași coloană, diagonală

**Implementare Detaliată:**
```cpp
class NDame {
private:
    vector<int> solutie;
    int n;
    int numarSolutii;
    
    bool esteSigur(int linia, int coloana) {
        for (int i = 0; i < linia; i++) {
            // Verifică coloana și diagonalele
            if (solutie[i] == coloana || 
                abs(solutie[i] - coloana) == abs(i - linia)) {
                return false;
            }
        }
        return true;
    }
    
    void backtrack(int linia) {
        if (linia == n) {
            // Soluție găsită
            afiseazaSolutie();
            numarSolutii++;
            return;
        }
        
        for (int coloana = 0; coloana < n; coloana++) {
            if (esteSigur(linia, coloana)) {
                solutie[linia] = coloana;
                backtrack(linia + 1);
                // Backtrack implicit prin revenirea din recursie
            }
        }
    }
    
public:
    void rezolva(int dimensiune) {
        n = dimensiune;
        solutie.resize(n);
        numarSolutii = 0;
        backtrack(0);
    }
};
```

**Analiza Complexității:**
- **Timp**: O(N!) în cazul cel mai rău, îmbunătățit prin pruning
- **Spațiu**: O(N) pentru stiva de recursie

**2.5.2 Sudoku**

**Formularea Problemei:**
Completarea unei grile 9×9 cu cifre 1-9 respectând constrângerile Sudoku.

**Strategii de Optimizare:**
- **Most Constrained Variable**: Alegerea celulei cu cele mai puține valori posibile
- **Preprocessing**: Calcularea valorilor posibile pentru fiecare celulă goală

### 2.6 Analiza Teoretică

**Complexitate Temporală:**
- **Cazul cel mai rău**: O(b^d) unde b = factorul de ramificare, d = adâncimea
- **Cazul mediu**: Depinde de eficiența pruning-ului
- **Cazul cel mai bun**: O(d) când prima cale explorată este soluția

**Complexitate Spațială:**
- **Stiva de recursie**: O(d)
- **Spațiul soluției**: O(d)
- **Total**: O(d)

---

## 3. Divide et Impera - Divide și Stăpânește {#divide-et-impera}

### 3.1 Fundamente Teoretice

Divide et Impera este o paradigmă algoritmică care rezolvă problemele prin împărțirea lor în subprobleme mai mici de același tip, rezolvarea independentă a acestora, și combinarea rezultatelor.

**Principii Fundamentale:**
- **Divizibilitate**: Problema poate fi împărțită în subprobleme similare
- **Independența subproblemelor**: Subproblemele pot fi rezolvate independent
- **Combinabilitatea**: Rezultatele pot fi combinate eficient

### 3.2 Cadrul Formal

**Schema Generală Matematică:**
```
T(n) = aT(n/b) + f(n)
```
unde:
- a = numărul de subprobleme
- n/b = dimensiunea fiecărei subprobleme
- f(n) = costul diviziunii și combinării

**Implementarea Generică:**
```cpp
template<typename T>
T divideEtImpera(const Problem& p) {
    if (p.esteProblemaDeBase()) {
        return p.rezolvaDirect();
    }
    
    vector<Problem> subprobleme = p.divide();
    vector<T> solutiiPartiale;
    
    for (const auto& sub : subprobleme) {
        solutiiPartiale.push_back(divideEtImpera<T>(sub));
    }
    
    return p.combina(solutiiPartiale);
}
```

### 3.3 Analiza Complexității - Teorema Master

**Teorema Master (forma simplificată):**
Pentru relația T(n) = aT(n/b) + f(n):

1. **Dacă f(n) = O(n^c) cu c < log_b(a):**
   T(n) = Θ(n^(log_b(a)))

2. **Dacă f(n) = Θ(n^c) cu c = log_b(a):**
   T(n) = Θ(n^c * log n)

3. **Dacă f(n) = Ω(n^c) cu c > log_b(a) și af(n/b) ≤ kf(n):**
   T(n) = Θ(f(n))

### 3.4 Exemple Detaliate

**3.4.1 Merge Sort - Sortarea prin Interclasare**

**Algoritm Detaliat:**
```cpp
class MergeSort {
private:
    void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArr(n1), rightArr(n2);
        
        // Copierea datelor în arrayurile temporare
        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        
        // Interclasarea
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        // Copierea elementelor rămase
        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            // Diviziune
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            
            // Combinare
            merge(arr, left, mid, right);
        }
    }
    
public:
    void sort(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
    }
};
```

**Analiza Detaliată:**
- **Relația de recurență**: T(n) = 2T(n/2) + O(n)
- **Aplicând Teorema Master**: a=2, b=2, f(n)=O(n), c=1
- **log_b(a) = log₂(2) = 1 = c**
- **Rezultat**: T(n) = Θ(n log n)

**3.4.2 Quick Sort - Sortarea Rapidă**

**Implementare Optimizată:**
```cpp
class QuickSort {
private:
    int partition(vector<int>& arr, int low, int high) {
        // Alegerea pivotului (median-of-three)
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[low]) swap(arr[low], arr[mid]);
        if (arr[high] < arr[low]) swap(arr[low], arr[high]);
        if (arr[high] < arr[mid]) swap(arr[mid], arr[high]);
        swap(arr[mid], arr[high]);
        
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
public:
    void sort(vector<int>& arr) {
        quickSort(arr, 0, arr.size() - 1);
    }
};
```

**Analiza Complexității:**
- **Cazul cel mai bun/mediu**: T(n) = 2T(n/2) + O(n) = O(n log n)
- **Cazul cel mai rău**: T(n) = T(n-1) + O(n) = O(n²)
- **Optimizări**: Median-of-three, tail recursion optimization

**3.4.3 Înmulțirea Rapidă (Algoritmul lui Karatsuba)**

**Problema**: Înmulțirea a două numere mari de n cifre.

**Abordarea Clasică**: O(n²) operații
**Abordarea Karatsuba**: O(n^(log₂3)) ≈ O(n^1.585)

**Algoritm:**
Pentru numerele X = a*10^(n/2) + b și Y = c*10^(n/2) + d:
- X*Y = ac*10^n + ((a+b)(c+d) - ac - bd)*10^(n/2) + bd
- Necesită doar 3 înmulțiri în loc de 4

### 3.5 Variante și Extensii

**3.5.1 Divide et Impera cu Memorization**
Combinarea cu programarea dinamică pentru subprobleme care se repetă.

**3.5.2 Paralelizarea**
Divide et Impera se pretează natural la paralelizare:
```cpp
// Pseudocod pentru versiunea paralelă
T divideEtImperaParalel(Problem p) {
    if (p.esteProblemaDeBase()) {
        return p.rezolvaDirect();
    }
    
    auto subprobleme = p.divide();
    
    // Execuție paralelă
    auto future1 = async(launch::async, divideEtImperaParalel, subprobleme[0]);
    auto future2 = async(launch::async, divideEtImperaParalel, subprobleme[1]);
    
    return p.combina({future1.get(), future2.get()});
}
```

---

## 4. Greedy - Tehnica Lacomă {#greedy}

### 4.1 Fundamente Teoretice

Algoritmii Greedy construiesc soluții prin luarea unei secvențe de alegeri, fiecare alegere fiind cea mai bună disponibilă în momentul respectiv, fără a considera efectele globale.

**Caracteristici Definitorii:**
- **Alegere locală optimă**: Fiecare decizie pare cea mai bună în momentul actual
- **Proprietatea fără revenire**: Deciziile luate nu se schimbă niciodată
- **Construcție incrementală**: Soluția se construiește pas cu pas

### 4.2 Condiții de Optimalitate

Pentru ca un algoritm Greedy să producă soluția optimă globală, problema trebuie să satisfacă:

**4.2.1 Proprietatea Alegerii Greedy**
Există o soluție optimă globală care conține alegerea greedy făcută la primul pas.

**Demonstrație Tipică (prin metoda "exchange argument"):**
1. Presupunem că există o soluție optimă O care nu conține alegerea greedy G
2. Arătăm că putem "schimba" O cu G obținând o soluție cel puțin la fel de bună
3. Prin inducție, demonstrăm că alegerea greedy la fiecare pas este sigură

**4.2.2 Substructura Optimă**
După ce facem alegerea greedy, subproblema rezultată trebuie să aibă proprietatea că soluția sa optimă, combinată cu alegerea greedy, dă soluția optimă a problemei originale.

### 4.3 Cadrul Formal de Analiză

**Schema Generală de Demonstrație:**
```
Teoremă: Algoritmul Greedy A produce soluția optimă pentru problema P.

Demonstrație:
1. Invariant: După k pași, soluția parțială poate fi extinsă la o soluție optimă
2. Alegerea greedy: Demonstrăm că alegerea greedy menține invariantul
3. Substructura optimă: Subproblema rezultată are aceeași proprietate
4. Concluzie: Prin inducție, soluția finală este optimă
```

### 4.4 Tipologii de Probleme Greedy

**4.4.1 Probleme de Programare (Scheduling)**
- Caracteristici: activități cu timp de început și sfârșit
- Funcția greedy: alegerea activității cu timpul de sfârșit cel mai timpuriu

**4.4.2 Probleme de Acoperire Minimă**
- Caracteristici: acoperirea unei mulțimi cu cost minim
- Funcția greedy: alegerea elementului cu cel mai bun raport cost/beneficiu

**4.4.3 Probleme de Drum Minim**
- Caracteristici: găsirea drumului de cost minim în graf
- Funcția greedy: extinderea cu muchia de cost minim

### 4.5 Exemple Detaliate și Demonstrații

**4.5.1 Problema Selecției Activităților**

**Formularea Problemei:**
Dat un set de n activități {a₁, a₂, ..., aₙ}, fiecare cu timpul de început sᵢ și timpul de sfârșit fᵢ, să se selecteze numărul maxim de activități care nu se suprapun.

**Algoritmul Greedy:**
```cpp
class SelectieActivitati {
private:
    struct Activitate {
        int debut, sfarsit, id;
        bool operator<(const Activitate& other) const {
            return sfarsit < other.sfarsit;
        }
    };
    
public:
    vector<int> selecteazaActivitati(vector<pair<int,int>>& activitati) {
        int n = activitati.size();
        vector<Activitate> act(n);
        
        for (int i = 0; i < n; i++) {
            act[i] = {activitati[i].first, activitati[i].second, i};
        }
        
        // Sortarea după timpul de sfârșit
        sort(act.begin(), act.end());
        
        vector<int> solutie;
        solutie.push_back(act[0].id);
        int ultimulSfarsit = act[0].sfarsit;
        
        for (int i = 1; i < n; i++) {
            if (act[i].debut >= ultimulSfarsit) {
                solutie.push_back(act[i].id);
                ultimulSfarsit = act[i].sfarsit;
            }
        }
        
        return solutie;
    }
};
```

**Demonstrația Corectitudinii:**

*Teoremă*: Algoritmul greedy care selectează activitățile în ordinea crescătoare a timpului de sfârșit produce o soluție optimă.

*Demonstrație*:
1. **Proprietatea alegerii greedy**: Să considerăm o soluție optimă O = {a₁, a₂, ..., aₖ} ordonată după timpul de sfârșit. Dacă a₁ nu este activitatea cu cel mai timpuriu sfârșit, o putem înlocui cu aceasta (fie aⱼ) obținând o soluție cel puțin la fel de bună, deoarece f(aⱼ) ≤ f(a₁) ≤ s(a₂).

2. **Substructura optimă**: După alegerea primei activități, problema se reduce la selectarea din activitățile care încep după sfârșitul primei activități alese.

3. **Prin inducție**: Dacă alegerea greedy este sigură pentru primul pas și subproblema are aceeași structură, algoritmul este optim.

**Complexitatea**: O(n log n) pentru sortare + O(n) pentru selecție = O(n log n)

**4.5.2 Algoritmul lui Dijkstra**

**Formularea Problemei:**
Să se găsească drumurile de cost minim de la un nod sursă la toate celelalte noduri într-un graf cu muchii de cost pozitiv.

**Algoritmul Detaliat:**
```cpp
class Dijkstra {
private:
    struct Muchie {
        int dest, cost;
    };
    
    struct Nod {
        int id, distanta;
        bool operator>(const Nod& other) const {
            return distanta > other.distanta;
        }
    };
    
public:
    vector<int> drumMinim(int n, vector<vector<Muchie>>& graf, int sursa) {
        vector<int> dist(n, INT_MAX);
        vector<bool> vizitat(n, false);
        priority_queue<Nod, vector<Nod>, greater<Nod>> pq;
        
        dist[sursa] = 0;
        pq.push({sursa, 0});
        
        while (!pq.empty()) {
            int u = pq.top().id;
            pq.pop();
            
            if (vizitat[u]) continue;
            vizitat[u] = true;
            
            // Relaxarea muchiilor
            for (const auto& muchie : graf[u]) {
                int v = muchie.dest;
                int cost = muchie.cost;
                
                if (!vizitat[v] && dist[u] + cost < dist[v]) {
                    dist[v] = dist[u] + cost;
                    pq.push({v, dist[v]});
                }
            }
        }
        
        return dist;
    }
};
```

**Demonstrația Corectitudinii:**

*Invariant*: La fiecare pas, pentru nodurile din mulțimea S (nodurile procesate), distanțele calculate sunt optime.

*Alegerea greedy*: Nodul cu distanța minimă din afara lui S are într-adevăr distanța optimă calculată corect.

*Demonstrație*: Prin contradicție - dacă ar exista un drum mai scurt către nodul ales, acesta ar trece prin noduri din afara lui S, ceea ce ar contrazice alegerea nodului cu distanța minimă.

**Complexitatea**: O((V + E) log V) cu heap binar, O(V² + E) cu array simplu

**4.5.3 Algoritmul lui Kruskal pentru Arbori de Acoperire Minimă**

**Implementare cu Union-Find Optimizat:**
```cpp
class Kruskal {
private:
    class UnionFind {
        vector<int> parinte, rang;
        
    public:
        UnionFind(int n) : parinte(n), rang(n, 0) {
            iota(parinte.begin(), parinte.end(), 0);
        }
        
        int find(int x) {
            if (parinte[x] != x) {
                parinte[x] = find(parinte[x]); // Compresie de cale
            }
            return parinte[x];
        }
        
        bool unite(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return false;
            
            // Union by rank
            if (rang[px] < rang[py]) {
                parinte[px] = py;
            } else if (rang[px] > rang[py]) {
                parinte[py] = px;
            } else {
                parinte[py] = px;
                rang[px]++;
            }
            return true;
        }
    };
    
    struct Muchie {
        int u, v, cost;
        bool operator<(const Muchie& other) const {
            return cost < other.cost;
        }
    };
    
public:
    vector<Muchie> arborAcoperireMinima(int n, vector<Muchie>& muchii) {
        sort(muchii.begin(), muchii.end());
        
        UnionFind uf(n);
        vector<Muchie> rezultat;
        
        for (const auto& muchie : muchii) {
            if (uf.unite(muchie.u, muchie.v)) {
                rezultat.push_back(muchie);
                if (rezultat.size() == n - 1) break;
            }
        }
        
        return rezultat;
    }
};
```

**Demonstrația Corectitudinii (Teorema Tăieturii):**
Pentru orice tăietură în graf, muchia de cost minim care traversează tăietura aparține unui arbore de acoperire minimă.

### 4.6 Algoritmi Greedy Aproximativi

**4.6.1 Problema Rucsacului Fracționar vs. 0-1**

**Rucsacul Fracționar** (optim cu Greedy):
```cpp
double rucsacFractionar(vector<pair<int,int>>& obiecte, int capacitate) {
    vector<pair<double, int>> raport;
    for (int i = 0; i < obiecte.size(); i++) {
        raport.push_back({(double)obiecte[i].second / obiecte[i].first, i});
    }
    
    sort(raport.rbegin(), raport.rend());
    
    double valoareTotala = 0;
    int greutateRamasa = capacitate;
    
    for (const auto& item : raport) {
        int idx = item.second;
        if (obiecte[idx].first <= greutateRamasa) {
            valoareTotala += obiecte[idx].second;
            greutateRamasa -= obiecte[idx].first;
        } else {
            valoareTotala += (double)greutateRamasa * item.first;
            break;
        }
    }
    
    return valoareTotala;
}
```

**Rucsacul 0-1**: Greedy nu garantează optimalitatea, necesită programare dinamică.

---

## 5. Analiza Comparativă și Aplicații {#analiza-comparativa}

### 5.1 Matricea de Comparație Detaliată

| Criteriu | Backtracking | Divide et Impera | Greedy |
|----------|--------------|------------------|---------|
| **Complexitate Temporală** | O(b^d) - exponențială | O(n log n) - logaritmică | O(n log n) - polinomială |
| **Complexitate Spațială** | O(d) - liniară | O(log n) - logaritmică | O(1) - constantă |
| **Garantia Optimalității** | 100% | 100% | Condiționată |
| **Paralelizabilitate** | Limitată | Excelentă | Limitată |
| **Aplicabilitate** | Probleme de satisfacere | Probleme divizibile | Probleme cu alegeri locale |
| **Dificultatea Implementării** | Medie-Mare | Medie | Mică-Medie |
| **Debugging** | Dificil | Mediu | Ușor |

### 5.2 Criterii de Decizie pentru Alegerea Tehnicii

**5.2.1 Flowchart de Decizie**

```
START
  ↓
Problema necesită soluție optimă garantată?
  ↓ DA                    ↓ NU
Problema se poate         Algoritm
împărți în subprobleme    aproximativ
similare?                 acceptabil?
  ↓ DA        ↓ NU          ↓ DA
Divide et     Toate         Greedy
Impera        soluțiile     (cu validare)
              posibile?
                ↓ DA
              Backtracking
```

**5.2.2 Matrice de Compatibilitate Problemă-Tehnică**

| Tip Problemă | Backtracking | Divide et Impera | Greedy |
|--------------|--------------|------------------|---------|
| Optimizare combinatorială | ★★★ | ★ | ★★ |
| Sortare și căutare | ★
