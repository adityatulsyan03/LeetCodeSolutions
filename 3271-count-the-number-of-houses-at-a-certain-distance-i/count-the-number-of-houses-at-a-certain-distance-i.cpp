class Solution {
private:
    void fillFlyod(vector<vector<int>>& flyod){
        int n=flyod.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                if(i==k)    continue;
                for(int j=0;j<n;j++){
                    if(j==k)    continue;

                    if (flyod[i][k] != INT_MAX && flyod[k][j] != INT_MAX) {
                        int newValue = flyod[i][k] + flyod[k][j];
                        flyod[i][j] = min(flyod[i][j], newValue);
                    }
                }
            }
        }
    }
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        vector<vector<int>> flyod(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n-1;i++){
            flyod[i][i]=0;
            flyod[i][i+1]=1;
            flyod[i+1][i]=1;
        }
        flyod[n-1][n-1]=0;
        if(x!=y){
            flyod[x-1][y-1]=1;
            flyod[y-1][x-1]=1;
        }
        fillFlyod(flyod);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(flyod[i][j]>0)
                    ans[flyod[i][j]-1]++;
            }
        }
        return ans;
    }
};