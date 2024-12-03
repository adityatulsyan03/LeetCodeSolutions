class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int prev = 0;
        for (int space : spaces) {
            ans += s.substr(prev, space - prev);
            ans += " ";
            prev = space;
        }
        ans += s.substr(prev);
        return ans;
    }
};