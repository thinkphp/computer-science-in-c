class Solution {
public:
    string commonPrefix(const string &a, const string &b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i])
                return a.substr(0, i);
        }
        return a.substr(0, len);
    }

    string divideAndConquer(vector<string>& strs, int left, int right) {
        if (left == right)
            return strs[left];

        int mid = (left + right) / 2;

        string lcpLeft = divideAndConquer(strs, left, mid);
        string lcpRight = divideAndConquer(strs, mid + 1, right);

        return commonPrefix(lcpLeft, lcpRight);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        return divideAndConquer(strs, 0, strs.size() - 1);
    }
};
