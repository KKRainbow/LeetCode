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
    vector<int> pre, in;
    TreeNode* helper(int preStart, int inLeft, int inRight) {
        //cout << preStart << ' ' << inLeft << ' ' << inRight << endl;
        if (inRight - inLeft == 0) return nullptr;
        TreeNode* root = new TreeNode(pre[preStart]);
        int pos;
        for (pos = inLeft; pos < inRight && in[pos] != pre[preStart]; pos++);
        root->left = helper(preStart + 1, inLeft, pos);
        root->right = helper(preStart + (pos - inLeft) + 1, pos + 1, inRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = move(preorder);
        in = move(inorder);
        return helper(0, 0, in.size());
    }
};