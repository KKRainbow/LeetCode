/*
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle
 *
 * Hard (27.46%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["10100","10111","11111","10010"]'
 *
 * 
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * 
 * For example, given the following matrix:
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Return 6.
 * 
 */
class Solution {
	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
			if (matrix.empty()) {
				return 0;
			}
			vector<int> heights(matrix[0].size(), 0);
			int res = 0;
			for (int i = 0; i < matrix.size(); i++) {
				for (int j = 0; j < matrix[i].size(); j++) {
					if (matrix[i][j] == '0') {
						heights[j] = 0;
					} else {
						heights[j]++;
						for (int curr = j, preHeight = heights[j]; curr >= 0 && heights[curr] > 0; curr--) {
							preHeight = min(preHeight, heights[curr]);
							res = max(res, (j - curr + 1) * preHeight);
						}
					}
				}
			}
			return res;
		}
};
