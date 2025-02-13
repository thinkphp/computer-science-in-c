#include <iostream>

// Funcție pentru exponentiere modulară rapidă
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {  // Dacă bitul curent al lui exp este 1
            result = (1LL * result * base) % mod;
        }
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Algoritmul extins Euclid pentru a găsi inversul modular
int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Funcție pentru a calcula inversul modular
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        std::cerr << "Inversul modular nu există!" << std::endl;
        return -1;
    }
    return (x % m + m) % m;
}

int main() {
    int p = 61, q = 53; // Două numere prime mai mari
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e = 17; // Un număr coprim cu phi
    int d = modInverse(e, phi); // Cheia privată

    if (d == -1) {
        std::cerr << "Nu s-a putut calcula cheia privată!" << std::endl;
        return 1;
    }

    int mesaj = 42; // Mesajul de criptat

    // Criptare: c = m^e mod n
    int mesajCriptat = modExp(mesaj, e, n);

    // Decriptare: m = c^d mod n
    int mesajDecriptat = modExp(mesajCriptat, d, n);

    std::cout << "Mesaj original: " << mesaj << std::endl;
    std::cout << "Mesaj criptat: " << mesajCriptat << std::endl;
    std::cout << "Mesaj decriptat: " << mesajDecriptat << std::endl;

    return 0;
}
