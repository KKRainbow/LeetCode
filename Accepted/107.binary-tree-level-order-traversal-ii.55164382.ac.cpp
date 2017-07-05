/*
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii
 *
 * Easy (39.64%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */
#incldue<stack>
#incldue<queue>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		stack<TreeNode*> stk;
		queue<TreeNode*> que;

		dfs(root, 0);
		reverse(res.begin(), res.end());

		return res;
	}
};
