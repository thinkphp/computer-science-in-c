#include <iostream>
#include <vector>
#include <string>

// Funcție pentru exponentiere modulară rapidă
int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (1LL * result * base) % mod;
        base = (1LL * base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Algoritmul extins Euclid pentru invers modular
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

// Calcul invers modular
int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1) return -1;
    return (x % m + m) % m;
}

// Funcție pentru criptarea unui text
std::vector<int> encryptText(const std::string &text, int e, int n) {
    std::vector<int> encrypted;
    for (char ch : text) {
        int ascii = (int)ch;
        encrypted.push_back(modExp(ascii, e, n));  // C = M^e mod n
    }
    return encrypted;
}

// Funcție pentru decriptarea unui text
std::string decryptText(const std::vector<int> &encrypted, int d, int n) {
    std::string decrypted;
    for (int num : encrypted) {
        char ch = (char)modExp(num, d, n);  // M = C^d mod n
        decrypted += ch;
    }
    return decrypted;
}

int main() {
    // Alegem două numere prime
    int p = 61, q = 53;
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Alegem exponentul public
    int e = 17;
    int d = modInverse(e, phi);
    if (d == -1) {
        std::cerr << "Nu s-a putut calcula cheia privată!" << std::endl;
        return 1;
    }

    std::string mesaj = "RSA Test";

    // Criptare
    std::vector<int> mesajCriptat = encryptText(mesaj, e, n);

    // Afișare mesaj criptat
    std::cout << "Mesaj criptat: ";
    for (int c : mesajCriptat) std::cout << c << " ";
    std::cout << std::endl;

    // Decriptare
    std::string mesajDecriptat = decryptText(mesajCriptat, d, n);
    std::cout << "Mesaj decriptat: " << mesajDecriptat << std::endl;

    return 0;
}
