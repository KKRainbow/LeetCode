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
    map<int, int> minPos, maxPos;
    void dfs(TreeNode* root, int level, int pos) {
        if (!root) return;
        try {
            if (minPos.at(level) > pos)
                minPos[level] = pos;
        } catch(...) {
            minPos[level] = pos;
        }
        try {
            if (maxPos.at(level) < pos)
                maxPos[level] = pos;
        } catch(...) {
            maxPos[level] = pos;
        }
        dfs(root->left, level + 1, 2 * pos);
        dfs(root->right, level + 1, 2 * pos + 1);
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        int maxWidth = INT_MIN;
        for (auto& mi: minPos) {
            
            try {
                maxWidth = max(maxWidth, maxPos.at(mi.first) - mi.second);
            }
            catch(...) {}
        }
        return maxWidth + 1;
    }
};