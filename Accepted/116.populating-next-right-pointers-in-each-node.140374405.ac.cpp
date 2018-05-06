/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        auto os = root;
        while (os && os->left) {
            auto linkStart = os;
            while (linkStart) {
                linkStart->left->next = linkStart->right;
                linkStart->right->next = linkStart->next ? linkStart->next->left : nullptr;
                linkStart = linkStart->next;
            }
            os = os->left;
        }
    }
};
