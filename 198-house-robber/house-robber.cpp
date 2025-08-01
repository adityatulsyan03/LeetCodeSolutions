class Solution {
public:
    int rob(vector<int>& nums) {
        int a=nums[0],b=nums[0];
        for(int i=1;i<nums.size();i++){
            int take=nums[i] + ((i>1)?b:0) ;
            int skip=a;
            int c=max(take,skip);
            b=a;
            a=c;
        }
        return a;
    }
};