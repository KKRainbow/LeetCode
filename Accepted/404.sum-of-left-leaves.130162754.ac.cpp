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
    void helper(TreeNode* parent, TreeNode* self) {
        if (self && self == parent->left && !self->left && !self->right) {
            sum += self->val;
        }
        if (self) {
            helper(self, self->left);
            helper(self, self->right);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        sum = 0;
        helper(root, root->left);
        helper(root, root->right);
        return sum;
    }
};