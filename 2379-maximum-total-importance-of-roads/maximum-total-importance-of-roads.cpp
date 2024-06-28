class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        for(auto edge:roads){
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        long long ans=0,v=1;
        sort(degree.begin(),degree.end());
        for(auto i:degree){
            ans+=i*v;
            v++;
        }
        return ans;
    }
};