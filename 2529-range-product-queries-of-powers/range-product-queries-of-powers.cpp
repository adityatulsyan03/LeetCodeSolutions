class Solution {
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int a = n, c = 0;
        while (a > 0) {
            if (a & 1) {
                powers.push_back(1 << c);
            }
            c++;
            a >>= 1;
        }

        powers[0] %= MOD;
        for (int i = 1; i < powers.size(); i++) {
            powers[i] = (1LL * powers[i] * powers[i-1]) % MOD;
        }

        vector<int> ans;
        for (auto &query : queries) {
            int l = query[0], r = query[1];
            if (l == 0) {
                ans.push_back(powers[r]);
            } else {
                long long inv = modPow(powers[l-1], MOD-2);
                ans.push_back((powers[r] * inv) % MOD);
            }
        }
        return ans;
    }
};