//
// Created by sunsijie on 16-3-2.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    string ms;
    vector<vector<bool>> isPTable;
private:
    bool isPalindrome(int b, int e)
    {
        if (ms[e - 1] != ms[b]) {
            return false;
        } else {
            if (e - b <= 2) {
                return true;
            } else {
                return isPTable[b + 1][e - 1];
            }
        }
    }
public:
    int minCut(string s) {
        if (!s.length()) {
            return 0;
        }
        vector<int> table(s.length() + 1, (int)s.length());
        this->isPTable = vector<vector<bool>>(s.length() + 1, vector<bool>(s.length() + 1, false));

        table[0] = -1;
        ms = move(s);

        for (int i = 1; i <= ms.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (isPalindrome(j, i)) {
                    isPTable[j][i] = true;
                    int tmp = table[j] + 1;
                    if (tmp < table[i]) {
                        table[i] = tmp;
                    }
                }
            }
        }

        return table[ms.length()];
    }
};

int main(int argc, char* argv[], char* env[])
{
    Solution s;
    cout<<s.minCut("aab")<<endl;
}