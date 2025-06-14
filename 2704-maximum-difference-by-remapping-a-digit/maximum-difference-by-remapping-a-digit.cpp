class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char mx = s[0];
        char mn = '0';
        for (char c : s) {
            if (c != '9') {
                mn = c;
                break;
            }
        }

        string minStr = s;
        for (char &c : minStr) {
            if (c == mx) c = '0';
        }
        string maxStr = s;
        for (char &c : maxStr) {
            if (c == mn) c = '9';
        }
        
        return stoi(maxStr) - stoi(minStr);
    }
};