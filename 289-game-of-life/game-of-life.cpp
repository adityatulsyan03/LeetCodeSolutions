class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> ans = board;  // Copy of the original board
        
        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},         {0, 1},
            {1, -1}, {1, 0}, {1, 1}
        };
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int liveNeighbors = 0;
                
                for(auto dir : directions) {
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    
                    if(ni >= 0 && ni < m && nj >= 0 && nj < n && board[ni][nj] == 1) {
                        liveNeighbors++;
                    }
                }
                
                if(board[i][j] == 1) {
                    if(liveNeighbors < 2 || liveNeighbors > 3) {
                        ans[i][j] = 0;
                    }
                } else {
                    if(liveNeighbors == 3) {
                        ans[i][j] = 1;
                    }
                }
            }
        }
        
        board = ans;
    }
};
