# Indicatorul lui Euler
Indicatorul lui Euler, notat \( \phi(n) \), este o funcție matematică importantă în teoria numerelor. Este cunoscută și ca **funcția φ (phi) a lui Euler** sau **funcția totientă a lui Euler**.

---

### **Definiția**
Pentru un număr natural \( n \), \( \phi(n) \) reprezintă numărul de numere întregi pozitive mai mici sau egale cu \( n \) care sunt **coprime** cu \( n \). Două numere sunt coprime dacă cel mai mare divizor comun (GCD) al lor este \( 1 \).

\[
\phi(n) = \text{numărul de valori } k, \text{ cu } 1 \leq k \leq n, \text{ astfel încât } \text{GCD}(k, n) = 1
\]

---

### **Exemple**
1. \( n = 1 \):  
   Singurul număr \( k \) este \( 1 \), iar \( \text{GCD}(1, 1) = 1 \).  
   Deci, \( \phi(1) = 1 \).

2. \( n = 6 \):  
   Numerele de la \( 1 \) la \( 6 \) sunt: \( 1, 2, 3, 4, 5, 6 \).  
   - Coprime cu \( 6 \): \( 1, 5 \).  
   Deci, \( \phi(6) = 2 \).

3. \( n = 10 \):  
   Numerele de la \( 1 \) la \( 10 \) sunt: \( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 \).  
   - Coprime cu \( 10 \): \( 1, 3, 7, 9 \).  
   Deci, \( \phi(10) = 4 \).

---

### **Proprietăți**
1. **Dacă \( n \) este prim:**  
   Toate numerele mai mici decât \( n \) sunt coprime cu \( n \).  
   \[
   \phi(p) = p - 1, \text{ unde } p \text{ este prim.}
   \]

   Ex: \( \phi(7) = 6 \), deoarece \( 1, 2, 3, 4, 5, 6 \) sunt coprime cu \( 7 \).

2. **Pentru un număr \( n = p_1^{e_1} \cdot p_2^{e_2} \cdot \dots \cdot p_k^{e_k} \) (factorizare primă):**  
   Funcția totientă se calculează astfel:
   \[
   \phi(n) = n \cdot \prod_{p \mid n} \left( 1 - \frac{1}{p} \right)
   \]
   Unde \( p \) sunt divizorii primi ai lui \( n \).

   Exemplu: \( n = 12 = 2^2 \cdot 3 \):  
   \[
   \phi(12) = 12 \cdot \left( 1 - \frac{1}{2} \right) \cdot \left( 1 - \frac{1}{3} \right) = 12 \cdot \frac{1}{2} \cdot \frac{2}{3} = 4
   \]

3. **Funcția este multiplicativă:**  
   Dacă \( a \) și \( b \) sunt coprime (\( \text{GCD}(a, b) = 1 \)), atunci:
   \[
   \phi(a \cdot b) = \phi(a) \cdot \phi(b)
   \]

---

### **Calcularea funcției φ pentru orice \( n \)**
#### 1. **Metoda brută:**  
Numărăm direct câte numere între \( 1 \) și \( n \) sunt coprime cu \( n \). Se folosește cel mai mare divizor comun (GCD):
\[
\text{GCD}(i, n) = 1
\]
Acest algoritm este lent pentru valori mari ale lui \( n \).

#### 2. **Metoda eficientă folosind factorizarea primă:**  
Se aplică formula:
\[
\phi(n) = n \cdot \prod_{p \mid n} \left( 1 - \frac{1}{p} \right)
\]
Această metodă este mai rapidă, dar necesită factorizarea \( n \).

#### 3. **Ciurul lui Eratosthenes modificat:**  
Calculăm valorile \( \phi(i) \) pentru toate \( i \) până la un maxim \( N \) în timp \( O(N \log \log N) \):
- Inițializăm \( \phi[i] = i \) pentru toate \( i \).
- Dacă \( i \) este prim, actualizăm \( \phi[j] \) pentru toate multiplul lui \( i \):
\[
\phi[j] = \phi[j] \cdot \left(1 - \frac{1}{i}\right)
\]

---

### **Aplicații ale funcției lui Euler**
1. **Teorema lui Euler:**  
   Dacă \( a \) și \( n \) sunt coprime, atunci:
   \[
   a^{\phi(n)} \equiv 1 \, (\text{mod } n)
   \]

2. **Criptografia RSA:**  
   Funcția \( \phi \) este esențială pentru calcularea cheii private în algoritmul RSA.

3. **Probleme combinatorice:**  
   Apare în probleme legate de fracții ireductibile, precum cea descrisă de tine.

---

### **Exemplu practic**
Pentru \( n = 10 \), vrem să calculăm \( \phi(10) \):
- Factorizarea primă: \( 10 = 2 \cdot 5 \).
- Formula:
\[
\phi(10) = 10 \cdot \left(1 - \frac{1}{2}\right) \cdot \left(1 - \frac{1}{5}\right) = 10 \cdot \frac{1}{2} \cdot \frac{4}{5} = 4
\]

Fracțiile ireductibile pentru \( n = 10 \): \( 1/10, 3/10, 7/10, 9/10 \).

### Problem set
- https://www.infoarena.ro/problema/fractii
 - https://www.pbinfo.ro/probleme/3227/tramvaie

### References
https://www.pbinfo.ro/articole/18882/indicatorul-lui-euler
