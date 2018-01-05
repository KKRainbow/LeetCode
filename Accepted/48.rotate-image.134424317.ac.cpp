class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size() - 1;
        // m[x][y] -> m[y][n - x] -> m[n - x][n - y] -> m[n - y][x] -> m[x][y]
        for (int row = 0; row < (n + 2) / 2; row++) {
            for (int col = row; col < n - row; col++) {
                int& a = m[row][col];
                int& b = m[col][n - row];
                int& c = m[n - row][n - col];
                int& d = m[n - col][row];
                
                auto tmp = d;
                d = c; c = b; b = a; a = tmp;
            }
        }
    }
};