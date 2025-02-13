#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define ll long long

ll euclidian(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
 		x = 1;
 		y = 0;
 		return a;
	}
    else {
		ll x0, y0, d;
		d = euclidian(b, a%b, x0, y0);
		x = y0;
		y = x0 - (a / b) * y0;
		return d;
	}
}

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

void solve() {
    ll a, m;
    fin >> a >> m;
    ll x, y;
    ll g = euclidian(a, m, x, y);
    x = (x % m + m) % m;
    fout << x << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
