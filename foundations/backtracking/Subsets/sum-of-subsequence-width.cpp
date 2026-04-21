class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<long long> pow2(n);
        pow2[0] = 1;
        
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        
        long long result = 0;
        
        for (int i = 0; i < n; i++) {
            long long max_contrib = nums[i] * pow2[i];
            long long min_contrib = nums[i] * pow2[n-i-1];
            
            result = (result + max_contrib - min_contrib) % MOD;
        }
        
        return (result + MOD) % MOD;
    }
};
