class Solution {
private:
    void solve(vector<vector<int>>& ans,vector<int> temp,vector<vector<int>>& graph,int curr){
        temp.push_back(curr);
        if (curr == graph.size() - 1) {
            ans.push_back(temp);
        }
        for (auto i:graph[curr]) {
            solve(ans, temp, graph, i);
        }
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans,temp,graph,0);
        return ans;
    }
};