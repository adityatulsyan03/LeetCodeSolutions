class Solution {
private:
    void helper(vector<vector<int>>& ans,vector<int> temp,vector<bool> used,vector<int> nums){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }
        else{
            for(int j=0;j<nums.size();j++){
                if(used[j]) continue;
                used[j]=true;
                temp.push_back(nums[j]);
                helper(ans,temp,used,nums);
                used[j]=false;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        helper(ans,temp,used,nums);
        return ans;
    }
};