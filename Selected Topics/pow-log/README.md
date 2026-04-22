# 🔢 Ridicare la putere în C++ (timp liniar vs. timp logaritmic)

Acest proiect demonstrează două metode clasice de calcul al puterii unui număr:

* metoda **naivă (timp liniar)**
* metoda **rapidă (timp logaritmic)**

---

## 📌 1. Ridicare la putere în timp liniar

### 💡 Idee

Se înmulțește baza `a` de `n` ori.

### ⏱ Complexitate

* **Timp:** `O(n)`
* **Spațiu:** `O(1)`

### 🧠 Implementare

```cpp
int pow(int a, int n) {
    int p = 1;

    for(int i = 1; i <= n; ++i) 
        p *= a;

    return p;
}
```

### ✔ Avantaje

* Ușor de înțeles și implementat

### ❌ Dezavantaje

* Ineficient pentru valori mari ale lui `n`

---

## ⚡ 2. Ridicare la putere în timp logaritmic (Exponentiere rapidă)

### 💡 Idee

Folosește faptul că:

* dacă `n` este par:
  `aⁿ = (a²)^(n/2)`
* dacă `n` este impar:
  `aⁿ = a * (a²)^((n-1)/2)`

Se utilizează operații pe biți (`&`, `>>`) pentru eficiență.

### ⏱ Complexitate

* **Timp:** `O(log n)`
* **Spațiu:** `O(1)`

### 🧠 Implementare

```cpp
int fast_pow(int a, int n) {
    int result = 1;

    while(n > 0) {
        if(n & 1) 
            result = result * a;

        a = a * a;
        n >>= 1;
    }

    return result;
}
```

---

## 🧮 3. Variantă pentru numere mari

Pentru a evita overflow-ul pe `int`, se folosește `long long`:

```cpp
long long power(long long base, int exp) {
    long long result = 1;

    while(exp > 0) {
        if(exp & 1) 
            result = result * base;

        base = base * base;
        exp >>= 1;
    }

    return result;
}
```

---

## 🔍 4. Calcul logaritm în bază 2

### Varianta rapidă (fără `<cmath>`)

```cpp
int log2_fast(int a) {
    int cnt = 0;
    while (a >>= 1) {
        cnt++;
    }
    return cnt;
}
```

### 💡 Observație

* Returnează partea întreagă a logaritmului în bază 2
* Practic numără de câte ori putem împărți la 2

---

## 🚀 Exemplu de rulare

```cpp
int main() {
    std::cout << fast_pow(2, 20);
    std::cout << pow(2, 20) << std::endl;
    std::cout << log2(20) + 1 << "\n";
    std::cout << log2_fast(8) << std::endl;
    std::cout << power(2, 3);
    return 0;
}
```

---

## 📊 Comparatie

| Metodă      | Complexitate | Rapiditate |
| ----------- | ------------ | ---------- |
| Liniară     | O(n)         | 🐢 Lent    |
| Logaritmică | O(log n)     | ⚡ Rapid    |

---

## 🧠 Concluzie

Pentru calcule simple sau valori mici, metoda liniară este suficientă.
Pentru aplicații serioase (algoritmi, competiții, sisteme reale), **exponentierea rapidă este esențială**.

---

## 📚 Utilizări

* Algoritmi competitivi (ex: modular exponentiation)
* Criptografie
* Calcul numeric eficient


### Problem Set

- Abc 1 (clasa a 9-a) https://www.nerdarena.ro/problema/abc1
- Ridicare la putere in timp logaritmic https://www.infoarena.ro/problema/lgput
- The last digit https://www.spoj.com/problems/LASTDIG/

### Referecens
- https://www.pbinfo.ro/articole/18954/exponentiere-rapida
- https://infoas.ro/lectie/104/ridicarea-la-putere-in-timp-logaritmic-in-c-exponentiere-rapida
- https://www.algopedia.ro/wiki/index.php/Clasa_a_V-a_lec%C8%9Bia_42_-_24_mai_2018
