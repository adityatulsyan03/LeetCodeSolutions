class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> cnt;
        for(int i:nums)
            cnt[i]++;
        vector<int> ans;
        for(auto [i,j]:cnt)
            ans.push_back(i);
        nums=ans;
        return cnt.size();
    }
};