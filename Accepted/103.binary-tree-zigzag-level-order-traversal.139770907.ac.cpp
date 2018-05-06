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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if (!root) {
                return {};
            }
            // true is left to right
            bool direct = true;
            deque<TreeNode*> q(1, root);
            vector<vector<int>> result;
            while (!q.empty()) {
                auto curSize = q.size();
                vector<int> level;
                for (int i = 0; i < curSize; i++) {
                    if (direct) {
                        auto cur = q.front();
                        q.pop_front();
                        level.push_back(cur->val);
                        if (cur->left) {
                            q.push_back(cur->left);
                        }
                        if (cur->right) {
                            q.push_back(cur->right);
                        }
                    } else {
                        auto cur = q.back();
                        q.pop_back();
                        level.push_back(cur->val);
                        if (cur->right) {
                            q.push_front(cur->right);
                        }
                        if (cur->left) {
                            q.push_front(cur->left);
                        }
                    }
                }

                result.push_back(level);
                direct = !direct;
            }
            return result;
        }
};
