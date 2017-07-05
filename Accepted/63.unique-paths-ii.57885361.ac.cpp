/*
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii
 *
 * Medium (31.51%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[0]]'
 *
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 * ⁠ [0,0,0],
 * ⁠ [0,1,0],
 * ⁠ [0,0,0]
 * ]
 * 
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 */
class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			int m = obstacleGrid.size(), n = m == 0 ? 0 : obstacleGrid[0].size();
			vector<vector<int>> table((size_t) m + 1, vector<int>((size_t)n + 1, 1));

			for (int i = 1; i < n + 1 ; i++) {
				if (obstacleGrid[0][i - 1] == 1) {
					table[1][i] = 0;
				} else {
					table[1][i] = table[1][i - 1];
				}
			}

			for (int i = 1; i < m + 1 ; i++) {
				if (obstacleGrid[i - 1][0] == 1) {
					table[i][1] = 0;
				} else {
					table[i][1] = table[i - 1][1];
				}
			}

			for (int h = 2; h <= m; h++) {
				for (int v = 2; v <= n; v++) {
					//cout << obstacleGrid[h- 1][v - 1] << endl;
					if (obstacleGrid[h- 1][v - 1] == 0) {
						table[h][v] = table[h][v - 1] + table[h - 1][v];
						//cout << h << ' ' << v << ' ' << table[h][v] << endl;
					} else {
						table[h][v] = 0;
					}
				}
			}
			return table[m][n];
		}
};

