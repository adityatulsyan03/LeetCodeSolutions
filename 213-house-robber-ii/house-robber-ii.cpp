class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev1 = 0;

        for (int i = start; i <= end; ++i) {
            int take = nums[i] + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int case1 = helper(nums, 0, n - 2);

        int case2 = helper(nums, 1, n - 1);

        return max(case1, case2);
    }
};