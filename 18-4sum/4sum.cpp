class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()<4)
            return ans;
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                if(j==i)    continue;
                int left=j+1,right=nums.size()-1;
                while(left<right){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        --right;
                    }
                    else if(sum<target)
                        left++;
                    else
                        right--;
                }
            }
        }
        set<vector<int>> uniqueQuadruplets(ans.begin(), ans.end());
        ans.assign(uniqueQuadruplets.begin(), uniqueQuadruplets.end());
        
        return ans;
    }
};