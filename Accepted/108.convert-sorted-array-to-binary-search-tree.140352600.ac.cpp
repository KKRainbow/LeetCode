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
    void helper(vector<int>& nums, int start, int end, TreeNode **root) {
        if (start > end) return;
        int mid = (start + end) / 2;
        *root = new TreeNode(nums[mid]);
        helper(nums, start, mid - 1, &((*root)->left));
        helper(nums, mid + 1, end, &((*root)->right));
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        helper(nums, 0, nums.size() - 1, &root);
        return root;
    }
};
