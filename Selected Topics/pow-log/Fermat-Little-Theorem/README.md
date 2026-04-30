# 📌 Mica teoremă a lui Fermat

Mica teoremă a lui Fermat este un rezultat fundamental din teoria numerelor care stabilește o proprietate importantă a numerelor prime în aritmetica modulară.
https://en.wikipedia.org/wiki/Fermat%27s_little_theorem

## 🔷 Enunțul teoremei

Dacă ( p ) este un număr prim și ( a ) este un număr întreg care nu este divizibil cu ( p ), atunci:

a^{p-1} \equiv 1 \pmod p

---

## 🔷 Interpretare intuitivă

Aceasta înseamnă că, dacă ridicăm un număr ( a ) la puterea ( p-1 ) și îl împărțim la un număr prim ( p ), restul obținut va fi întotdeauna 1, atâta timp cât ( a ) nu este multiplu de ( p ).

---

## 🔷 Forma echivalentă

Teorema mai poate fi scrisă și astfel:

a^p \equiv a \pmod p

---

## 🔷 Condiții importante

* ( p ) trebuie să fie **număr prim**
* ( a ) trebuie să fie un întreg cu ( a \not\equiv 0 \pmod p )

---

## 🔷 Importanță

Mica teoremă a lui Fermat este utilizată în:

* teste de primalitate (Fermat primality test)
* criptografie (RSA și sisteme de securitate)
* algoritmi modulari eficienți

---

## ⚠️ Observație importantă

Teorema este **deterministă**, dar aplicarea ei în testul de primalitate devine **probabilistică**, deoarece funcționează invers și poate accepta numere compuse speciale (ex: numere Carmichael).
