# Explicația detaliată a codului AVL Tree

## 1. Includerea bibliotecilor și definirea structurii

```c
#include <stdio.h>
#include <stdlib.h>
```
- `stdio.h` - pentru funcții de input/output (printf, scanf)
- `stdlib.h` - pentru alocarea dinamică de memorie (malloc, free)

```c
typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;
```
- Definește structura unui nod AVL
- `data` - valoarea stocată în nod
- `left` - pointer către copilul stâng
- `right` - pointer către copilul drept
- `height` - înălțimea nodului (necesară pentru AVL)

## 2. Funcția de creare a unui nod nou

```c
AVLNode* createNode(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
```
- Alocă memorie pentru un nou nod AVL

```c
    if (!node) {
        printf("Eroare: Nu s-a putut aloca memoria!\n");
        return NULL;
    }
```
- Verifică dacă alocarea a reușit; dacă nu, afișează eroare și returnează NULL

```c
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // Nodul nou este frunză
    return node;
```
- Inițializează noul nod cu datele primite
- Copiii sunt NULL (frunză)
- Înălțimea este 1 (frunzele au înălțimea 1)

## 3. Funcții auxiliare pentru AVL

```c
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}
```
- Returnează înălțimea nodului
- Dacă nodul este NULL, înălțimea este 0

```c
int getBalance(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}
```
- Calculează factorul de echilibru: înălțime_stânga - înălțime_dreapta
- Pentru AVL, acest factor trebuie să fie între -1 și 1

```c
void updateHeight(AVLNode* node) {
    if (node) {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}
```
- Actualizează înălțimea nodului
- Înălțimea = max(înălțime_stânga, înălțime_dreapta) + 1

## 4. Rotații AVL

### Rotația la dreapta (pentru cazul LL)

```c
AVLNode* rotateRight(AVLNode* y) {
    printf("Efectuez rotația dreapta la nodul %d\n", y->data);
    
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
```
- `y` este nodul neechilibrat
- `x` este copilul stâng al lui `y`
- `T2` este subarborele drept al lui `x`

```c
    // Efectuez rotația
    x->right = y;
    y->left = T2;
```
- `x` devine noua rădăcină
- `y` devine copilul drept al lui `x`
- `T2` devine copilul stâng al lui `y`

```c
    // Actualizez înălțimile
    updateHeight(y);
    updateHeight(x);
    
    return x; // Noua rădăcină
```
- Actualizează înălțimile (mai întâi `y`, apoi `x`)
- Returnează noua rădăcină (`x`)

### Rotația la stânga (pentru cazul RR)

```c
AVLNode* rotateLeft(AVLNode* x) {
    printf("Efectuez rotația stânga la nodul %d\n", x->data);
    
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    // Efectuez rotația
    y->left = x;
    x->right = T2;
    
    // Actualizez înălțimile
    updateHeight(x);
    updateHeight(y);
    
    return y; // Noua rădăcină
}
```
- Similar cu rotația dreapta, dar în sens invers
- `y` (copilul drept) devine noua rădăcină
- `x` devine copilul stâng al lui `y`

## 5. Funcția de inserare AVL

```c
AVLNode* insert(AVLNode* node, int data) {
    // Pas 1: Inserare BST normală
    if (!node) {
        printf("Inserez %d ca nod nou\n", data);
        return createNode(data);
    }
```
- Dacă nodul este NULL, creează un nod nou (cazul de bază)

```c
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        // Valoarea există deja
        printf("Valoarea %d există deja în arbore\n", data);
        return node;
    }
```
- Inserare BST standard: stânga dacă mai mic, dreapta dacă mai mare
- Dacă valoarea există, nu face nimic

```c
    // Pas 2: Actualizez înălțimea nodului curent
    updateHeight(node);
    
    // Pas 3: Obțin factorul de echilibru
    int balance = getBalance(node);
    printf("Nodul %d: înălțime=%d, factor echilibru=%d\n", 
           node->data, node->height, balance);
```
- Actualizează înălțimea după inserare
- Calculează factorul de echilibru pentru a verifica dacă e necesar reechilibrarea

### Cele 4 cazuri de neechilibru:

```c
    // Cazul LL (Left Left)
    if (balance > 1 && data < node->left->data) {
        printf("Caz LL detectat la nodul %d\n", node->data);
        return rotateRight(node);
    }
```
- Factor > 1 și inserarea în subarborele stâng al copilului stâng
- Se rezolvă cu rotație dreapta

```c
    // Cazul RR (Right Right)
    if (balance < -1 && data > node->right->data) {
        printf("Caz RR detectat la nodul %d\n", node->data);
        return rotateLeft(node);
    }
```
- Factor < -1 și inserarea în subarborele drept al copilului drept
- Se rezolvă cu rotație stânga

```c
    // Cazul LR (Left Right)
    if (balance > 1 && data > node->left->data) {
        printf("Caz LR detectat la nodul %d\n", node->data);
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
```
- Factor > 1 și inserarea în subarborele drept al copilului stâng
- Se rezolvă cu rotație stânga urmată de rotație dreapta

```c
    // Cazul RL (Right Left)
    if (balance < -1 && data < node->right->data) {
        printf("Caz RL detectat la nodul %d\n", node->data);
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
```
- Factor < -1 și inserarea în subarborele stâng al copilului drept
- Se rezolvă cu rotație dreapta urmată de rotație stânga

## 6. Funcții de parcurgere

```c
void inorderTraversal(AVLNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
```
- Parcurgere în inordine: stânga → rădăcină → dreapta
- Pentru BST, afișează valorile în ordine crescătoare

```c
void preorderTraversal(AVLNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
```
- Parcurgere în preordine: rădăcină → stânga → dreapta
- Utilă pentru reconstructia arborelui

```c
void postorderTraversal(AVLNode* root) {
    if (root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
```
- Parcurgere în postordine: stânga → dreapta → rădăcină
- Utilă pentru ștergerea sigură a arborelui

## 7. Gestionarea memoriei

```c
void freeTree(AVLNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
```
- Eliberează recursiv memoria pentru întreg arborele
- Folosește parcurgerea postordine pentru siguranță

## 8. Interfața utilizator

```c
void printMenu() {
    printf("\n=== AVL Tree - Inserare și Parcurgeri ===\n");
    printf("1. Inserare număr\n");
    printf("2. Parcurgere în inordine\n");
    printf("3. Parcurgere în preordine\n");
    printf("4. Parcurgere în postordine\n");
    printf("5. Toate parcurgerile\n");
    printf("6. Demo (inserare secvență)\n");
    printf("0. Ieșire\n");
    printf("Alegerea ta: ");
}
```
- Afișează meniul interactiv cu opțiunile disponibile

## 9. Funcția main

```c
int main() {
    AVLNode* root = NULL;
    int choice, value;
    
    printf("=== AVL Tree - Implementare pentru Inserare și Parcurgeri ===\n");
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
```
- Inițializează rădăcina ca NULL
- Bucla infinită pentru meniul interactiv

### Switch pentru opțiuni:

**Cazul 1 - Inserare:**
```c
case 1:
    printf("Introdu numărul de inserat: ");
    scanf("%d", &value);
    printf("\n=== INSERARE %d ===\n", value);
    root = insert(root, value);
    printf("Operația completă!\n");
    break;
```

**Cazurile 2-4 - Parcurgeri:**
```c
case 2:
    printf("\n=== PARCURGERE INORDINE ===\n");
    if (root) {
        printf("Inordine (stânga-rădăcină-dreapta): ");
        inorderTraversal(root);
        printf("\n");
    } else {
        printf("Arborele este gol\n");
    }
    break;
```

**Cazul 6 - Demo:**
```c
case 6:
    printf("\n=== DEMO - Inserare secvența 10,20,30,40,50,25 ===\n");
    int demo[] = {10, 20, 30, 40, 50, 25};
    int demo_size = sizeof(demo) / sizeof(demo[0]);
    
    for (int i = 0; i < demo_size; i++) {
        printf("\n--- Inserez %d ---\n", demo[i]);
        root = insert(root, demo[i]);
    }
```
- Inserează o secvență predefinită pentru demonstrație

**Cazul 0 - Ieșire:**
```c
case 0:
    printf("Eliberez memoria și ies...\n");
    freeTree(root);
    exit(0);
```
- Eliberează memoria și închide programul

## Caracteristici importante AVL:

1. **Autoechilibrare**: După fiecare inserare, arborele se reechilibrează automat
2. **Factor de echilibru**: Diferența dintre înălțimile subarborilor stâng și drept (-1, 0, 1)
3. **Rotații**: Mecanismul de reechilibrare prin rotații simple și duble
4. **Complexitate**: O(log n) pentru inserare, căutare și ștergere
5. **Invariant**: Toate nodurile respectă proprietatea BST și factorul de echilibru AVL
