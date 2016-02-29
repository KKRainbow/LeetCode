//
// Created by sunsijie on 16-2-28.
//

#include <cstring>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int initMap[256] = {0,};
        int wordMap[256] = {0,};
        bool flag = false;
        size_t l = 0, r = s.size();
        size_t size = t.length();

        for (auto& c : t) {
            initMap[c]++;
        }

        int count = 0;
        int leftCursor = 0, rightCursor = 0;
        while (rightCursor <= s.length()) {
            char rc = s[rightCursor];
            //这里操作rightCursor
            if (initMap[rc]) {
                //第一次出现
                auto tmp = ++wordMap[rc];
                if (tmp <= initMap[rc]) {
                    count++;
                }
            }
            rightCursor++;

            if (count == size) {
                flag = true;
                //开始操作左边的
                while (1) {
                    char lc = s[leftCursor];
                    if (!initMap[lc]) {
                        leftCursor++;
                    } else {
                        if (wordMap[lc] == initMap[lc]) { //不能在少了
                            break;
                        } else {
                            wordMap[lc]--;
                            leftCursor++;
                        }
                    }
                }
                //现在左边不能再前进了
                if (rightCursor - leftCursor < r - l) {
                    l = leftCursor;
                    r = rightCursor;
                }

                //开始下一次搜索,每次搜索是右边扩展，紧接着左边夹逼
                //左边的字符一定在t内
                wordMap[s[leftCursor]]--;
                count--;
                leftCursor++;
            }
        }

        return flag ? string(s, l, r - l) : "";
    }
};

int main(int argc, char* argv[], char* env[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution so;
    auto r = so.minWindow(s,t);

    cout<<r<<endl;
}