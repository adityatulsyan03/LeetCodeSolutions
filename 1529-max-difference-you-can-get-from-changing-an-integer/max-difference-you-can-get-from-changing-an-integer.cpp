class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num), maxStr = s, minStr = s;
        char a = 0, b = 0;

        for (char c : s) {
            if (c != '9') { a = c; break; }
        }
        
        for (char &c : maxStr) if (c == a) c = '9';

        if (s[0] != '1') b = s[0];
        else {
            for (char c : s) {
                if (c != '0' && c != '1') { b = c; break; }
            }
        }
        for (char &c : minStr) if (c == b) c = (b == s[0] ? '1' : '0');

        return stoi(maxStr) - stoi(minStr);
    }
};