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
    int ans=0;
    void bfs(TreeNode* root){
        if(root==NULL)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            ans++;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* top=q.front();
                q.pop();
                if(top->right)
                    q.push(top->right);
                if(top->left)
                    q.push(top->left);
            }
        }
    }
public:
    int maxDepth(TreeNode* root) {
        bfs(root);
        return ans;
    }
};