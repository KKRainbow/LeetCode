class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int left = 0, bottom = matrix.size() - 1;
        while (left < matrix[0].size() && bottom >= 0) {
            if (matrix[bottom][left] > target) {
                bottom--;
            } else if (matrix[bottom][left] < target) {
                left++;
            } else {
                return true;
            }
        }
        return false;
    }
};