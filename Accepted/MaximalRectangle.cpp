//
// Created by sunsijie on 16-3-11.
//

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0);
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                    for (int curr = j, preHeight = heights[j]; curr >= 0 && heights[curr] > 0; curr--) {
                        preHeight = min(preHeight, heights[curr]);
                        res = max(res, (j - curr + 1) * preHeight);
                    }
                }
            }
        }
        return res;
    }
};