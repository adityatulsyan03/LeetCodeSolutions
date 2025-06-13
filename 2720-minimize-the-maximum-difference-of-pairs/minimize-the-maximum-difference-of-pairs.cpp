class Solution {
private:
    int helper(vector<int>& nums, int t) {
        int i = 0, cnt = 0;
        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= t) {
                cnt++;
                i++;
            }
            i++;
        }
        return cnt;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n - 1] - nums[0];

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(nums, mid) >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};