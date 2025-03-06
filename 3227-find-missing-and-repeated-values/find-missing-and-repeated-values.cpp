class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> freq;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                freq[grid[i][j]]++;
            }
        }
        vector<int> ans(2,-1);
        for(int i=1;i<=grid.size()*grid.size();i++){
            if(freq[i]==2){
                ans[0]=i;
            }
            if(freq[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};