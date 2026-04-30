#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// -------------------- CHECK (brute force) --------------------
bool check(long long n) {
    if (n == 2 || n == 3)
        return true;

    if (n < 2)
        return false;

    if (n % 2 == 0)
        return false;

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// -------------------- FAST POWER (modular exponentiation) --------------------
long long fast_pow(long long base, long long exp, long long mod) {
    long long res = 1;

    while (exp > 0) {
        if (exp & 1)
            res = (res * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return res;
}

// -------------------- FERMAT TEST --------------------
bool Fermat(long long n) {
    if (n < 2)
        return false;

    if (n == 2 || n == 3)
        return true;

    if (n % 2 == 0)
        return false;

    for (int i = 0; i < 5; i++) {
        long long a = 2 + rand() % (n - 3); // [2, n-2]

        if (fast_pow(a, n - 1, n) != 1)
            return false;
    }

    return true;
}

// -------------------- MAIN --------------------
int main() {
    srand(time(0));

    long long n;
    cout << "N = ";
    cin >> n;

    cout << "Number: " << n << endl;

    cout << "Brute Force: ";
    if (check(n))
        cout << "is Prime" << endl;
    else
        cout << "is Not Prime" << endl;

    cout << "Fermat Test: ";
    if (Fermat(n))
        cout << "Probably Prime" << endl;
    else
        cout << "Not Prime" << endl;

    return 0;
}
