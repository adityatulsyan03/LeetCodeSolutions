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
    void revodd(TreeNode* root1,TreeNode* root2,int level){
        if((root1->left==NULL && root1->right==NULL) || (root2->left==NULL && root2->right==NULL))
            return;
        
        if(level%2==0){
            int temp=root1->left->val;
            root1->left->val=root2->right->val;
            root2->right->val=temp;
        }

        revodd(root1->left,root2->right,level+1);
        revodd(root1->right,root2->left,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        revodd(root,root,0);
        return root;
    }
};