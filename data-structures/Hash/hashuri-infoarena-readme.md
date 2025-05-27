# Explicația detaliată a programului Hash Set în C

## Header-uri și constante

```c
#include <stdio.h>
#include <stdlib.h>
```
- `stdio.h` - pentru funcțiile de input/output (printf, scanf, fopen, etc.)
- `stdlib.h` - pentru funcțiile de alocare/eliberare memorie (malloc, free)

```c
#define MOD 700001
```
- Definește constanta MOD cu valoarea 700001 (număr prim)
- Această constantă reprezintă dimensiunea tabelei de hash
- Numerele prime sunt preferate pentru funcțiile de hash pentru a reduce coliziunile

## Definirea structurii Node

```c
typedef struct Node {
    long long value;
    struct Node *next;
} Node;
```
- Definește structura pentru nodurile din listele înlănțuite
- `value` - stochează valoarea efectivă a elementului
- `next` - pointer către următorul nod din listă
- `typedef` permite folosirea `Node` în loc de `struct Node`
- `long long` este folosit pentru a suporta valori până la 2 miliarde

## Tabela de hash globală

```c
Node *ListNode[MOD];
```
- Declară o tabelă de hash cu MOD (700001) poziții
- Fiecare poziție este un pointer către primul nod dintr-o listă înlănțuită
- Inițial toate pointer-ii sunt nedefiniti (vor fi setați la NULL)

## Funcția de hash

```c
long long hashValue(long long value) {
    return value % MOD;
}
```
- Implementează o funcție de hash simplă folosind operația modulo
- Primește o valoare și returnează indicele în tabela de hash (0 la MOD-1)
- Exemple: hashValue(5) = 5, hashValue(700002) = 1

## Funcția de căutare

```c
long long searchElement(long long value) {
    long long index = hashValue(value);
```
- Calculează indicele în tabela de hash pentru valoarea căutată

```c
    Node *currentHead = ListNode[index];
    while (currentHead != NULL) {
        if (currentHead->value == value) {
            return 1;
        }
        currentHead = currentHead->next;
    }
```
- Pornește de la primul nod din lista de la poziția `index`
- Parcurge lista înlănțuită până la sfârșit
- Dacă găsește valoarea, returnează 1 (găsit)
- Trece la următorul nod cu `currentHead->next`

```c
    return 0;
}
```
- Dacă nu găsește valoarea în toată lista, returnează 0 (nu există)

## Funcția de inserare

```c
void insert(long long value) {
    if (searchElement(value) == 1) {
        return;
    }
```
- Verifică mai întâi dacă elementul există deja
- Dacă există, nu face nimic (mulțimea nu se schimbă)

```c
    long long index = hashValue(value);
    Node *newNode = (Node*)malloc(sizeof(Node));
```
- Calculează indicele pentru noua valoare
- Alocă memorie pentru un nou nod folosind `malloc`
- `sizeof(Node)` dă dimensiunea în bytes a structurii Node

```c
    newNode->value = value;
    newNode->next = ListNode[index];
```
- Setează valoarea nodului nou
- Leagă noul nod de lista existentă (inserare la început)

```c
    ListNode[index] = newNode;
}
```
- Actualizează capul listei să pointeze la noul nod
- Noul nod devine primul element din listă

## Funcția de ștergere

```c
void deleteElement(long long value) {
    long long indexHash = hashValue(value);
```
- Calculează indicele pentru valoarea de șters

```c
    Node *currentHead = ListNode[indexHash];
    Node *prevNode = NULL;
```
- `currentHead` - pointer la nodul curent
- `prevNode` - pointer la nodul anterior (pentru a putea face legătura)

```c
    long long index = 0, foundAt = -1;
    while (currentHead != NULL) {
        if (currentHead->value == value) {
            foundAt = index;
            break;
        }
        ++index;
        prevNode = currentHead;
        currentHead = currentHead->next;
    }
```
- Parcurge lista și caută elementul
- Ține evidența poziției (`index`) și nodului anterior (`prevNode`)
- Când găsește elementul, salvează poziția în `foundAt` și iese din buclă

```c
    if (foundAt == -1) {
        return;
    }
```
- Dacă nu a găsit elementul (`foundAt` rămâne -1), nu face nimic

```c
    if (prevNode == NULL) {
        ListNode[indexHash] = currentHead->next;
    } else {
        prevNode->next = currentHead->next;
    }
```
- Dacă elementul de șters este primul din listă (`prevNode == NULL`):
  - Actualizează capul listei să pointeze la al doilea element
- Altfel:
  - Leagă nodul anterior direct de nodul următor (ocolește nodul curent)

```c
    free(currentHead);
}
```
- Eliberează memoria ocupată de nodul șters

## Funcția principală

```c
int main() {
    FILE *fin = fopen("hashuri.in", "r");
    FILE *fout = fopen("hashuri.out", "w");
```
- Deschide fișierele de intrare și ieșire
- "r" = read mode, "w" = write mode

```c
    if (fin == NULL || fout == NULL) {
        printf("Eroare la deschiderea fisierelor!\n");
        return 1;
    }
```
- Verifică dacă fișierele s-au deschis cu succes
- Dacă nu, afișează o eroare și iese din program

```c
    long long n;
    fscanf(fin, "%lld", &n);
```
- Citește numărul de operații din fișier
- `%lld` este formatul pentru `long long`

```c
    for (long long i = 0; i < MOD; ++i) {
        ListNode[i] = NULL;
    }
```
- Inițializează toate pozițiile din tabela de hash cu NULL
- Aceasta înseamnă că inițial toate listele sunt goale

```c
    for (long long i = 0; i < n; ++i) {
        long long type;
        long long value;
        fscanf(fin, "%lld %lld", &type, &value);
```
- Parcurge toate operațiile
- Citește tipul operației și valoarea pentru fiecare operație

```c
        if (type == 1) {
            insert(value);
        } else if (type == 2) {
            deleteElement(value);
        } else if (type == 3) {
            fprintf(fout, "%lld\n", searchElement(value));
        }
    }
```
- Execută operația corespunzătoare:
  - Tip 1: inserează elementul
  - Tip 2: șterge elementul  
  - Tip 3: caută elementul și scrie rezultatul în fișierul de ieșire

```c
    fclose(fin);
    fclose(fout);
    return 0;
}
```
- Închide fișierele
- Returnează 0 (succes)

## Principiul de funcționare

1. **Hash Table cu Chaining**: Folosește o tabelă cu 700001 poziții, fiecare conținând o listă înlănțuită
2. **Funcția de hash**: `value % 700001` mapează valorile la indici
3. **Gestionarea coliziunilor**: Elementele cu același hash sunt stocate în aceeași listă
4. **Complexitate medie**: O(1) pentru toate operațiile, O(n) în cel mai rău caz
