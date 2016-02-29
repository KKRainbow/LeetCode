//
// Created by sunsijie on 16-2-29.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    struct Blank {
        char& num;
        int row;
        int col;
        Blank(char& num, int row, int col):num(num), row(row), col(col){}
    };
    vector<Blank> blanks;
    int blankCursor = 0;

    int rowTable[9][10];
    int colTable[9][10];
    int squareTable[9][10];

    int O(char n)
    {
        return n - '1';
    }

    int SQ(int row, int col)
    {
        return ((row / 3) * 3) + (col / 3);
    }

    bool test(const Blank& b)
    {
        return !rowTable[b.row][O(b.num)] &&
               !colTable[b.col][O(b.num)] &&
               !squareTable[SQ(b.row, b.col)][O(b.num)];
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char& n = board[r][c];
                if (n == '.') {
                    Blank b(n, r, c);
                    n = '1';
                    blanks.push_back(b);
                } else {
                    rowTable[r][O(n)] = 1;
                    colTable[c][O(n)] = 1;
                    squareTable[SQ(r, c)][O(n)] = 1;
                }
            }
        }

        while (blankCursor < blanks.size()) {
            auto& b = blanks[blankCursor];
            while (b.num <= '9') {
                if (test(b)) {
                    break;
                } else {
                    b.num++;
                }
            }
            cout<<"row: "<<b.row<<" col: "<<b.col<<" num: "<<b.num<<endl;
            if (b.num <= '9') {
                rowTable[b.row][O(b.num)] = 1;
                colTable[b.col][O(b.num)] = 1;
                squareTable[SQ(b.row, b.col)][O(b.num)] = 1;
                blankCursor++;
                if (blankCursor < blanks.size()) {
                    blanks[blankCursor].num = '1';
                }
            } else {
                blankCursor--;
                //不考虑无解情况，即blankCursor < 0
                auto& b = blanks[blankCursor];
                rowTable[b.row][O(b.num)] = 0;
                colTable[b.col][O(b.num)] = 0;
                squareTable[SQ(b.row, b.col)][O(b.num)] = 0;
                b.num++;
            }
        }
    }
};
