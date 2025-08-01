class Solution {
private:
    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx >= nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        
        int take = nums[idx] + helper(idx + 2, nums, dp);
        int skip = helper(idx + 1, nums, dp);

        return dp[idx] = max(take, skip);
    }

    int robLinear(vector<int>& nums, int start, int end) {
        vector<int> dp(nums.size(), -1);
        vector<int> slice(nums.begin() + start, nums.begin() + end + 1);
        return helper(0, slice, dp);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int case1 = robLinear(nums, 0, n - 2);

        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};