# Cifra de Substituție

Aceasta este o implementare a cifrei de substituție în C++. Algoritmul permite criptarea și decriptarea unui text dat folosind o cheie specificată.

## Descriere

Cifra de substituție este un algoritm de criptare în care fiecare literă din textul original este înlocuită cu o literă diferită, determinată de o cheie de substituție. Această cheie este un map care asociază fiecare caracter original cu un caracter criptat.

## Funcționalități

- **Criptare**: Transformă textul original într-un text criptat folosind cheia de substituție.
- **Decriptare**: Transformă textul criptat înapoi în textul original folosind cheia de substituție.

## Utilizare

1. Clonați sau descărcați repo-ul.
2. Compilați fișierul `main.cpp` folosind un compilator C++.
3. Rulați programul.

### Exemplu de rulare

```bash
g++ main.cpp -o substitution_cipher
./substitution_cipher
```

### Ieșire așteptată

```
Text: Hello, world!
Encrypted: Iktto, vjvwd!
Decrypted: Hello, world!
```

## Detalii tehnice

- **Biblioteci utilizate**:
  - `<iostream>` pentru input/output.
  - `<string>` pentru manipularea string-urilor.
  - `<map>` pentru stocarea și manipularea perechilor cheie-valoare.

### Funcția `substitutionCipher`

Această funcție primește un `std::string` (textul de criptat/decriptat), un `std::map<char, char>` (cheia de substituție) și un `bool` (indică dacă se efectuează criptarea sau decriptarea). Funcția parcurge fiecare caracter din text și aplică cheia de substituție corespunzătoare, returnând textul rezultat.

```cpp
std::string substitutionCipher(std::string text, std::map<char, char> key, bool encrypt) {
    // Implementare...
}
```

