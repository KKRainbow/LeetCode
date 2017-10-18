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
    tuple<int, int> dfs(TreeNode* root) {
        if (!root) {
            return make_tuple(0, 0);
        }
        int leftTilt, rightTilt, leftSum, rightSum;
        tie(leftTilt, leftSum) = dfs(root->left);
        tie(rightTilt, rightSum) = dfs(root->right);
        auto tilt = abs(rightSum - leftSum) + leftTilt + rightTilt;
        auto sum = leftSum + rightSum + root->val;
        return make_tuple(tilt, sum);
    }
public:
    int findTilt(TreeNode* root, int t = 0) {
        return get<0>(dfs(root));
    }
};