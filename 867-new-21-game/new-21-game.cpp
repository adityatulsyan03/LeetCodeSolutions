class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;  
        vector<double> dp(n + maxPts + 1,0.0);
        for (int i=k;i<=n;i++) {
            dp[i]=1.0;
        }
        double windowSum = 0.0;
        for (int i = 1; i <= maxPts; i++) {
            windowSum += dp[k + i - 1];
        }
        for (int curr = k-1; curr >= 0; curr--) {
            dp[curr] = windowSum / maxPts;
            windowSum += dp[curr];
            windowSum -= dp[curr + maxPts];
        }
        return dp[0];
    }
};