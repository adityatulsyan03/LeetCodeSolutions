class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0,n=nums.size(),prefsum=0;
        unordered_map<int,int> Occ;
        Occ[0]=1;
        for(int i=0;i<n;i++){
            prefsum=(prefsum+nums[i]%k+k)%k;
            ans += Occ[prefsum];
            Occ[prefsum]++;
        }
        return ans;
    }
};