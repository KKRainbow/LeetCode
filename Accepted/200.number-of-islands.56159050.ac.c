/*
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands
 *
 * Medium (34.08%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["11110","11010","11000","00000"]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 11110110101100000000
 * Answer: 1
 * Example 2:
 * 11000110000010000011
 * Answer: 3
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
static int stack[10000][2];
static int curr = 0;

#define PUSH(x,y) do{stack[curr][0] = x;stack[curr][1] = y;curr++;}while(0)
#define POP() (curr--)
#define FRONT(x,y) do{x=stack[curr-1][0];y=stack[curr-1][1];}while(0)
#define EMPTY() (curr==0)

int explore(char** grid, int gridRowSize, int gridColSize, int x, int y) {
	PUSH(x,y);
	int i = 0;
	while(!EMPTY()) {
		FRONT(x, y);
		//printf("%d %d %d    %d\n", x, y, curr,grid[x][y]);
		grid[x][y] = '0';
		POP();
		if (x + 1 < gridRowSize && grid[x + 1][y] == '1') {
			PUSH(x+1, y);
		}
		if (x - 1 >= 0 && grid[x - 1][y] == '1') {
			PUSH(x-1, y);
		}
		if (y + 1 < gridColSize && grid[x][y+1] == '1') {
			PUSH(x, y+1);
		}
		if (y - 1 >= 0 && grid[x][y-1] == '1') {
			PUSH(x, y-1);
		}
	}
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
	int sum = 0;
	for (int i = 0; i < gridRowSize; i++) {
		for (int j = 0; j < gridColSize; j++) {
			if (grid[i][j] == '1') {
				explore(grid, gridRowSize, gridColSize, i, j);
				sum++;
			}
		}
	}
	return sum;
}
