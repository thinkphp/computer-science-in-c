#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    pair<int, vector<int>> lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n, -1);         // pentru reconstruirea drumului
        vector<int> indices(n, 0);       // indices[i] = indexul din nums al finalului LIS de lungime i+1
        vector<int> tails;               // valorile finale ale LIS-urilor
        int size = 0;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];

            // Binary search în tails
            int left = 0, right = size;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[indices[mid]] < x)
                    left = mid + 1;
                else
                    right = mid;
            }

            // Update tails și prev
            if (left > 0)
                prev[i] = indices[left - 1];
            indices[left] = i;

            if (left == size)
                ++size;
        }

        // Reconstruim LIS-ul
        vector<int> lis;
        int k = indices[size - 1];
        while (k >= 0) {
            lis.push_back(nums[k]);
            k = prev[k];
        }
        reverse(lis.begin(), lis.end());

        return {size, lis};
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    Solution sol;
    auto [length, subsequence] = sol.lengthOfLIS(nums);

    cout << "Lungimea LIS: " << length << endl;
    cout << "Subsecvența LIS: ";
    for (int x : subsequence) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
