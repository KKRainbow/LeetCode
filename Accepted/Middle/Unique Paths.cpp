//
// Created by sunsijie on 16-3-1.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> table((size_t) m + 1, vector<int>((size_t)n + 1, 1));

        for (int h = 2; h <= m; h++) {
            for (int v = 2; v <= n; v++) {
                table[h][v] = table[h][v - 1] + table[h - 1][v];
            }
        }
        return table[m][n];
    }
};