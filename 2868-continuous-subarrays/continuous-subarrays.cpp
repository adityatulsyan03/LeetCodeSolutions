class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long i = 0, j = 0, ans = 0;
        map<int, int> freq;

        while (j < nums.size()) {
            freq[nums[j]]++;

            int mn = freq.begin()->first;
            int mx = freq.rbegin()->first;

            while (abs(mx - mn) > 2) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i++;
                mn = freq.begin()->first;
                mx = freq.rbegin()->first;
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};