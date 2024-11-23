
#include <bits/stdc++.h>
#define ll long long 
#define nl '\n' 
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box){
        int m = box.size();// rows of box 
        int n = box[0].size();// column of box 
        vector<vector<char>> rotated(n, vector<char>(m, '.'));
     // Rotate the box 90 degrees clockwise
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                rotated[j][m - 1 - i] = box[i][j];
            }
        }
    // Apply gravity to the rotated box
        for(int col = 0; col < m; col++){ // Iterate over each column of the rotated matrix.
            int bottom = n - 1;// Initialize 'bottom' to the last row of the column, where stones will fall to.
            for(int row = n - 1; row >= 0;row--){// Iterate from the bottom of the column upwards.
                if(rotated[row][col] == '*'){// If an obstacle '*' is found
                    bottom = row - 1;// reset 'bottom' to the row just above the obstacle( grey color box is the new bottom)
                }else if (rotated[row][col] == '#'){// If a stone '#' is found,
                    rotated[row][col] = '.'; // clear the current position by setting it to '.'
                    //(bcoz we are going to down due to gravity so current postion there is nothing )
                    rotated[bottom][col] = '#'; // place the stone at the 'bottom' position.
                    bottom--; // Move the 'bottom' up one row for the next stone.
                }
            }
        }
        return rotated;
    }
};