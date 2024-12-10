class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int ans = -1;

        for (int len = 1; len <= n; len++) {
            unordered_map<string, int> mp;
            string temp = "";
            for (int i = 0; i < n; i++) {
                if (temp.empty() || s[i] == temp[0]) {
                    temp = s[i] + temp;
                } else {
                    temp = s[i];
                }

                if (temp.size() > len) {
                    temp.pop_back();
                }

                if (temp.size() == len) {
                    mp[temp]++;
                    if (mp[temp] == 3) {
                        ans = max(ans, len);
                    }
                }
            }
        }

        return ans;
    }
};