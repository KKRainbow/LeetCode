class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        vector<int> heights(matrix[0].size());
        int res = 0;
        for (int row = 0; row < matrix.size(); row++) {
            vector<int> minHeights(matrix[row].size(), INT_MAX);
            for (int col = 0; col < matrix[row].size(); col++) {
                //cout << row << ' ' << col << endl;
                heights[col] = matrix[row][col] == '1' ? heights[col] + 1 : 0;
                minHeights[col] = heights[col];
                for (int i = 0; i <= col; i++) {
                    minHeights[i] = min(minHeights[i], minHeights[col]);
                    if (col - i + 1 <= minHeights[i]) {
                        res = max(col - i + 1, res);
                    }
                }
            }
        }
        return res * res;
    }
};