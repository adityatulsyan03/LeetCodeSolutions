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
    void make(TreeNode* root,unordered_map<int,pair<int,int>>& par_chi,int r){
        
        if(par_chi.find(r)!= par_chi.end()){

            if(par_chi[r].first!=0){
                root->left=new TreeNode(par_chi[r].first);
                make(root->left,par_chi,par_chi[r].first);
            }
            else{
                root->left=NULL;
            }
            if(par_chi[r].second!=0){
                root->right=new TreeNode(par_chi[r].second);
                make(root->right,par_chi,par_chi[r].second);
            }
            else{
                root->right=NULL;
            }

        }

    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>> par_chi;
        vector<int> v(100001,-1);
        for(int i=0;i<descriptions.size();i++){
            int par=descriptions[i][0];
            int chi=descriptions[i][1];
            if(v[par]!=2)
                v[par]=1;
            if(descriptions[i][2]==1){
                par_chi[par].first=chi;
                v[chi]=2;
            }
            else{
                par_chi[par].second=chi;
                v[chi]=2;
            }
        }
        // for(auto [i,j]:par_chi){
        //     cout<<i<<" "<<j.first<<" "<<j.second<<endl;
        // }
        int r;
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                r=i;
                break;
            }
        }
        TreeNode* root=new TreeNode(r);
        make(root,par_chi,r);
        return root;
    }
};