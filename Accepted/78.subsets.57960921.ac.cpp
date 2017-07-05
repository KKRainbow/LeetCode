/*
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets
 *
 * Medium (39.66%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[1,2,3]'
 *
 * 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [1],
 * ⁠ [2],
 * ⁠ [1,2,3],
 * ⁠ [1,3],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			for (unsigned int i = 0; i < (1 << nums.size()); i++) {
				int tmp = i;
				int idx = 0;
				vector<int> v;
				while (tmp) {
					bool b = tmp & 1;
					tmp >>= 1;
					if (b) {
						v.push_back(nums[idx]);
					}
					idx++;
				}
				res.push_back(v);
			}
			return res;
		}
};
