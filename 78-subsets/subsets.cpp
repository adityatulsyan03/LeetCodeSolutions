class Solution {
private:
    void generateSubsets(vector<int>& nums,int index, vector<int>& curr, vector<vector<int>>& result){
        if (index == nums.size()) {
            result.push_back(curr);
            return;
        }
        generateSubsets(nums, index+1, curr, result);
        curr.push_back(nums[index]);
        generateSubsets(nums, index+1, curr, result);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        generateSubsets(nums, 0, curr, result);
        return result;
    }
};