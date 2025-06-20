class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=1,s=nums[0],e=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]-s>k){
                cnt++;
                s=nums[i];
            }
        }
        return cnt;
    }
};