class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total=accumulate(nums.begin(),nums.end(),0LL);
        int ans=0;
        long long curr_sum=0;
        for(int i=0;i<nums.size()-1;i++){
            curr_sum+=nums[i];
            total-=nums[i];
            if(curr_sum>=total)   ans++;
        }
        return ans;
    }
};