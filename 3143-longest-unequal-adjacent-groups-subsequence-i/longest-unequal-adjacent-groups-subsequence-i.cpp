class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        if (words.empty()) return result;

        result.push_back(words[0]);
        int last_group = groups[0];

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != last_group) {
                result.push_back(words[i]);
                last_group = groups[i];
            }
        }

        return result;
    }
};