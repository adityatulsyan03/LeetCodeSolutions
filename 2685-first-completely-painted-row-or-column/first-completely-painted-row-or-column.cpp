class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        unordered_map<int,pair<int,int>> pos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos[mat[i][j]]={i,j};
            }
        }
        vector<int> left_row(n,m),left_col(m,n);
        for(int i=0;i<n*m;i++){
            auto p=pos[arr[i]];
            left_row[p.first]--;
            left_col[p.second]--;
            if(left_row[p.first]==0 || left_col[p.second]==0){
                return i;
            }
        }
        return -1;
    }
};