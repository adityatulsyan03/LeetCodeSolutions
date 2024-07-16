class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i:nums)
            cnt[i]++;
        for(auto [i,j]:cnt)
            if(j>1) return i;
        return 0;
    }
};