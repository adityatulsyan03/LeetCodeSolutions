class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> cnt;
        for(int i=0;i<roads.size();i++){
            cnt[roads[i][0]]++;
            cnt[roads[i][1]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto [i,j]:cnt)
            pq.push({j,i});
        long long ans=0,v=n;
        while (!pq.empty()) {
            pair<int, int> topElement = pq.top();
            ans+= v*topElement.first;
            v--;
            pq.pop();
        }
        return ans;
    }
};