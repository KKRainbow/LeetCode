/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens
 *
 * Hard (30.52%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//只测试斜线
int test(int *row, int currRow, int currCol)
{
	for (int i = 1; i < currRow; i++) {
		int colNum = row[i];
		if (abs(currCol - colNum) == abs(currRow - i)) {
			return 0;
		}
	}
	return 1;
}

int search(int *row, int *col, int n, int currRow)
{
	int currCol = 0;
	while (1) {
		currCol = row[currRow];
		//printf("row: %d\t col: %d\n", currRow, currCol);
		if (currCol <= n && (col[currCol] || !test(row, currRow, currCol))) {
			//该列被占用
			row[currRow]++;
			continue;
		} else {
			if (currCol > n) {
				currRow--;
				if (currRow <= 0) {
					return 0;
				}
				col[row[currRow]] = 0;
				row[currRow]++;
				continue;
			} else {
				col[currCol] = currRow;
				if (currRow == n) {
					return 1;
				} else {
					currRow++;
					row[currRow] = 1;
				}
			}
		}
	}
}

int searchFirst(int *row, int *col, int n)
{
	row[1] = 1;
	return search(row, col, n, 1);
}

int searchNext(int *row, int *col, int n)
{
	col[row[n]] = 0;
	row[n]++;
	return search(row, col, n, n);
}

vector<string> buildAns(int* row, int n)
{
	vector<string> ret;
	for (int i = 1; i <= n; i++) {
		string tmp((size_t)n, '.');
		tmp[row[i] - 1] = 'Q';
		ret.push_back(tmp);
	}
	return ret;
}

class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			int *row, *col;
			vector<vector<string>> res;
			row = (int*)calloc((size_t)n + 2, sizeof(int));
			col = (int*)calloc((size_t)n + 2, sizeof(int));

			if (!searchFirst(row, col, n)) {
				return res;
			}
			int i = 0;
			do {
				i++;
				res.push_back(buildAns(row, n));
			} while (searchNext(row, col, n));

			free(row);
			free(col);
			return res;
		}
};

