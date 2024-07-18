class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int,int> cnt;
        int prefSum=0;
        cnt[0]=1;
        for(int i:nums){
            prefSum+=i;

            if(cnt.find(prefSum-k)!=cnt.end())
                ans+=cnt[prefSum-k];
            
            cnt[prefSum]++;
        }
        return ans;
    }
};