/*
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self
 *
 * Medium (48.66%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0,0]'
 *
 * 
 * Given an array of n integers where n > 1, nums, return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Solve it without division and in O(n).
 * 
 * For example, given [1,2,3,4], return [24,12,8,6].
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (Note: The output array
 * does not count as extra space for the purpose of space complexity analysis.)
 */
class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> res(nums.size());
			res[0] = 1;
			for (int i = 1; i < nums.size();i++)
			{
				res[i] = res[i - 1] * nums[i - 1];
			}
			res[0] = nums[nums.size() - 1];
			for (int i = nums.size() - 2; i > 0; i--)
			{
				res[i] *= res[0];
				res[0] *= nums[i];
			}
			return res;
		}
};
