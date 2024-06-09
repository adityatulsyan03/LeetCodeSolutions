class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size(),prefsum=0;
        unordered_map<int,int> firstocc;
        firstocc[0]=0;
        for(int i=0;i<n;i++){
            prefsum = (prefsum+nums[i])%k;
            if(firstocc.find(prefsum)!=firstocc.end()){
                if(i+1 - firstocc[prefsum] >= 2)  return true;
            }
            else
                firstocc[prefsum]=i+1;
        }
        return false;
    }
};