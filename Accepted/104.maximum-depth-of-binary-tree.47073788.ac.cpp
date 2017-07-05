/*
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree
 *
 * Easy (52.28%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
		int maxDepth(TreeNode* root) {
			if(!root)return 0;
			return max(maxDepth(root->left),maxDepth(root->right)) + 1;
		}
};
