class Solution {
public:
    int maxDiff(int num) {
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
            if (c == mx) c = '1';
        }
        string maxStr = s;
        for (char &c : maxStr) {
            if (c == mn) c = '9';
        }

        if(mx=='1'){
            for(char c:s){
                if(c!='1' && c!='0'){
                    mx=c;
                    break;
                }
            }
            for (char &c : minStr) {
                if (c == mx && mx!='1') c = '0';
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};