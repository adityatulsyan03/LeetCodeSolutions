class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row, col, subgrid;

            for (int j = 0; j < 9; j++) {
                if (row.find(board[i][j]) != row.end() && board[i][j] != '.')
                    return false;
                row[board[i][j]] = 1;

                if (col.find(board[j][i]) != col.end() && board[j][i] != '.')
                    return false;
                col[board[j][i]] = 1;

                int subgridRow = 3 * (i / 3);
                int subgridCol = 3 * (i % 3);
                if (subgrid.find(board[subgridRow + j / 3][subgridCol + j % 3]) != subgrid.end() && board[subgridRow + j / 3][subgridCol + j % 3] != '.')
                    return false;
                subgrid[board[subgridRow + j / 3][subgridCol + j % 3]] = 1;
            }
        }

        return true;
    }
};