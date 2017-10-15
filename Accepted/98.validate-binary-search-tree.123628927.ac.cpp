/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    long long prev = LONG_LONG_MIN;
    bool dfs(TreeNode* root) {
        if (!root) return true;
        if (!dfs(root->left)) return false;
        if (prev >= root->val) return false;
        prev = root->val;
        if (!dfs(root->right)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root);
    }
};