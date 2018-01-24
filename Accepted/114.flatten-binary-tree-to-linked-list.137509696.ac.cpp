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
    TreeNode* helper(TreeNode* node) {
        if (!node) return nullptr;
        auto tail = helper(node->left);
        auto rightTail = helper(node->right);
        auto res = node;
        if (tail) {
            tail->right = node->right;
            node->right = node->left;
            res = tail;
        }
        if (rightTail) {
            res = rightTail;
        }
        node->left = nullptr;
        return res;
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};