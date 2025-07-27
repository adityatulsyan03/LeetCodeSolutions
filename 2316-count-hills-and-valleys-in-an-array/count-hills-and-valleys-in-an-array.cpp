class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1])  continue;
            int l=nums[i],r=nums[i];
            for(int j=i-1;j>=0;j--){
                if(nums[j]!=nums[i]){
                    l=nums[j];
                    break;
                }
            }
            for(int j=i+1;j<n;j++){
                if(nums[j]!=nums[i]){
                    r=nums[j];
                    break;
                }
            }
            if(l==nums[i] || r==nums[i])
                continue;
            
            if(l<nums[i] && r<nums[i] || l>nums[i] && r>nums[i]){
                ans++;
            }
        }
        return ans;
    }
};