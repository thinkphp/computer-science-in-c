#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    int n;
    vector<long long> tree, lazy;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(nums, node * 2 + 1, start, mid);
        build(nums, node * 2 + 2, mid + 1, end);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) {
                lazy[node * 2 + 1] += lazy[node];
                lazy[node * 2 + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void updateRange(int L, int R, int val) {
        updateUtil(0, 0, n - 1, L, R, val);
    }

    void updateUtil(int node, int start, int end, int L, int R, int val) {
        push(node, start, end);

        if (R < start || end < L)
            return;

        if (L <= start && end <= R) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        updateUtil(node * 2 + 1, start, mid, L, R, val);
        updateUtil(node * 2 + 2, mid + 1, end, L, R, val);

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }

    long long query(int L, int R) {
        return queryUtil(0, 0, n - 1, L, R);
    }

    long long queryUtil(int node, int start, int end, int L, int R) {
        push(node, start, end);

        if (R < start || end < L)
            return 0;

        if (L <= start && end <= R)
            return tree[node];

        int mid = (start + end) / 2;
        long long leftSum = queryUtil(node * 2 + 1, start, mid, L, R);
        long long rightSum = queryUtil(node * 2 + 2, mid + 1, end, L, R);
        return leftSum + rightSum;
    }
};


int main() {
    vector<int> nums = {2, 7, 1, 3, 5, 9, 4, 8};

    SegmentTree st(nums);

    cout << "Sum(2, 6) = " << st.query(2, 6) << "\n";
    // 1 + 3 + 5 + 9 + 4 = 22

    st.updateRange(2, 5, 10);
    // Adaugăm +10 pe intervalul [2..5]
    // Array devine: [2,7,11,13,15,19,4,8]

    cout << "After update: Sum(2, 6) = " << st.query(2, 6) << "\n";
    // 11 + 13 + 15 + 19 + 4 = 62

    return 0;
}
