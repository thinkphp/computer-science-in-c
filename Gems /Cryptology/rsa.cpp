#include <iostream>
#include <cmath>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Funcție pentru a calcula puterea modulară (a^b % mod)
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Funcție pentru a găsi inversul modular al lui e mod phi(n)
long long mod_inverse(long long e, long long phi) {
    long long t = 0, new_t = 1;
    long long r = phi, new_r = e;

    while (new_r != 0) {
        long long quotient = r / new_r;
        std::tie(t, new_t) = std::make_tuple(new_t, t - quotient * new_t);
        std::tie(r, new_r) = std::make_tuple(new_r, r - quotient * new_r);
    }
    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

int main() {
    long long p = 61;  // Prim 1
    long long q = 53;  // Prim 2
    long long n = p * q;  // n = p * q
    long long phi = (p - 1) * (q - 1);  // Calculăm phi(n)

    long long e = 17;  // Cheia publică e
    while (gcd(e, phi) != 1) {  // Verificăm că gcd(e, phi(n)) == 1
        e++;
    }

    long long d = mod_inverse(e, phi);  // Cheia privată d

    // Criptare
    long long message = 65;  // Mesaj de criptat
    long long encrypted = mod_exp(message, e, n);
    std::cout << "Mesaj criptat: " << encrypted << std::endl;

    // Decriptare
    long long decrypted = mod_exp(encrypted, d, n);
    std::cout << "Mesaj decriptat: " << decrypted << std::endl;

    return 0;
}
