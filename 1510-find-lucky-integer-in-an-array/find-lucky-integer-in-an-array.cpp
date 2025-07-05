class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> cnt;
        int ans=-1;
        for(int i:arr)  cnt[i]++;
        for(auto [i,j]:cnt) if(i==j)    ans=max(ans,i);
        return ans;
    }
};