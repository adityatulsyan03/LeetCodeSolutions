class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1,c=0;
        
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        };

        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(l + 1, r) || isPalindrome(l, r - 1);
            }
            l++;
            r--;
        }

        return true;
    }
};