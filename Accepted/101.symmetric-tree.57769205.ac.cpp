/*
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree
 *
 * Easy (38.38%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3]  is not:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
	vector<int> a1, a2;
	void houxu1(TreeNode* root)
	{
		if (!root) {
			a1.push_back(INT_MAX);
			return;
		}
		houxu1(root->left);
		houxu1(root->right);
		a1.push_back(root->val);
	}
	void houxu2(TreeNode* root)
	{
		if (!root) {
			a2.push_back(INT_MAX);
			return;
		}
		houxu2(root->right);
		houxu2(root->left);
		a2.push_back(root->val);
	}
	public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}
		houxu1(root->left);
		houxu2(root->right);
		if (a1.size() != a2.size()) {
			return false;
		} else {
			for (int i = 0 ; i < a1.size(); i++) {
				//cout << a1[i] << ' ' << a2[i] << endl;
				if (a1[i] != a2[i]) {
					return false;
				}
			}
		}
		return true;
	}
};
