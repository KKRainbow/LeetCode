class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<vector<bool>> table(s1.length() + 1, vector<bool>(s2.length() + 1));
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 && j == 0) {
                    table[i][j] = true;
                } else if (i == 0) {
                    table[i][j] = table[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                } else if (j == 0) {
                    table[i][j] = table[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                } else {
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]) || (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                //cout << i << '\t' << j << '\t' << table[i][j] << endl;
            }
        }
        return table.back().back();
    }
};
