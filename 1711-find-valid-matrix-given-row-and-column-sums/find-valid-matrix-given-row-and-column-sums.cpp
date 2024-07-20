class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(),m=colSum.size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int a=min(rowSum[i],colSum[j]);
                ans[i][j]=a;
                rowSum[i]-=a;
                colSum[j]-=a;

                if(rowSum[i]==0)
                    break;
            }
        }
        return ans;
    }
};