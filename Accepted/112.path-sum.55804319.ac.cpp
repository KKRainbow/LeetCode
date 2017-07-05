/*
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum
 *
 * Easy (33.73%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]\n1'
 *
 * 
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 */
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
		bool hasPathSum(TreeNode* root, int sum) {
			if (!root) {
				return false;
			}
			if (!root->right && !root->left) {
				return sum - root->val == 0;
			} else {
				int tmp = sum - root->val;
				bool left = root->left ? hasPathSum(root->left, tmp) : false;
				bool right = root->right ? hasPathSum(root->right, tmp) : false;
				return left || right;
			}
		}
};
