class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;

        dfs(0, 0, n, res, "");

        return res;
    }

    void dfs(int l, int r, int t, vector<string>& res, string s) {
        if(l==r && (l+r) == t*2) {
            res.push_back(s);
            return;
        }

        if(l<t) {
            dfs(l+1, r, t, res, s + '(');
        }

        if(r<l) {
            dfs(l, r+1, t, res, s + ')');
        }

    }
};