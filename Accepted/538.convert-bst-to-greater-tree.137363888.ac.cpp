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
    int sum;
    void helper(TreeNode* node) {
        if (!node) return;
        helper(node->right);
        node->val += sum;
        sum = node->val;
        helper(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        helper(root);
        return root;
    }
};