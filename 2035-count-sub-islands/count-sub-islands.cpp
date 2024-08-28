class Solution {
private:
    void helper(vector<vector<int>>& grid2,int i,int j){
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || grid2[i][j]==0)
            return;
        grid2[i][j]=0;
        helper(grid2,i+1,j);
        helper(grid2,i-1,j);
        helper(grid2,i,j+1);
        helper(grid2,i,j-1);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0,n=grid1.size(),m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==0 && grid2[i][j]==1){
                    helper(grid2,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    ans++;
                    helper(grid2,i,j);
                }
            }
        }
        return ans;
    }
};