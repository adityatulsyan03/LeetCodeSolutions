class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),0);
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;
        int cnt=0;
        for(int i=0;i<queries.size();i++){
            int num=queries[i][0];
            int col=queries[i][1];
            if(mp1[num]==0){
                mp1[num]=col;
                mp2[col]++;
                if(mp2[col]==1){
                    cnt++;
                }
            }
            else{
                if(mp1[num]!=col){
                    if(mp2[col]==0){
                        cnt++;
                    }
                    if(mp2[mp1[num]]==1){
                        cnt--;
                    }
                }
                mp2[mp1[num]]--;
                mp1[num]=col;
                mp2[col]++;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};