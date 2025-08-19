class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,curr=0;
        for(int i:nums){
            if(i==0){
                curr++;
            }else{
                ans+=(curr*(curr+1))/2;
                curr=0;
            }
        }
        ans+=(curr*(curr+1))/2;
        return ans;
    }
};