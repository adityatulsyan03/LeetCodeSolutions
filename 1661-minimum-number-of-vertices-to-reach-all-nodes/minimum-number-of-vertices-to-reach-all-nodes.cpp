class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> zero_incoming(n,1);
        int m=edges.size();
        for(int i=0;i<m;i++)    zero_incoming[edges[i][1]]=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(zero_incoming[i])   ans.push_back(i);
        }
        return ans;
    }
};