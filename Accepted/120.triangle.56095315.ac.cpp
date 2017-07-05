/*
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle
 *
 * Medium (33.48%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[-10]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * 
 * For example, given the following triangle
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * 
 * 
 * Note:
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
	public:
		int minimumTotal(vector<vector<int>>& triangle) {
			if (triangle.empty()) {
				return 0;
			}
			for (int i = triangle.size() - 2; i >=0 ; i--) {
				auto& t = triangle[i+1];
				for (int j = 0; j < triangle[i].size(); j++) {
					triangle[i][j] += min(t[j], t[j + 1]);
				}
			}
			return triangle[0][0];
		}
};
