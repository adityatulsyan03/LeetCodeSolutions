class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int n=nums.size(),sum=0;
        for (int i:nums) {
            sum+=i;
            maxi=max(sum,maxi);
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
};