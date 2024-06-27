class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> cnt;
        for(int i=0;i<2;i++){
            cnt[edges[i][0]]++;
            cnt[edges[i][1]]++;
        }
        int ans=0;
        for(auto [i,j]:cnt)
            if(j==2)    ans=i;
        return ans;
    }
};