class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1, col = 0;
        while (row >= 0 && col < matrix[0].size()) {
            auto v = matrix[row][col];
            if (v == target) return true;
            else if (v < target) col++;
            else row--;
        }
        return false;
    }
};