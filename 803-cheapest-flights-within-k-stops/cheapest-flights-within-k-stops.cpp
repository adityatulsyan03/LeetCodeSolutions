class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> paths;
        for(int i=0;i<flights.size();i++){
            paths[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }

        vector<vector<int>> minCost(n, vector<int>(k + 2, INT_MAX));
        minCost[src][0] = 0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,src,0});

        while(!pq.empty()){
            auto [cost,node,stops]=pq.top();
            pq.pop();

            if(node == dst) return cost;

            if(stops>k) continue;

            for(auto& [nextNode,nextCost]:paths[node]){
                int newCost = cost + nextCost;
                if (newCost < minCost[nextNode][stops + 1]) {
                    minCost[nextNode][stops + 1] = newCost;
                    pq.push({newCost, nextNode, stops + 1});
                }
            }
        }

        return -1;
    }
};