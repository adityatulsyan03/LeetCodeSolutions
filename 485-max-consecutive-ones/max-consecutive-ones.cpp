class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0,c=0;
        for(int i:nums){
            if(i)   c++;
            else    c=0;
            ans=max(ans,c);
        }
        return ans;
    }
};