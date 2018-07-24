class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        auto result = matrix;
        vector<tuple<int, int, int>> seq;
        seq.reserve((matrix.size() * matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                seq.push_back({matrix[i][j], i, j});
            }
        }
        sort(seq.begin(), seq.end(), [](auto& a, auto& b) {
            return get<0>(a) < get<0>(b);
        });
        int longest = 0;
        for (auto& s : seq) {
            int val = get<0>(s);
            int i = get<1>(s), j = get<2>(s);
            result[i][j] = 1;
            if (i > 0) {
                if (val > matrix[i - 1][j]) {
                    result[i][j] = max(result[i][j], result[i - 1][j] + 1);
                }
            }
            if (i < matrix.size() - 1) {
                if (val > matrix[i + 1][j]) {
                    result[i][j] = max(result[i][j], result[i + 1][j] + 1);
                }
            }
            if (j > 0) {
                if (val > matrix[i][j - 1]) {
                    result[i][j] = max(result[i][j], result[i][j - 1] + 1);
                }
            }
            if (j < matrix[0].size() - 1) {
                if (val > matrix[i][j + 1]) {
                    result[i][j] = max(result[i][j], result[i][j + 1] + 1);
                }
            }
            longest = max(longest, result[i][j]);
        }

        return longest;
    }
};
