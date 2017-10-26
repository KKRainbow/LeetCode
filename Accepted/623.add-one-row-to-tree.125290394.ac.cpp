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
    int value;
    void dfs(TreeNode* node, int d) {
        if (!node) return;
        d--;
        if (d == 0) {
            auto l = node->left;
            auto r = node->right;
            node->left = new TreeNode(value);
            node->right = new TreeNode(value);
            node->left->left = l;
            node->right->right = r;
        } else {
            dfs(node->left, d);
            dfs(node->right, d);
        }        
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        auto t = new TreeNode(v);
        t->left = root;
        value = v;
        dfs(t, d);
        return t->left;
    }
};