#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1999999973;

int32_t lgput(int a, int b) {
    int ans = 1;
    while(b != 0) {
        if(b % 2 == 1) {
            ans *= a;
            ans %= MOD;
           // b /= 2;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}

int32_t main(void) {
    ofstream cout("lgput.out");
    ifstream cin("lgput.in");
    int a, b;
    cin >> a >> b;
    cout << lgput(a, b);
}
