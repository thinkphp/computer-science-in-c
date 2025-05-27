# Binary Search Tree (BST) Implementation in C

## Descriere

Acest proiect implementează un Binary Search Tree (Arbore Binar de Căutare) în limbajul C, oferind toate operațiile fundamentale necesare pentru manipularea și parcurgerea structurii de date.

Un Binary Search Tree este o structură de date arborescente în care fiecare nod are cel mult doi copii, denumiți copilul stâng și copilul drept. Pentru fiecare nod din arbore, toate valorile din subarborele stâng sunt mai mici decât valoarea nodului, iar toate valorile din subarborele drept sunt mai mari.

## Structura Nodului

```c
typedef struct Node {
    int data;           // Valoarea stocată în nod
    struct Node* left;  // Pointer către copilul stâng
    struct Node* right; // Pointer către copilul drept
} Node;
```

## Operații Implementate

### 1. Inserare (Insert)

**Funcția:** `Node* insert(Node* root, int value)`

**Descriere:** Inserează o nouă valoare în BST respectând proprietatea de ordine.

**Algoritmul:**
- Dacă arborele este gol, creează un nod nou ca rădăcină
- Dacă valoarea este mai mică decât nodul curent, inserează în subarborele stâng
- Dacă valoarea este mai mare decât nodul curent, inserează în subarborele drept
- Dacă valoarea există deja, nu o inserează din nou (evită duplicatele)

**Complexitatea:** O(log n) în cazul mediu, O(n) în cel mai rău caz (arbore degenerat)

### 2. Căutare (Search)

**Funcția:** `Node* search(Node* root, int value)`

**Descriere:** Caută o valoare specifică în BST și returnează nodul care o conține.

**Algoritmul:**
- Dacă nodul curent este NULL sau conține valoarea căutată, returnează nodul
- Dacă valoarea căutată este mai mică, caută în subarborele stâng
- Dacă valoarea căutată este mai mare, caută în subarborele drept

**Complexitatea:** O(log n) în cazul mediu, O(n) în cel mai rău caz

**Valoarea returnată:** Pointer către nodul găsit sau NULL dacă valoarea nu există

### 3. Ștergere (Delete)

**Funcția:** `Node* delete(Node* root, int value)`

**Descriere:** Șterge un nod cu o anumită valoare din BST, menținând proprietatea de ordine.

**Algoritmul tratează 3 cazuri:**

#### Cazul 1: Nodul nu are copii (nod frunză)
- Se șterge direct nodul și se returnează NULL

#### Cazul 2: Nodul are un singur copil
- Se înlocuiește nodul cu copilul său
- Se eliberează memoria nodului șters

#### Cazul 3: Nodul are doi copii
- Se găsește succesorul inorder (cel mai mic nod din subarborele drept)
- Se copiază valoarea succesorului în nodul de șters
- Se șterge succesorul din subarborele drept

**Complexitatea:** O(log n) în cazul mediu, O(n) în cel mai rău caz

### 4. Parcurgere Inordine (Inorder Traversal)

**Funcția:** `void inorderTraversal(Node* root)`

**Descriere:** Parcurge arborele în ordinea: stânga → rădăcină → dreapta

**Caracteristici:**
- Pentru un BST, parcurgerea inordine produce valorile în ordine crescătoare
- Folosește recursivitatea pentru parcurgere
- Utilă pentru sortarea datelor din BST

**Complexitatea:** O(n) - vizitează fiecare nod o singură dată

**Exemplu:** Pentru BST-ul cu valorile [50, 30, 70, 20, 40, 60, 80], inorder produce: 20, 30, 40, 50, 60, 70, 80

### 5. Parcurgere Preordine (Preorder Traversal)

**Funcția:** `void preorderTraversal(Node* root)`

**Descriere:** Parcurge arborele în ordinea: rădăcină → stânga → dreapta

**Caracteristici:**
- Vizitează mai întâi rădăcina, apoi subarborii
- Utilă pentru copierea arborelui sau pentru evaluarea expresiilor
- Prima valoare afișată este întotdeauna rădăcina

**Complexitatea:** O(n)

**Exemplu:** Pentru același BST, preorder produce: 50, 30, 20, 40, 70, 60, 80

### 6. Parcurgere Postordine (Postorder Traversal)

**Funcția:** `void postorderTraversal(Node* root)`

**Descriere:** Parcurge arborele în ordinea: stânga → dreapta → rădăcină

**Caracteristici:**
- Vizitează rădăcina la final, după subarborii
- Utilă pentru ștergerea arborelui sau pentru calculul dimensiunii
- Ultima valoare afișată este întotdeauna rădăcina

**Complexitatea:** O(n)

**Exemplu:** Pentru același BST, postorder produce: 20, 40, 30, 60, 80, 70, 50

## Funcții Auxiliare

### createNode()
Creează un nod nou cu valoarea specificată și inițializează pointerii la NULL.

### findMin()
Găsește nodul cu valoarea minimă într-un subarbore (cel mai din stânga nod).

### freeTree()
Eliberează memoria ocupată de întreg arborele folosind parcurgerea postordine.

## Compilare și Rulare

```bash
gcc bst.c -o bst
./bst
```

## Exemplu de Utilizare

Programul demonstrează toate operațiile implementate:

1. **Inserare:** Se inserează valorile 50, 30, 70, 20, 40, 60, 80
2. **Parcurgeri:** Se afișează toate cele trei tipuri de parcurgere
3. **Căutare:** Se caută valorile 40 (există), 25 (nu există), 80 (există)
4. **Ștergere:** Se demonstrează ștergerea pentru toate cele 3 cazuri

## Complexități Temporale

| Operație | Cazul Mediu | Cazul Rău |
|----------|-------------|-----------|
| Inserare | O(log n)    | O(n)      |
| Căutare  | O(log n)    | O(n)      |
| Ștergere | O(log n)    | O(n)      |
| Parcurgere | O(n)      | O(n)      |

## Complexitatea Spațială

- **Spațiu:** O(n) pentru stocarea nodurilor
- **Spațiu auxiliar:** O(h) pentru stiva de recursivitate, unde h este înălțimea arborelui

## Avantaje ale BST

1. **Căutare eficientă:** Timpul de căutare este logaritmic în cazul unui arbore echilibrat
2. **Inserare și ștergere dinamice:** Operațiile sunt eficiente comparativ cu alte structuri
3. **Parcurgere ordonată:** Inorder traversal produce valorile sortate
4. **Flexibilitate:** Suportă operații de range query și găsirea succesorului/predecesorului

## Dezavantaje

1. **Degenerare:** În cel mai rău caz, BST-ul poate deveni o listă înlănțuită
2. **Fără auto-echilibrare:** Această implementare nu menține echilibrul automat
3. **Performanța depinde de ordinea inserării:** Datele sortate pot crea un arbore degenerat

## Îmbunătățiri Posibile

1. **Auto-echilibrare:** Implementarea unui AVL Tree sau Red-Black Tree
2. **Operații suplimentare:** Găsirea succesorului, predecesorului, rang-ul unui element
3. **Suport pentru duplicate:** Modificarea pentru a permite valori duplicate
4. **Iteratori:** Implementarea de iteratori pentru parcurgere non-recursivă
