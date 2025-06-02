class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k,vector<int>(k,0));
        int n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            int curr=nums[i]%k;
            for(int j=0;j<k;j++){
                dp[curr][j]=max(dp[curr][j],1+dp[j][curr]);
                ans=max(ans,dp[curr][j]);
            }
        }
        return ans;
    }
};