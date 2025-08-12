class Solution {
private:
    const int MOD = 1000000007;
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        dp[0][0] = 1;

        for (int num = 1; num <= n; num++) {
            long long p = 1;
            for (int i = 0; i < x; i++) {
                p *= num;
                if (p > n) break;
            }
            if (p > n) {
                for (int sum = 0; sum <= n; sum++)
                    dp[num][sum] = dp[num - 1][sum];
                continue;
            }
            for (int sum = 0; sum <= n; sum++) {
                dp[num][sum] = (dp[num][sum] + dp[num - 1][sum]) % MOD;

                if (sum >= p) {
                    dp[num][sum] = (dp[num][sum] + dp[num - 1][sum - p]) % MOD;
                }
            }
        }

        return dp[n][n];
    }
};