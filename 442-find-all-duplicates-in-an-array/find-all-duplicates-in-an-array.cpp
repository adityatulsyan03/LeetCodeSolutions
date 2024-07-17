class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i:nums)
            cnt[i]++;
        vector<int> ans;
        for(auto [i,j]:cnt)
            if(j>1) ans.push_back(i);
        return ans;
    }
};