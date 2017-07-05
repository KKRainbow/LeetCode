/*
 * [235] Lowest Common Ancestor of a Binary Search Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
 *
 * Easy (38.81%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[2,1]\nnode with value 2\nnode with value 1'
 *
 * 
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of
 * two given nodes in the BST.
 * 
 * 
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes v and w as the lowest node in T that has both v
 * and w as descendants (where we allow a node to be a descendant of
 * itself).”
 * 
 * 
 * 
 * ⁠       _______6______
 * ⁠      /              \
 * ⁠   ___2__          ___8__
 * ⁠  /      \        /      \
 * ⁠  0      _4       7       9
 * ⁠        /  \
 * ⁠        3   5
 * 
 * 
 * 
 * For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
 * example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
 * itself according to the LCA definition.
 */
#include<cstdlib>
#include<map>
using namespace std;

class Solution {
	TreeNode* res = nullptr;
	int depth = 0;
	TreeNode* p;
	TreeNode* q;
	pair<bool,bool> hasChild(TreeNode* root, int depth = 0)
	{
		if(!root)return make_pair(false,false);
		else
		{
			auto pleft = hasChild(root->left,depth+1);
			auto pright = hasChild(root->right,depth + 1);
			bool hasp = pleft.first || pright.first || root == p;
			bool hasq = pleft.second || pright.second || root == q;

			if(hasp && hasq && this->depth <= depth)
			{
				this->depth = depth;
				this->res = root;
			}
			return make_pair(hasp,hasq);
		}
	}
	public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		this->p = p;
		this->q = q;
		hasChild(root);
		return this->res;
	}
};

