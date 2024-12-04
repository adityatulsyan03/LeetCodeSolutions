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
    bool checkSame(TreeNode* first, TreeNode* second){
        if(first==nullptr && second==nullptr)   return true;
        if(first==nullptr && second!=nullptr || 
            first!=nullptr && second==nullptr)  return false;
        if(first->val==second->val)
            return checkSame(first->right,second->left) && checkSame(first->left,second->right);
        else
            return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr || 
            root->right==nullptr && root->left==nullptr )   return true;
        if((root->right==nullptr && root->left!=nullptr) || 
            (root->right!=nullptr && root->left==nullptr))  return false;
        return checkSame(root->right, root->left);
    }
};