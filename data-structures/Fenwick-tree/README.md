# Fenwick Tree (Binary Indexed Tree)

## 📌 Overview

Fenwick Tree (sau **Binary Indexed Tree - BIT**) este o structură de date eficientă pentru:

- calculul sumelor prefixate
- actualizări de elemente

Toate operațiile se fac în **O(log n)**.

---

## 🚀 Operații suportate

| Operație              | Complexitate |
|----------------------|-------------|
| Update (adăugare)    | O(log n)    |
| Query (sumă prefix)  | O(log n)    |
| Sumă pe interval     | O(log n)    |

---

## 🧠 Ideea de bază

Fenwick Tree stochează sume parțiale astfel încât:

- fiecare poziție acoperă un interval de lungime `2^k`
- folosim operația:  
  ```cpp
  i & (-i)
````

pentru a naviga în structură

---

## 📦 Implementare C++

```cpp
#include <iostream>
using namespace std;

int n;
int BIT[100] = {0};

void update(int i, int val) {
    while (i <= n) {
        BIT[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int sum = 0;
    while (i >= 1) {
        sum += BIT[i];
        i -= (i & -i);
    }
    return sum;
}

int range_sum(int l, int r) {
    return query(r) - query(l - 1);
}
```

---

## 🔢 Exemplu

```cpp
int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
n = 10;

for(int i = 1; i <= n; i++) {
    update(i, arr[i]);
}

cout << range_sum(2, 7); // 27
```

---

## 📐 Formule importante

* Sumă prefix:

  ```
  sum(1, x) = query(x)
  ```

* Sumă interval:

  ```
  sum(l, r) = query(r) - query(l - 1)
  ```

---

## ⚙️ Cum funcționează `i & (-i)`

Extrage **cel mai mic bit setat** (LSB - Least Significant Bit).

Exemple:

| i (binar) | i & -i |
| --------- | ------ |
| 6 (110)   | 2      |
| 8 (1000)  | 8      |
| 10 (1010) | 2      |

---

## 📈 Avantaje

* simplu de implementat
* memorie eficientă O(n)
* rapid pentru update + query

---

## ⚠️ Limitări

* nu suportă ușor operații complexe (min, max fără modificări)
* mai puțin flexibil decât Segment Tree

---

## 🧩 Extensii

* Range Update + Point Query
* Range Update + Range Query (folosind 2 Fenwick Trees)
* Order statistics (k-th element)

---

## 🎯 Când îl folosești?

Folosește Fenwick Tree când:

* ai multe **update-uri**
* ai multe **query-uri de sumă**
* datele sunt dinamice

---

## 📚 Concluzie

Fenwick Tree este una dintre cele mai importante structuri de date pentru probleme de:

* sume pe intervale
* optimizare în O(log n)

Este mai simplu decât Segment Tree și foarte eficient în practică.


#### Problem Set

- https://www.infoarena.ro/problema/aib

- https://cses.fi/problemset/task/1646/

- https://www.pbinfo.ro/probleme/eticheta/125/arbori-indexati-binar

- https://leetcode.com/tag/binary-indexed-tree/
