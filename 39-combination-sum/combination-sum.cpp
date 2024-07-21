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
            temp.push_back(candidates[i]);
            helper(ans, temp, candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, candidates, target, 0);
        return ans;
    }
};