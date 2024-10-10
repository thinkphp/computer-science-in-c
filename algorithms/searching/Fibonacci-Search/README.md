# Fibonacci Search in C++

## Descriere

Fibonacci Search este un algoritm de căutare care funcționează pe liste sortate, folosind numerele din seria Fibonacci pentru a împărți lista în intervale mai mici. Acest algoritm este similar cu **binary search**, dar utilizează numere Fibonacci pentru a selecta punctele de diviziune ale intervalului de căutare, ceea ce îl poate face mai eficient în anumite cazuri.

## Cum funcționează

1. Se initializează seria Fibonacci până când cel mai mare număr Fibonacci este mai mare sau egal cu dimensiunea listei.
2. Se folosește seria Fibonacci pentru a împărți lista și a găsi elementul căutat.
3. Algoritmul continuă să micșoreze intervalul de căutare până când fie găsește elementul, fie reduce intervalul de căutare la zero.

## Complexitate

- **Timp de execuție**: O(log n)
- **Memorie**: O(1)

## Exemplu de utilizare

### Codul în C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(const vector<int>& arr, int x) {
    int n = arr.size();

    // Initializează numerele Fibonacci
    int fib2 = 0;  // (Fibonacci minus 2)
    int fib1 = 1;  // (Fibonacci minus 1)
    int fibM = fib2 + fib1;  // (Fibonacci M)

    // Găsește cel mai mic număr Fibonacci mai mare sau egal cu dimensiunea listei
    while (fibM < n) {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    // Marca indexul tăiat
    int offset = -1;

    // Caută elementul în listă
    while (fibM > 1) {
        // Verifică dacă fib2 este o locație validă
        int i = min(offset + fib2, n - 1);

        // Dacă x este mai mare decât valoarea la indexul i, taie intervalul din stânga
        if (arr[i] < x) {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        // Dacă x este mai mic, taie intervalul din dreapta
        else if (arr[i] > x) {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        // Dacă elementul este găsit
        else {
            return i;
        }
    }

    // Compară ultimul element
    if (fib1 && arr[offset + 1] == x) {
        return offset + 1;
    }

    // Elementul nu a fost găsit
    return -1;
}

int main() {
    vector<int> arr = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    int elementCautat = 85;
    int rezultat = fibonacciSearch(arr, elementCautat);

    if (rezultat != -1) {
        cout << "Elementul se află la indexul " << rezultat << endl;
    } else {
        cout << "Elementul nu a fost găsit în listă" << endl;
    }

    return 0;
}
```

### Output așteptat:
```
Elementul se află la indexul 8
```

## Compilare și rulare

1. Creează un fișier sursă cu codul de mai sus, de exemplu, `fibonacci_search.cpp`.
2. Deschide un terminal și navighează la locația fișierului.
3. Compilează fișierul cu un compilator C++, cum ar fi `g++`:

   ```bash
   g++ fibonacci_search.cpp -o fibonacci_search
   ```

4. Rulează programul:

   ```bash
   ./fibonacci_search
   ```

### Cerințe

- Un compilator C++ (de exemplu: `g++`, `clang++`).
- Lista de intrare trebuie să fie sortată.

## Contribuții

Orice contribuție este binevenită! Te rugăm să creezi un pull request sau să deschizi un issue dacă ai sugestii de îmbunătățire a codului sau a documentației.

## Licență

Acest proiect este licențiat sub [MIT License](LICENSE).
```

### Explicații:
- **Descrierea** algoritmului este similară cu cea pentru implementarea în JavaScript, dar adaptată pentru C++.
- Instrucțiunile pentru **compilare și rulare** sunt detaliate pentru a ușura procesul de testare.
- Codul sursă este inclus împreună cu un exemplu de output așteptat.
- Secțiunea de **Contribuții** și **Licență** oferă posibilitatea utilizatorilor de a contribui la proiect și de a înțelege termenii de utilizare.
