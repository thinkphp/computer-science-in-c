#include <iostream>
using namespace std;
 
int vec[1001], d, m, n, x;
 
int main() {
    cout << "n ( <=1000 ) = ";
    cin >> n;
 
    for (int tt = 2; tt <= n; ++tt) {
        x = tt;
        for (d = 2; x > 1; d++) {
            for (m = 0; (x % d) == 0; m++, x /= d); // Correct counting
            vec[d] += m;  // Accumulate the factor counts
        }
    }
 
    cout << n << "! prime factorization:\n";
    for (d = 2; d <= n; ++d) {
        if (vec[d]) cout << d << "^" << vec[d] << endl;
    }
 
    return 0;
}
