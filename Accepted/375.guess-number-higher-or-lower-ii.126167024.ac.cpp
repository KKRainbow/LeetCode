class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
        for (int len = 2; len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                mat[start][len] = INT_MAX;
                for (int i = start; i < start + len; i++) {
                    mat[start][len] = min(mat[start][len], (i + 1) + max(mat[start][i - start], mat[i + 1][start + len - i - 1]));
                    //cout << start << ' ' << len << ' ' << mat[start][len] << ' ' << mat[start].size() << endl;
                }
            }
        }
        return mat[0][n];
    }
};