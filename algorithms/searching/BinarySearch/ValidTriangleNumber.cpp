/*
 * Given an integer array nums, return the number of triplets chosen from the 
*  array that can make triangles if we take 
 * them as side lengths of a triangle.
 */

class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        int n = nums.size(), ans = 0;//hold the number of the elements and set the ans to zero
           
        sort(nums.begin(), nums.end());//sort the elements of the array

        for(int i = n - 1; i >= 0; i--) {
            int lo = 0, hi = i - 1;

            while(lo<hi) {

                if(nums[lo]+nums[hi]>nums[i]) {

                    ans+=hi-lo;
                    hi--;

                } else  lo++;
            }

        }

        return ans;
    }
};
