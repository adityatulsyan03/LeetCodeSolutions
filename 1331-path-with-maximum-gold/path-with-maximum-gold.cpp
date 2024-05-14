class Solution {
private:
    int mx=0;
    void getsum(int i,int j,vector<vector<int>>& grid, int ans,vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j]==0)
            return;

        ans += grid[i][j];
        vis[i][j] = true;
        mx = max(mx, ans);
        getsum(i+1,j,grid,ans,vis);
        getsum(i-1,j,grid,ans,vis);
        getsum(i,j+1,grid,ans,vis);
        getsum(i,j-1,grid,ans,vis);
        vis[i][j]=false;
        ans-=grid[i][j];
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                getsum(i,j,grid,0,vis);
            }
        }
        return mx;
    }
};