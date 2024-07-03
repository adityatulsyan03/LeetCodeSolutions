class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)
            return 0;
        sort(nums.begin(),nums.end());
        int mn= INT_MAX,n=nums.size();
        mn= min({mn,nums[n-4]-nums[0],nums[n-1]-nums[3],nums[n-2]-nums[2],nums[n-3]-nums[1]});
        return mn;
    }
};