class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i] + ((i>1)?dp[i-2]:0) ;
            int skip=dp[i-1];
            dp[i]=max(take,skip);
        }
        return dp[nums.size()-1];
    }
};