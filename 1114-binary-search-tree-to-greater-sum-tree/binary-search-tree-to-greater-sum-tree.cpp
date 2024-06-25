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
int sum=0;
private:
    void change(TreeNode* root){
        if(root==NULL)
            return;
        change(root->right);
        sum+=root->val;
        root->val=sum;
        change(root->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        change(root);
        return root;
    }
};