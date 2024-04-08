/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const bool __boost = [](){
    cin.tie(nullptr);
    cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);
}();
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL)
            return NULL;
        if(original==target)
            return cloned;
        TreeNode* result = getTargetCopy(original->left,cloned->left, target);
        if(result)
            return result;
        return getTargetCopy(original->right,cloned->right,target);
    }
};