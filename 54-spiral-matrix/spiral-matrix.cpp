class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int mni=0,mnj=0,mxi=matrix.size()-1,mxj=matrix[0].size()-1;
        vector<int> ans;
        while(mni<=mxi && mnj<=mxj){
            for(int i=mnj;i<=mxj;i++)
                ans.push_back(matrix[mni][i]);
            mni++;
            for(int i=mni;i<=mxi;i++)
                ans.push_back(matrix[i][mxj]);
            mxj--;
            if(mni<=mxi){
                for(int i=mxj;i>=mnj;i--)
                    ans.push_back(matrix[mxi][i]);
                mxi--;
            }
            if(mnj<=mxj){
                for(int i=mxi;i>=mni;i--)
                    ans.push_back(matrix[i][mnj]);
                mnj++;
            }
        }
        return ans;
    }
};