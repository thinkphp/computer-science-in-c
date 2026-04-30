class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    int mn = nums[0], mx = nums[0];

    for (int x : nums) {
        mn = min(mn, x);
        mx = max(mx, x);
    }

    vector<int> freq(mx - mn + 1, 0);

    for (int x : nums) {
        freq[x - mn]++;
    }

    int idx = 0;
    for (int i = 0; i < freq.size(); i++) {
        while (freq[i] > 0) {
            nums[idx++] = i + mn;
            freq[i]--;
        }
    }

    return nums;
}
};
