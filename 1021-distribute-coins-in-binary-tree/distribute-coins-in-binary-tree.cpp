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
int step = 0;
private:
    void cnt(TreeNode* root){
        if(root==NULL || (root->right == NULL && root->left == NULL) )
            return;

        cnt(root->left);
        cnt(root->right);

        if(root->left)  root->left->val--;
        if(root->right) root->right->val--;
        if(root->right == NULL){
            int lv = root->left->val;
            if(lv<0)
                step+= (-1)*lv;
            if(lv>0)
                step += lv;
            root->val += lv;
            // cout<<"right null "<<"step: "<<step<<"root: "<<root->val<<endl;
        }
        else if(root->left == NULL){
            int rv = root->right->val;

            if(rv<0)
                step+= (-1)*rv;
            if(rv>0)
                step += rv;
            root->val += rv;
            // cout<<"left null "<<"step: "<<step<<"root: "<<root->val<<endl;
        }
        else{
            int lv = root->left->val;
            int rv = root->right->val;
            if(lv<0 && rv<0){
                step += (-1)*lv + (-1)*rv;
            }
            if(lv<0 && rv>=0){
                step += (-1)*lv + rv;
            }
            if(lv>=0 && rv<0){
                step += lv + (-1)*rv;
            }
            if(lv>=0 && rv>=0){
                step += lv + rv;
            }
            root-> val += lv + rv;
            // cout<<"no null "<<"step: "<<step<<"root: "<<root->val<<endl;
        }
    }
public:
    int distributeCoins(TreeNode* root) {
        cnt(root);
        return step;      
    }
};