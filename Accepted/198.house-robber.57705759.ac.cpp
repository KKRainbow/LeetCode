/*
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber
 *
 * Easy (38.59%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Credits:Special thanks to @ifanchu for adding this problem and creating all
 * test cases. Also thanks to @ts for adding additional test cases.
 */
class Solution {
	public:
		int rob(vector<int>& nums) {
			int res = 0;
			int maxb2= 0, robbed = 0, notrobbed = 0;
			for (int i = 0; i < nums.size(); i++) {
				int nnotrobbed = max(robbed, maxb2);
				int nrobbed = max(notrobbed, maxb2) + nums[i];
				maxb2 = max(max(robbed, notrobbed), maxb2);
				robbed = nrobbed;
				notrobbed = nnotrobbed;
			}
			res += max(robbed, notrobbed);

			return res;
		}
};
