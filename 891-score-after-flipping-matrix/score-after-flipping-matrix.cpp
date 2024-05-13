class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0){
                for(int j=0;j<grid[i].size();j++){
                    grid[i][j] = grid[i][j]==1?0:1;
                }
            }
        }
        for(int i=0;i<grid[0].size();i++){
            int c=0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]==0)
                    c++;
            }
            if((c*2)>grid.size()){
                for(int j=0;j<grid.size();j++){
                    grid[j][i] = grid[j][i]==1?0:1;
                }   
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    ans+= pow(2,grid[i].size()-j-1);
                }
            }
        }
        return ans;
    }
};