class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        auto f = [&](int x, int y) {
            if (x < 0 || y < 0) {
                return INT_MAX;
            } else {
                return grid[x][y];
            }
        };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!i && !j) continue;
                grid[i][j] += min(f(i - 1, j), f(i, j - 1));
            }
        }
        return grid.back().back();
    }
};
