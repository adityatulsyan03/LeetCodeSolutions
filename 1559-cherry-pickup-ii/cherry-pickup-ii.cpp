class Solution {
private:
    int helper(int r, int c, vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp){
        if(j1<0 || j2<0 || j1>=c || j2>=c || i>=r)
            return 0;
        
        if(i==r-1){
            if(j1==j2){
                return grid[i][j1];
            }else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];

        int mx=0;

        int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

        mx = max(mx, val + helper(r, c, grid, i+1, j1, j2,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1, j2+1,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1, j2-1,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1+1, j2,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1+1, j2+1,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1+1, j2-1,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1-1, j2,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1-1, j2+1,dp));
        mx = max(mx, val + helper(r, c, grid, i+1, j1-1, j2-1,dp));

        return dp[i][j1][j2]=mx;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return helper(r,c,grid,0,0,c-1,dp);
    }
};