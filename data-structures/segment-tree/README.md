## Segment Tree Data Structure

```cpp
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(nums, 2 * node + 1, start, mid);
        build(nums, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int L, int R) {
        return queryUtil(0, 0, n - 1, L, R);
    }

    int queryUtil(int node, int start, int end, int L, int R) {
        if (R < start || end < L)
            return 0;

        if (L <= start && end <= R)
            return tree[node];

        int mid = (start + end) / 2;
        int leftSum = queryUtil(2 * node + 1, start, mid, L, R);
        int rightSum = queryUtil(2 * node + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }

    void update(int index, int value) {
        updateUtil(0, 0, n - 1, index, value);
    }

    void updateUtil(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            updateUtil(2 * node + 1, start, mid, idx, val);
        else
            updateUtil(2 * node + 2, mid + 1, end, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

int main() {
    vector<int> nums = {2, 7, 1, 3, 5, 9, 4, 8};

    SegmentTree st(nums);

    cout << "Sum(2, 6) = " << st.query(2, 6) << "\n"; // 1+3+5+9+4 = 22

    st.update(3, 10); // schimbam a[3] = 3 -> 10

    cout << "After update: Sum(2, 6) = " << st.query(2, 6) << "\n";
    // acum: 1 + 10 + 5 + 9 + 4 = 29

    return 0;
}
```

### Problem Set

- Arbori de intervale https://infoarena.ro/problema/arbint
- Range Sum Query https://leetcode.com/problems/range-sum-query-immutable/description/
- Range Sum Query Mutable https://leetcode.com/problems/range-sum-query-mutable/description/
