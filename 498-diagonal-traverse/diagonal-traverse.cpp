class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        if (n == 1 || m == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans.push_back(mat[i][j]);
                }
            }
            return ans;
        }

        int mx = n + m - 2;
        bool f = false;

        for (int b = 0; b <= mx; b++) {
            int i, j;
            if (f) {
                j = min(b, m - 1);
                i = b - j;
                while (i < n && j >= 0) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            } else {
                i = min(b, n - 1);
                j = b - i;
                while (i >= 0 && j < m) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            f = !f;
        }
        return ans;
    }
};