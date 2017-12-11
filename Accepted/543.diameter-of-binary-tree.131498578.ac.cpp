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
    // (maxDepth, maxDiameter)
    pair<int, int> helper(TreeNode* node) {
        if (!node) return make_pair(0, 0);
        auto l = helper(node->left);
        auto r = helper(node->right);
        return make_pair(max(l.first, r.first) + 1, max(max(l.second, r.second), l.first + r.first + 1));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        auto r = helper(root);
        return max(r.first, r.second) - 1;
    }
};