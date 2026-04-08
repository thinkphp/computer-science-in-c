Sunt înrudite, dar nu sunt exact același lucru.

### 🔹 Two pointers (doi pointeri)

Este o tehnică generală în care folosești **două variabile (pointeri/indexuri)** pentru a parcurge o structură (de obicei un array sau un string).

* pot merge în aceeași direcție sau în direcții opuse
* nu implică neapărat o „fereastră”
* se folosește la:

  * căutare în array sortat
  * eliminare duplicate
  * intersecții
  * palindrome etc.

👉 Exemplu: `i = 0`, `j = n-1` (convergent)

---

### 🔹 Sliding window (fereastră glisantă)

Este **un caz particular de two pointers**, unde cei doi pointeri definesc o **fereastră continuă** într-un array/string.

* `left` și `right` delimitează un interval `[left, right]`
* fereastra se „mută” (sliding) prin creșterea/diminuarea ei
* se folosește la:

  * subarray/substrings
  * sumă maximă/minimă
  * probleme de tip „longest/shortest window”

👉 Exemplu: menții o sumă pe interval și muți `right`, apoi ajustezi `left`

---

### 🔥 Diferența esențială

* **Two pointers = concept general**
* **Sliding window = aplicație specifică a two pointers pe intervale continue**

---

### 🧠 Intuiție simplă

* Two pointers: „doi indicatori care explorează”
* Sliding window: „o fereastră care se deplasează pe un array”

