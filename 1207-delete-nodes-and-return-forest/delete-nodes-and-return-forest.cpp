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
    TreeNode* deleteNodes(TreeNode* root, unordered_map<int, int>& del, vector<TreeNode*>& ans) {
        if (root == nullptr) return nullptr;
        
        root->left = deleteNodes(root->left, del, ans);
        root->right = deleteNodes(root->right, del, ans);
        
        if (del[root->val] > 0) {
            if (root->left) ans.push_back(root->left);
            if (root->right) ans.push_back(root->right);
            return nullptr;
        }
        
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int, int> del;
        
        for (int i : to_delete) {
            del[i] = 1;
        }
        
        if (del[root->val] == 0) {
            ans.push_back(root);
        }
        
        deleteNodes(root, del, ans);
        return ans;
    }
};