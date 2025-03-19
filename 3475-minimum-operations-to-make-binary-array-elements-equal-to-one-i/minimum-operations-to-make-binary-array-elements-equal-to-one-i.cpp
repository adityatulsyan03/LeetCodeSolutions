class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0,i=0;
        for(;i<nums.size()-2;i++){
            if(nums[i]==0){
                nums[i]=nums[i]?0:1;
                nums[i+1]=nums[i+1]?0:1;
                nums[i+2]=nums[i+2]?0:1;
                ans++;
            }
        }
        return nums[i-1]&&nums[i]&&nums[i+1]?ans:-1;
    }
};