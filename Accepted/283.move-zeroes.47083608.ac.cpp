/*
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes
 *
 * Easy (49.49%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * 
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * 
 * 
 * For example, given nums  = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 * 
 * 
 * 
 * Note:
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
			int first = 0,last = 0;
			while(last < nums.size())
			{
				if(nums[last] == 0)
				{
					last++;
				}
				else
				{
					swap(nums[first],nums[last]);
					first++;
					last++;
				}
			}
		}
};
