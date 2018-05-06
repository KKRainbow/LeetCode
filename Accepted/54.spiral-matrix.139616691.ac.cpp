class Solution {
public:
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int height = matrix.size();
        int width = matrix[0].size();
        int round = 0;
        while (1) {
            for (int i = round; i < width - round; i++) {
                res.push_back(matrix[round][i]);
            }
            if (width * height == res.size()) break;
            for (int i = round + 1; i < height - round - 1; i++) {
                res.push_back(matrix[i][width - 1 - round]);
            }
            if (width * height == res.size()) break;
            for (int i = width - 1 - round; i >= round; i--) {
                res.push_back(matrix[height - round - 1][i]);
            }
            if (width * height == res.size()) break;
            for (int i = height - 2 - round; i >= round + 1; i--) {
                res.push_back(matrix[i][round]);
            }
            round++;
            if (width * height == res.size()) break;
        }
        return res;
    }
};
