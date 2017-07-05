/*
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum
 *
 * Hard (25.82%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a binary tree, find the maximum path sum.
 * 
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * 
 * For example:
 * Given the below binary tree,
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 
 * 
 * Return 6.
 * 
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

	int aux(struct TreeNode* root, int* subMax)
	{
		if (!root) {
			*subMax = 0;
			return 0;
		}

		int lpath, rpath, lsum, rsum;
		lsum = aux(root->left, &lpath);
		rsum = aux(root->right, &rpath);

		if (lpath < 0) lpath = 0;
		if (rpath < 0) rpath = 0;
		*subMax = max(lpath, rpath) + root->val;

		int sum = lpath + rpath + root->val;

		if (root->left) sum = max(sum, lsum);
		if (root->right) sum = max(sum, rsum);
		return sum;
	}

	public:
	int maxPathSum(TreeNode* root) {
		int tmp;
		return aux(root, &tmp);
	}
};


