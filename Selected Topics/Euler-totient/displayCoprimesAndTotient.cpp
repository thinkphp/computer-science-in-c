#include <bits/stdc++.h>

using namespace std;

// Function to compute the Euler's totient function for each number up to n
void computeTotient(int n, vector<int>& phi) {
    for (int i = 1; i <= n; i++) {
        phi[i] = i;
    }
    
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) { // Check if i is prime
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

// Function to find and display numbers that are relatively prime to each number up to n
void displayRelativelyPrimeNumbers(int n, const vector<int>& phi) {
    for (int i = 1; i <= n; i++) {
        cout << "phi(" << i << ") = " << phi[i] << ": Relatively prime numbers are: ";
        for (int j = 1; j < i; j++) {
            if (__gcd(i, j) == 1) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> phi(n + 1);
    computeTotient(n, phi);

    displayRelativelyPrimeNumbers(n, phi);

    return 0;
}
