/*
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii
 *
 * Medium (31.20%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1...n.
 * 
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
	vector<TreeNode*> genTree(int start, int end)
	{
		vector<TreeNode*> res;
		if (end - start == 1) {
			res.push_back(new TreeNode(start));
			return (res);
		} else if (end - start == 0) {
			res.push_back(nullptr);
			return (res);
		}
		for (int i = start; i < end; i++) {
			auto left = genTree(start, i);
			auto right = genTree(i + 1, end);
			for (auto l : left) {
				for (auto r : right) {
					auto node = new TreeNode(i);
					node->left = l;
					node->right = r;
					res.push_back(node);
				}
			}
		}
		return (res);
	}
	public:
	vector<TreeNode*> generateTrees(int n) {
		if (!n) {
			return {};
		}
		vector<TreeNode*> res = genTree(1, n + 1);
		return res;
	}
};
