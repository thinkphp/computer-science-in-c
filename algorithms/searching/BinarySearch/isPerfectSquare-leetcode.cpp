class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        int end = num;

        while(start <= end)
        {
            long long mid = start + (end - start) / 2;

            if(mid * mid == num)
            return true;
            else if(mid * mid > num)
            end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};
