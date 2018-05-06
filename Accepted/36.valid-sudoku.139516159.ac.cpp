class Solution {
    void p(const vector<int> &tmp) {
        for (auto i : tmp) {
            cout << i << '\t';
        }
        cout << endl;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            vector<int> hash1(10, 0), hash2(10, 0);
            for (int col = 0; col < 9; col++) {
                auto num1 = board[row][col], num2 = board[col][row];
                if (num1 != '.' && hash1[num1 - '0']) {
                    //cout << row << '?' << col << ' ' << num1 << endl;
                    //p(hash1);
                    return false;
                }
                if (num2 != '.' && hash2[num2 - '0']) {
                    //cout << row << '!' << col << endl;
                    return false;
                }
                if (num1 != '.')
                    hash1[num1 - '0'] = 1;
                if (num2 != '.')
                    hash2[num2 - '0'] = 1;
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9;  col += 3) {
                vector<int> hash1(10, 0);
                for (int i  = 0; i < 9; i++) {
                    auto num = board[row + (i / 3)][col + (i % 3)];
                    if (num != '.' && hash1[num - '0']) {
                        return false;
                    }
                    if (num != '.')
                        hash1[num - '0'] = 1;
                }
            }
        }
        return true;
    }
};
