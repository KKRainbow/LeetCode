/*
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii
 *
 * Hard (26.15%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0]'
 *
 * 
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * 
 * Each element in the array represents your maximum jump length at that
 * position. 
 * 
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * 
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from
 * index 0 to 1, then 3 steps to the last index.)
 * 
 * 
 * 
 * Note:
 * You can assume that you can always reach the last index.
 */
class Solution {
	public:
		int jump(vector<int>& nums) {
			int begin = 0, end = 1;
			int nextEnd = 1;
			int currStep = 0;

			while (end <= nums.size() - 1) {
				while (begin < end) {
					int tmp = begin + nums[begin];
					if (tmp + 1 > nextEnd) {
						nextEnd = tmp + 1;
					}
					begin++;
				}
				end = nextEnd;
				currStep++;
			}
			return currStep;
		}
};
