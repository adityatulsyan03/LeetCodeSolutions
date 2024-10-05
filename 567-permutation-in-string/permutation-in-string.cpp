class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n) 
            return false;
        vector<int> s1_freq(26, 0), window_freq(26, 0);
        for (int i = 0; i < n; i++) {
            s1_freq[s1[i] - 'a']++;
        }
        for (int i = 0; i < m; i++) {
            window_freq[s2[i] - 'a']++;
            if (i >= n) {
                window_freq[s2[i - n] - 'a']--;
            }
            if (window_freq == s1_freq) {
                return true;
            }
        }
        return false;
    }
};
