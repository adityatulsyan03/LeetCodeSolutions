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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,bool> hasParent;
        for(auto num:descriptions){
            int pval=num[0],cval=num[1],isLeft=num[2];
            TreeNode *par = nullptr, *chi = nullptr;

            if(mp.find(pval)==mp.end())
                par=new TreeNode(pval);
            else
                par=mp[pval];
            
            if(mp.find(cval)==mp.end())
                chi=new TreeNode(cval);
            else
                chi=mp[cval];

            if(isLeft)
                par->left=chi;
            else
                par->right=chi;
            
            hasParent[cval]=true;
            mp[cval]=chi;
            mp[pval]=par;
        }
        TreeNode* rootNode = nullptr;
        for(auto& [i,j]:mp){
            if(!hasParent[i])
                rootNode=j;
        }
        return rootNode;
    }
};