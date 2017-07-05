/*
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii
 *
 * Medium (43.00%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * 
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * 
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * 
 * Example 1:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * 
 * Example 2:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
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
	template <class T, class T1>
T maxs(T a, T1 b)
{
	return max(a, b);
}

	template <class T, class... TS>
T maxs(T a, TS... ts) 
{
	return maxs(a, maxs<TS...>(ts...));
}

class Solution {
	int res = 0;
	void r(TreeNode* root, pair<int, int>& p)
	{
		if (!root) {
			p = make_pair(0, 0);
			return;
		}
		pair<int, int> lpair, rpair;
		r(root->left, lpair);
		r(root->right, rpair);

		int robbed = rpair.second + lpair.second + root->val;
		int notrobbed = maxs(lpair.first, lpair.second) + maxs(rpair.first, rpair.second);

		p = make_pair(robbed, notrobbed);
	}
	public:
	int rob(TreeNode* root) {
		auto p = make_pair(0, 0);
		r(root, p);
		return maxs(p.first, p.second);
	}
};
