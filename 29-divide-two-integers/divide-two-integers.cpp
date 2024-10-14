class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long num = abs((long long)dividend);
        long long denom = abs((long long)divisor);

        bool sign = (dividend < 0) == (divisor < 0);
        long long ans = 0;

        while (num >= denom) {
            int count = 0;
            while (num >= (denom << (count + 1))) {
                count++;
            }
            ans += (1 << count);
            num -= (denom << count);
        }

        return sign ? ans : -ans;
    }
};