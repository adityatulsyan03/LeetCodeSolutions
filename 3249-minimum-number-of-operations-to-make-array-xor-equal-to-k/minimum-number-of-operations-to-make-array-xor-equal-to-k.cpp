class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<20;i++){
            int x=0;
            for(auto j:nums){
                int bit=(1<<i)&j;
                x=x^bit;
            }
            
            int xbit=(1<<i)&k;
            if(xbit!=x)
                ans++;
        }
        return ans;
    }
};