#include <bits/stdc++.h>

using namespace std;

void computeTotient(int n, vector<int>& phi) {
    // Initialize phi array
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    
    // Compute totient values using the modified Sieve of Eratosthenes
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) { // Check if i is prime
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> phi(n + 1);
    computeTotient(n, phi);

    // Display the totient values
    cout << "Euler's Totient Function values up to " << n << " are:\n";
    for (int i = 1; i <= n; i++) {
        cout << "phi(" << i << ") = " << phi[i] << "\n";
    }

    return 0;
}
