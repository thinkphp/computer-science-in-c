#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("scmax.in", "r", stdin);
    freopen("scmax.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    vector<int> prev(n, -1);      // pentru a reconstrui LIS
    vector<int> indices(n, 0);    // indices[i] = indexul finalului LIS de lungime i+1
    int size = 0;

    for (int i = 0; i < n; ++i) {
        int left = 0, right = size;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[indices[mid]] < nums[i])
                left = mid + 1;
            else
                right = mid;
        }

        if (left > 0)
            prev[i] = indices[left - 1];
        indices[left] = i;
        if (left == size)
            ++size;
    }

    // reconstrucție LIS
    vector<int> lis;
    int k = indices[size - 1];
    while (k >= 0) {
        lis.push_back(nums[k]);
        k = prev[k];
    }
    reverse(lis.begin(), lis.end());

    // scriere rezultat
    cout << size << "\n";
    for (int x : lis)
        cout << x << " ";
    cout << "\n";

    return 0;
}
