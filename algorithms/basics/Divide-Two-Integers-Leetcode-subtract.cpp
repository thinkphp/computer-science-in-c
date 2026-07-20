class Solution {
public:
    long long divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int result = 0;
        int sign = 1;
        
        long long n = abs((long long) dividend);
        long long d = abs((long long) divisor);

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = -1;
        if(d == 1) {
            result = n;
            return (long long) sign * result;
        }

        while(n >= d){
            n = n - d;         //SUBTRACTION
            result++;
        }

        return (long long) sign * result;
    }
};
