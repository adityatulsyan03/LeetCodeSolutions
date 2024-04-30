class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,prefsum=0;
        unordered_map<int,int> freq;
        freq[0]=1;
        for(auto e:nums){
            prefsum+=e;

            if(freq.find(prefsum-k) !=freq.end())
                ans+=freq[prefsum-k];
            
            freq[prefsum]++;
        }

        return ans;
    }
};