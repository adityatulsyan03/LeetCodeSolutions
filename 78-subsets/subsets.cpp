class Solution {
private:
    void helper(int i,vector<vector<int>>& ans,vector<int> temp,vector<int> nums){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            helper(j+1,ans,temp,nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0,ans,temp,nums);
        return ans;
    }
};