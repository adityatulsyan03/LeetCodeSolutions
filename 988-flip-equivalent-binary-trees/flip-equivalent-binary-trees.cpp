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
    bool helper(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr && root2==nullptr)   return true;
        else if((root1 && !root2)||(root2 && !root1))   return false;
        if(root1->val==root2->val){
            return (helper(root1->left, root2->left) && helper(root1->right, root2->right)) ||
                    (helper(root1->left, root2->right) && helper(root1->right, root2->left));
        }else{
            return false;
        }
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return helper(root1,root2);
    }
};