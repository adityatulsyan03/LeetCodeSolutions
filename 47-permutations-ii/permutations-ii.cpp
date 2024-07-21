class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int> temp,vector<bool> used,vector<int> nums){
        if(temp.size()==nums.size())
            ans.push_back(temp);
        else{
            for(int i=0;i<nums.size();i++){
                if((i!=0 && nums[i-1]==nums[i] && !used[i-1]) || used[i])  continue;
                temp.push_back(nums[i]);
                used[i]=true;
                helper(ans,temp,used,nums);
                used[i]=false;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        helper(ans,temp,used,nums);
        return ans;
    }
};