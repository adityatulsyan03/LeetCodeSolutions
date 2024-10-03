/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* builder(vector<vector<int>>& grid,int row,int col,int size){
        
        if(size==1){
            return new Node(grid[row][col]==1, true);
        }

        if (isUniform(grid, row, col, size)) {
            return new Node(grid[row][col] == 1, true);
        }

        int half_size = size/2;
        Node* top_left_val = builder(grid,row,col,half_size);
        Node* top_right_val = builder(grid,row,col+half_size,half_size);
        Node* bottom_left_val = builder(grid,row+half_size,col,half_size);
        Node* bottom_right_val = builder(grid,row+half_size,col+half_size,half_size);

        return new Node(true, false, top_left_val, top_right_val, bottom_left_val, bottom_right_val);

    }

    bool isUniform(vector<vector<int>>& grid, int row, int col, int size) {
        int val = grid[row][col];
        for (int i = row; i < row + size; ++i) {
            for (int j = col; j < col + size; ++j) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        return builder(grid,0,0,grid.size());
    }
};