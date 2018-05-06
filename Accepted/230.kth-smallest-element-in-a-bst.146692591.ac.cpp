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
    int helper(TreeNode* root, int k, int& nodeCount) {
        nodeCount = 0;
        if (!root) {
            return 0;
        }
        int ln;
        auto tmp = helper(root->left, k, ln);
        nodeCount = ln + 1;
        int res = 0;
        if (ln >= k) {
            return tmp;
        } else if (ln + 1 == k) {
            return root->val;
        } else {
            int rn = 0;
            res = helper(root->right, k - ln - 1, rn);
            nodeCount += rn;
            return res;
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ln;
        return helper(root, k, ln);
    }
};
