class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for(int i:nums){
            cnt[i]++;
            if(cnt[i]==2)
                cnt.erase(i);
        }
        vector<int> ans;
        for(auto [i,j]:cnt)
            ans.push_back(i);
        return ans;
    }
};