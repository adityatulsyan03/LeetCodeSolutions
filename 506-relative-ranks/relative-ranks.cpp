class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sorted=score;
        sort(sorted.rbegin(),sorted.rend());
        unordered_map<int,string> rank;
        for(int i=0;i<score.size();i++){
            if (i == 0) rank[sorted[i]] = "Gold Medal";
            else if (i == 1) rank[sorted[i]] = "Silver Medal";
            else if (i == 2) rank[sorted[i]] = "Bronze Medal";
            else rank[sorted[i]] = to_string(i + 1);
        }
        vector<string> ans;
        for(int i:score){
            ans.push_back(rank[i]);
        }
        return ans;
    }
};