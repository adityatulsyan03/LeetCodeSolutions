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
private:
    TreeNode* erase(TreeNode* root) {
        if (!root) return nullptr;
        root->left = erase(root->left);
        root->right = erase(root->right);
        if (root->val == 0 && !root->left && !root->right) {
            delete root;
            return nullptr;
        }
        return root;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return erase(root);
    }
};