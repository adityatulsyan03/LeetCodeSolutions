class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        unordered_map<int, int> andMap;

        for (int i = 0; i < nums.size(); ++i) {
            unordered_map<int, int> nextMap;
            nextMap[nums[i]]++;

            for (auto &[val, freq] : andMap) {
                int newAnd = val & nums[i];
                nextMap[newAnd] += freq;
            }

            for (auto &[val, freq] : nextMap) {
                if (val == k) result += freq;
            }

            andMap = move(nextMap);
        }

        return result;
    }
};