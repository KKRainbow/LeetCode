//
// Created by sunsijie on 16-3-1.
//

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minDistance(string shorts, string longs) {
        if (shorts.length() > longs.length()) {
            shorts.swap(longs);
        }
        if (shorts.empty()) {
            return (int)longs.length();
        }

        //table[m][n]指的是longs的前m变成shorts的前n需要的次数
        vector<vector<int>> table(longs.length() + 2, vector<int>(shorts.length() + 2)); //+1防止字符串长度为1

        for (int i = 1; i <= longs.length(); i++) {
            table[i][0] = i;
        }
        for (int i = 1; i <= shorts.length(); i++) {
            table[0][i] = i;
        }

        for (int m = 1; m <= longs.length(); m++) {
            for (int n = 1; n <= shorts.length(); n++) {
                int num1 = table[m -1][n] + 1; //删的情况
                int num2;
                if (longs[m - 1] == shorts[n - 1]) {
                    num2 = table[m - 1][n - 1]; //一样且不删
                } else {
                    num2 = table[m -1][n - 1] + 1;//不一样但是改了
                }
                int num3 = table[m][n - 1] + 1; //末尾加的情况
                table[m][n] = min(num1, min(num2, num3));
            }
        }

        return table[longs.length()][shorts.length()];
    }
};

int main(int argc, char* argv[], char* env[])
{
    string a = "";
    string b = "abcbbc";
    Solution s;
    cout<<s.minDistance(a,b)<<endl;
}