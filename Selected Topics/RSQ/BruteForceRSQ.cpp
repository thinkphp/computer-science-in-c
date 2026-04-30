#include <bits/stdc++.h>
using namespace std;

// Brute Force RSQ
class BruteForceRSQ {
private:
    vector<long long> arr;

public:
    BruteForceRSQ(const vector<long long>& input) {
        arr = input;
    }

    // update: O(1)
    void update(int pos, long long val) {
        arr[pos] = val;
    }

    // query: O(n)
    long long query(int l, int r) {
        long long sum = 0;
        for (int i = l; i <= r; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "n = ";
    cin >> n;

    vector<long long> v(n);
    cout << "Elemente:\n";
    for (auto &x : v) cin >> x;

    BruteForceRSQ rsq(v);

    int q;
    cout << "Numar query-uri = ";
    cin >> q;

    while (q--) {
        int type;
        cout << "\nTip (1 = query, 2 = update): ";
        cin >> type;

        if (type == 1) {
            int l, r;
            cout << "l r = ";
            cin >> l >> r;
            cout << "Sum = " << rsq.query(l, r) << "\n";
        } else {
            int pos;
            long long val;
            cout << "pos val = ";
            cin >> pos >> val;
            rsq.update(pos, val);
        }
    }

    return 0;
}
