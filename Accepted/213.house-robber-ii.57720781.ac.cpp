/*
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii
 *
 * Medium (33.75%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * Note: This is an extension of House Robber.
 * 
 * After robbing those houses on that street, the thief has found himself a new
 * place for his thievery so that he will not get too much attention. This
 * time, all houses at this place are arranged in a circle. That means the
 * first house is the neighbor of the last one. Meanwhile, the security system
 * for these houses remain the same as for those in the previous street. 
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @Freezen for adding this problem and creating all
 * test cases.
 */
class Solution {
	int r(vector<int>& nums, int start) {
		int robbed = 0, notrobbed = 0;
		for (int n = 0, i = start; n < nums.size() - 1; n++, i = (i + 1) % nums.size()) {
			int nnotrobbed = max(robbed, notrobbed);
			int nrobbed = notrobbed + nums[i];
			robbed = nrobbed;
			notrobbed = nnotrobbed;
		}

		return max(robbed, notrobbed);;
	}
	public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res = max(res, r(nums, i));
		}
		return res;
	}
};
