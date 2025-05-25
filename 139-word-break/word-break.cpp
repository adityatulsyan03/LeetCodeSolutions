class Solution {
private:
    bool helper(unordered_map<string, int>& cnt, string& s, int idx, vector<int>& dp) {
        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];

        string temp = "";
        for (int i = idx; i < s.size(); i++) {
            temp += s[i];
            if (cnt[temp] > 0) {
                if (helper(cnt, s, i + 1, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> cnt;
        for (auto word : wordDict) {
            cnt[word]++;
        }
        vector<int> dp(s.size(), -1);
        return helper(cnt, s, 0, dp);
    }
};