class Solution {
private:
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited, string word, int wordIndex,int i,int j){
        if(i<0 || i>=visited.size() || j<0 || j>= visited[0].size() || visited[i][j] || board[i][j] != word[wordIndex])
            return false;

        if(wordIndex == word.size()-1)
            return true;
        
        visited[i][j] = true;

        bool found = dfs(board, visited, word, wordIndex + 1, i + 1, j) ||
                     dfs(board, visited, word, wordIndex + 1, i - 1, j) ||
                     dfs(board, visited, word, wordIndex + 1, i, j + 1) ||
                     dfs(board, visited, word, wordIndex + 1, i, j - 1);

        visited[i][j] = false;
        return found;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        if (rows == 0) return false;
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j]==word[0] && dfs(board, visited, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }
};