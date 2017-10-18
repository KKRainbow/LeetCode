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
    char str[100];
    unsigned int sum;
    void dfs(TreeNode* node, int level = 0, bool flag = false) {
        if (!node && !flag) {
            str[level] = '\0';
            //cout << str << endl;
            sum += atoi(str);
            return;
        } else if (!node) {
            return;
        }
        str[level] = node->val + '0';
        dfs(node->left, level + 1, node->left || node->right);
        dfs(node->right, level + 1, node->left || node->right);
    }
public:
    int sumNumbers(TreeNode* root) {
        new (str)char[100];
        sum = 0;
        dfs(root);
        return sum / 2;
    }
};