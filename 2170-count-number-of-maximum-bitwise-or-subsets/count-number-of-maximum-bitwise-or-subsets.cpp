class Solution {
private:
    int count(vector<int>& nums,int index, int curr, int mx, vector<vector<int>>& dp){
        if (index == nums.size()) {
            return (curr==mx)?1:0;
        }
        if(dp[index][curr]!=-1)
            return dp[index][curr];

        int cntWithout = count(nums,index+1,curr,mx,dp);
        int cntWith = count(nums,index+1,curr|nums[index],mx,dp);
        return dp[index][curr]= cntWithout + cntWith;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0,n=nums.size();
        for(auto i:nums)
            mx = mx|i;
        vector<vector<int>> dp(n,vector<int>(mx+1,-1));
        return count(nums,0 ,0, mx,dp);
    }
};