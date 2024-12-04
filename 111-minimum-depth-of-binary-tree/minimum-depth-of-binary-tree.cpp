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
    void height(TreeNode* root,int& ans,int depth){
        if (root == nullptr) return;
        if(root->right==nullptr && root->left==nullptr)
            ans=min(ans,depth);
        else{
            if(root->right)
                height(root->right,ans,depth+1);
            if(root->left)
                height(root->left,ans,depth+1);
        }
    }
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)   return 0;
        int ans=INT_MAX;
        height(root,ans,1);
        return ans;
    }
};