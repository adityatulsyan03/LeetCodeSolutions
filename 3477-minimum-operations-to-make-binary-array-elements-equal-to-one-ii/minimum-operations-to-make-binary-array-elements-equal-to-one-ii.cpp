class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(((ans%2==0 && nums[i]==0) || (ans%2 && nums[i]))){
                ans++;
            }
        }
        return ans;
    }
};