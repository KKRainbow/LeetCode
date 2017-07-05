/*
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle
 *
 * Easy (38.15%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '0'
 *
 * Given numRows, generate the first numRows of Pascal's triangle.
 * 
 * 
 * For example, given numRows = 5,
 * Return
 * 
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> res;
			if (numRows <= 0) {
				return res;
			}
			res.push_back({1});
			for (int i = 1 ; i < numRows; i ++) {
				vector<int> row;
				row.push_back(1);
				for (int j = 1; j <= i - 1; j++) {
					int c = res[i - 1][j - 1] + res[i - 1][j];
					row.push_back(c);
				}
				row.push_back(1);
				res.push_back(row);
			}
			return res;
		}
};
