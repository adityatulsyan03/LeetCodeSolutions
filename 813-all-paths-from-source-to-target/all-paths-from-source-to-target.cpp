class Solution {
private:
    void solve(vector<vector<int>>& ans,vector<int> temp,vector<vector<int>>& graph,int curr){
        if (curr == graph.size() - 1) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < graph[curr].size(); i++) {
            temp.push_back(graph[curr][i]);
            solve(ans, temp, graph, graph[curr][i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        solve(ans,temp,graph,0);
        return ans;
    }
};