#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    priority_queue<int> q;
    unordered_map<int, int> m;
    long s = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        s += t;
        q.push(t);
        if (m.find(t) == m.end()) {
            m[t] = 0;
        }
        ++m[t];
    }
    double average = (double)s / (double)n;
    double median;
    int count;
    if (n % 2 == 0) count = (n - 1) / 2;
    else count = n / 2;
    int start = 0;
    while (start < count) {
        q.pop();
        ++start;
    }
    median += (double)q.top();
    if (n % 2 == 0) {
        q.pop();
        median += (double)q.top();
        median /= 2.0;
    }
    int mode = 0;
    int curMax = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (curMax < it -> second) {
            mode = it -> first;
            curMax = it -> second;
        } else if (curMax == it -> second && mode > it -> first) {
            mode = it -> first;
        }
    }
    cout << average << endl << median << endl << mode << endl;
    return 0;
}
