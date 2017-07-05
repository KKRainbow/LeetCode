/*
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths
 *
 * Medium (40.69%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1\n2'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
	public:
		int uniquePaths(int m, int n) {
			vector<vector<int>> table((size_t) m + 1, vector<int>((size_t)n + 1, 1));

			for (int h = 2; h <= m; h++) {
				for (int v = 2; v <= n; v++) {
					table[h][v] = table[h][v - 1] + table[h - 1][v];
				}
			}
			return table[m][n];
		}
};
