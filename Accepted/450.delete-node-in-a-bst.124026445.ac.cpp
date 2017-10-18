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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* rootParent = root;
        TreeNode** parent = &rootParent;
        TreeNode* node = root;
        while (node && node->val != key) {
            if (key < node->val) {
                parent = &(node->left);
                node = node->left;
            } else {
                parent = &(node->right);
                node = node->right;
            }
        }
        if (!node) return root;
        
        while (node->left || node->right) {
            if (node->left) {
                auto tmp =  node->left->right;
                *parent = node->left;
                node->left->right = node;
                node->left = tmp;
                parent = &((*parent)->right);
            } else {
                auto tmp = node->right->left;
                *parent = node->right;
                node->right->left = node;
                node->right = tmp;
                parent = &((*parent)->left);
            }
        }
        delete *parent;
        *parent = nullptr;
        return rootParent;
    }
};