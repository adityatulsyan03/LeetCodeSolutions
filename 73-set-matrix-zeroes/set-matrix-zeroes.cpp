class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> cnt_i,cnt_j;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    cnt_i[i]++;
                    cnt_j[j]++;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(cnt_i[i]>0 || cnt_j[j]>0)
                    matrix[i][j]=0;
            }
        }
    }
};