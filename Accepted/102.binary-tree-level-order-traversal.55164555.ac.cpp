/*
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal
 *
 * Medium (39.10%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
	vector<vector<int>> res;
	void dfs(TreeNode* root, int depth) 
	{
		if (!root) {
			return;
		}
		if (depth >= res.size()) {
			res.resize(depth + 1);
		}
		res[depth].push_back(root->val);

		dfs(root->left, depth + 1);
		dfs(root->right,  depth + 1);
	}
	public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		stack<TreeNode*> stk;
		queue<TreeNode*> que;

		dfs(root, 0);

		return res;
	}
};
