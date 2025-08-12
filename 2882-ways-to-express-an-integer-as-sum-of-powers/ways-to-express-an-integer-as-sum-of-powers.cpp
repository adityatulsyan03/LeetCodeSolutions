class Solution {
private:
    const int MOD = 1000000007;
    int helper(int n, int x, int num, int curr, vector<vector<int>>& dp){
        if(curr == n)  return 1;
        if(curr > n || pow(num,x)>n)   return 0;
        if(dp[num][curr] != -1) return dp[num][curr];

        int take = helper(n,x,num+1,curr+pow(num,x),dp);
        int notTake = helper(n,x,num+1,curr,dp);

        return dp[num][curr] = (take + notTake)%MOD;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+2,vector<int>(n+1,-1));
        return helper(n,x,1,0,dp);
    }
};