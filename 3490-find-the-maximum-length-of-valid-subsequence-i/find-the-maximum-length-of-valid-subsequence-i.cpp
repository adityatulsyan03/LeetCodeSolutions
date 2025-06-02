class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> dp(2,vector<int>(2,0));
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int curr=nums[i]%2;
            dp[curr][0] = max(dp[curr][0],1+dp[0][curr]);
            dp[curr][1] = max(dp[curr][1],1+dp[1][curr]);
            ans=max({ans,dp[curr][0],dp[curr][1]});
        }
        return ans;
    }
};