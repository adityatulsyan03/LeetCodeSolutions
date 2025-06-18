class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        bool flag=true;
        for(int i=0;i<nums.size();){
            int j=i+2;
            if(j<nums.size() && nums[j]-nums[i] <= k){
                vector<int> temp(nums.begin()+i,nums.begin()+j+1);
                ans.push_back(temp);
            }
            else{
                flag=false;
                break;
            }
            i=j+1;
        }
        if(!flag){
            vector<vector<int>> t;
            return t;
        }
        return ans;
    }
};