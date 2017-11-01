class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (auto r : rows) {
            matrix[r] = vector<int>(matrix[0].size(), 0);
        }
        for (auto c : cols) {
            for (int row = 0; row < matrix.size(); row++) {
                matrix[row][c] = 0;
            }
        }
    }
};