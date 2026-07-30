#include <bits/stdc++.h>
using namespace std;

int cycleLength(long long n) {
    int count = 1;

    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        count++;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long i, j;

    while (cin >> i >> j) {
        long long start = min(i, j);
        long long end = max(i, j);

        int maximum = 0;

        for (long long n = start; n <= end; n++) {
            maximum = max(maximum, cycleLength(n));
        }

        cout << i << " " << j << " " << maximum << "\n";
    }

    return 0;
}
