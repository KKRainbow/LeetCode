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
    int result = 0;
    int sum = 0;
    vector<int> prefix;
public:
    void v(TreeNode* node) {
        if (!node) return;
        prefix.push_back(node->val);
        v(node->left);
        v(node->right);
        int s = 0;
        for (auto it = prefix.rbegin(); it != prefix.rend(); it++) {
            s += *it;
            if (s == sum) {
                result++;
            }
        }
        prefix.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        result = 0;
        this->sum = sum;
        v(root);
        return result;
    }
};