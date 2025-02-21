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
class FindElements {
    set<int> a;
private:
    void initialize(TreeNode* root, int val) {
        if (!root)
            return;
        root->val = val;
        a.insert(val);
        initialize(root->left, 2 * val + 1);
        initialize(root->right, 2 * val + 2);
    }
public:
    FindElements(TreeNode* root) {
        initialize(root,0);
    }
    
    bool find(int target) {
        if(a.find(target)!=a.end())
            return 1;
        return 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */