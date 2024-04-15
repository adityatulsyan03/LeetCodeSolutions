/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int path) {
            if (!node) return;
            if (!node->left && !node->right) {
                ans += path * 10 + node->val;
                return;
            }
            dfs(node->left, path * 10 + node->val);
            dfs(node->right, path * 10 + node->val);
        };
        
        dfs(root, 0);
        return ans;
    }
};