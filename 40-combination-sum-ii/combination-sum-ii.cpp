class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& temp, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(i>start && candidates[i-1]==candidates[i])   continue;
            temp.push_back(candidates[i]);
            helper(ans, temp, candidates, target - candidates[i], i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        helper(ans, temp, candidates, target, 0);
        return ans;
    }
};