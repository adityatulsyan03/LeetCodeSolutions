class Solution {
public:
    bool checkPowersOfThree(int n) {
        int t = 0;
        while (pow(3, t) <= n) {
            t++;
        }
        while (n > 0) {
            if (n >= pow(3, t)) n -= pow(3, t);
            if (n >= pow(3, t)) return false;
            t--;
        }
        return true;
    }
};