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
    int find(TreeNode*& ans,TreeNode* root,int n,int& mx){
        if(!root)
            return n-1;
        
        int l = find(ans,root->left,n+1,mx);
        int r = find(ans,root->right,n+1,mx);

        int leafD = max(l,r);
        mx = max(mx,leafD);

        if(mx == l && l==r)
            ans = root;

        return leafD;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans=NULL;
        int mx=-1;
        find(ans,root,0,mx);
        return ans;
    }
};