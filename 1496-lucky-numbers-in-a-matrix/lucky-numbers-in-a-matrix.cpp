class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> cnt;
        for(int i=0;i<matrix.size();i++){
            int mn=INT_MAX;
            for(int j=0;j<matrix[0].size();j++){
                mn=min(matrix[i][j],mn);
            }
            cnt[mn]++;
        }
        for(int i=0;i<matrix[0].size();i++){
            int mx=0;
            for(int j=0;j<matrix.size();j++){
                mx=max(matrix[j][i],mx);
            }
            cnt[mx]++;
        }
        vector<int> ans;
        for(auto [i,j]:cnt)
            if(j>1) ans.push_back(i);
        return ans;
    }
};