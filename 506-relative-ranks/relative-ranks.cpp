class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> s=score;
        sort(s.rbegin(),s.rend());
        unordered_map<int,string> m;
        for(int i=0;i<s.size();i++){
            if (i == 0) m[s[i]] = "Gold Medal";
            else if (i == 1) m[s[i]] = "Silver Medal";
            else if (i == 2) m[s[i]] = "Bronze Medal";
            else m[s[i]] = to_string(i + 1);
        }
        vector<string> f;
        for(int i:score){
            f.push_back(m[i]);
        }
        return f;
    }
};