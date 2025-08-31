class Solution {
private:
    bool issafe(int row,int col,vector<vector<char>>& board, char n){
        for(int i=0;i<9;i++){
            if(board[i][col]==n)
                return 0;
            if(board[row][i]==n)
                return 0;
            if(board[3*(row/3) + i/3][3*(col/3)+ i%3]==n)
                return 0;
        }
        return 1;
    }
    bool solve(vector<vector<char>>& board){
        int n=board.size();
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    for(char val='1';val<='9';val++){
                        if(issafe(row,col,board,val)){
                            board[row][col]=val;
                            bool next=solve(board);
                            if(next)
                                return true;
                            else
                                board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};