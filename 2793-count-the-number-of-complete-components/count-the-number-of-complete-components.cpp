class Solution {
private:
    pair<int, int> dfs(int node, unordered_map<int, unordered_set<int>>& graph, unordered_set<int>& vis) {
        int nodeCount = 1;
        int edgeCount = 0;

        vis.insert(node);
        for (int neighbor : graph[node]) {
            edgeCount++;
            if (!vis.count(neighbor)) {
                pair<int, int> subResult = dfs(neighbor, graph, vis);
                nodeCount += subResult.first;
                edgeCount += subResult.second;
            }
        }
        return {nodeCount, edgeCount};
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto& i : edges) {
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }

        unordered_set<int> vis;
        int completeCount = 0;

        for (int i = 0; i < n; i++) {
            if (!vis.count(i)) {
                pair<int, int> result = dfs(i, graph, vis);
                int nodes = result.first;
                int edges = result.second/2;
                if (edges == (nodes * (nodes - 1)) / 2) {
                    completeCount++;
                }
            }
        }
        return completeCount;
    }
};