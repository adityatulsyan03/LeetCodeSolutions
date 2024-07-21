class Solution {
private:
    void helper(int i,vector<vector<int>>& ans,vector<int> temp,vector<int> nums){
        ans.push_back(temp);
        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j-1]==nums[j])  continue;
            temp.push_back(nums[j]);
            helper(j+1,ans,temp,nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> te;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(0,te,temp,nums);
        vector<vector<int>> ans(te.begin(),te.end());
        return ans;
    }
};