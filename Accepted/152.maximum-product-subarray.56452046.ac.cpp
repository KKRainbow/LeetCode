/*
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray
 *
 * Medium (25.40%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[-2]'
 *
 * 
 * Find the contiguous subarray within an array (containing at least one
 * number) which has the largest product.
 * 
 * 
 * 
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 * 
 */
class Solution {
	int subCalc(vector<int>& nums, int begin, int end)
	{
		//不用考虑零的情况
		if (end <= begin) {
			return INT_MIN;
		}
		if (end - begin == 1) {
			return nums[begin];
		}

		int count = 0, left = INT_MAX, right = INT_MIN;
		int pro = 1;
		for (int i = begin; i < end; i++) {
			if (nums[i] < 0) {
				count++;
				left = min(left, i);
				right = max(right, i);
			}
			pro *= nums[i];
		}

		if (count % 2 == 0) {
			return pro;
		} else {
			int leftpro = 1, rightpro = 1;
			for (int i = begin; i <= left; i++) {
				leftpro *= nums[i];
			}
			for (int i = right; i < end; i++) {
				rightpro *= nums[i];
			}
			cout << left << ' ' << right <<endl;
			pro /= min(abs(leftpro), abs(rightpro));
			pro *= -1;
			return pro;
		}
	}
	public:
	int maxProduct(vector<int>& nums) {
		int res = INT_MIN;
		int begin = 0, end = 0;
		for (end = 0; end < nums.size(); end++) {
			if (nums[end] == 0) {
				res = max(res, subCalc(nums, begin, end));
				res = max(res, 0);
				begin = end + 1;
			}
		}
		cout <<begin<<' '<< end <<endl;
		res = max(res, subCalc(nums, begin, end));
		return res;
	}
};
