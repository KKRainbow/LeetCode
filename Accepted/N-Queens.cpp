//原谅我在C++中混合了C，用C总是出现Runtime Error，也找不出来为什么
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

//只测试斜线
int test(int *row, int currRow, int currCol)
{
    for (int i = 1; i < currRow; i++) {
        int colNum = row[i];
        if (abs(currCol - colNum) == abs(currRow - i)) {
            return 0;
        }
    }
    return 1;
}

int search(int *row, int *col, int n, int currRow)
{
    int currCol = 0;
    while (1) {
        currCol = row[currRow];
        //printf("row: %d\t col: %d\n", currRow, currCol);
        if (currCol <= n && (col[currCol] || !test(row, currRow, currCol))) {
            //该列被占用
            row[currRow]++;
            continue;
        } else {
            if (currCol > n) {
                currRow--;
                if (currRow <= 0) {
                    return 0;
                }
                col[row[currRow]] = 0;
                row[currRow]++;
                continue;
            } else {
                col[currCol] = currRow;
                if (currRow == n) {
                    return 1;
                } else {
                    currRow++;
                    row[currRow] = 1;
                }
            }
        }
    }
}

int searchFirst(int *row, int *col, int n)
{
    row[1] = 1;
    return search(row, col, n, 1);
}

int searchNext(int *row, int *col, int n)
{
    col[row[n]] = 0;
    row[n]++;
    return search(row, col, n, n);
}

vector<string> buildAns(int* row, int n)
{
    vector<string> ret;
    for (int i = 1; i <= n; i++) {
        string tmp((size_t)n, '.');
        tmp[row[i] - 1] = 'Q';
        ret.push_back(tmp);
    }
    return ret;
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int *row, *col;
        vector<vector<string>> res;
        row = (int*)calloc((size_t)n + 2, sizeof(int));
        col = (int*)calloc((size_t)n + 2, sizeof(int));

        if (!searchFirst(row, col, n)) {
            return res;
        }
        int i = 0;
        do {
            i++;
            res.push_back(buildAns(row, n));
        } while (searchNext(row, col, n));

        free(row);
        free(col);
        return res;
    }
};

int main()
{
    int a;
    Solution s;
    auto res = s.solveNQueens(4);
    for (auto& vec : res) {
        for (auto& str : vec) {
            cout<<str<<endl;
        }
        cout<<endl;
    }
}