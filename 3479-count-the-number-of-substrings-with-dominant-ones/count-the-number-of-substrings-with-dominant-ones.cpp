class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> prefix(n);

        prefix[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + (s[i] == '1' ? 1 : 0);
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; j++) {
                int one = prefix[j] - (i == 0 ? 0 : prefix[i - 1]);
                int len = j - i + 1;
                int zero = len - one;

                int sq = zero * zero;

                if (sq > one) {
                    j += (sq - one - 1);
                } else if (sq == one) {
                    ++ans;
                } else if(sq < one) {
                    ++ans;
                    int diff = sqrt(one) - zero;
                    int nextj = j + diff;

                    if (nextj >= n) {
                        ans += (n - j - 1);
                        break;
                    } else {
                        ans += diff;
                    }

                    j = nextj;
                }
            }
        }

        return ans;
    }
};