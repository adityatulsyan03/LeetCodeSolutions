class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mn_i=grid[0].size(),mx_i=-1,mn_j=grid[0].size(),mx_j=-1,n=grid.size(),m=grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    if (mn_i > i) mn_i = i;
                    if (mx_i < i) mx_i = i;
                    if (mn_j > j) mn_j = j;
                    if (mx_j < j) mx_j = j;
                }
            }
        }
        if (mn_i > mx_i || mn_j > mx_j) {
            return 0;
        }
        int i = mx_i - mn_i + 1;
        int j = mx_j - mn_j + 1;
        
        return i*j;
    }
};