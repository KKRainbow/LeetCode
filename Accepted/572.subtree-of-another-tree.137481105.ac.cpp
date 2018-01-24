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
    bool helper(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true;
        }
        if ((s&&!t) || (!s&&t) || s->val != t->val) {
            return false;
        }
        return helper(s->left, t->left) && helper(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (helper(s, t)) {
            return true;
        }
        if (!s && t) {
            return false;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};