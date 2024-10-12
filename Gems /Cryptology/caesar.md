# Cifra lui Caesar

Aceasta este o implementare simplă a cifrului lui Caesar în C++. Algoritmul criptoază și decriptează un text dat folosind o deplasare specificată (shift).

## Descriere

Cifra lui Caesar este un algoritm de criptare simetrică, în care fiecare literă din textul original este înlocuită cu o literă aflată la o anumită distanță în alfabet. Această distanță este determinată de parametrul `shift`. De exemplu, cu un `shift` de 3, litera `A` devine `D`, `B` devine `E`, și așa mai departe.

## Funcționalități

- **Criptare**: Transformă textul original într-un text criptat.
- **Decriptare**: Transformă textul criptat înapoi în textul original.

## Utilizare

1. Clonați sau descărcați repo-ul.
2. Compilați fișierul `main.cpp` folosind un compilator C++.
3. Rulați programul. 

### Exemplu de rulare

```bash
g++ main.cpp -o caesar_cipher
./caesar_cipher
```

### Ieșire așteptată

```
Text: Hello, world!
Encrypted: Khoor, zruog!
Decrypted: Hello, world!
```

## Detalii tehnice

- **Biblioteci utilizate**:
  - `<iostream>` pentru input/output.
  - `<string>` pentru manipularea string-urilor.
  - `<algorithm>` pentru funcții ajutătoare (de exemplu, `std::isalpha` și `std::islower`).

### Funcția `caesarCipher`

Această funcție primește un `std::string` (textul de criptat/decriptat) și un `int` (deplasarea). Funcția parcurge fiecare caracter din text, verifică dacă este o literă și aplică deplasarea corespunzătoare, returnând textul rezultat.

```cpp
std::string caesarCipher(std::string text, int shift) {
    // Implementare...
}
```
