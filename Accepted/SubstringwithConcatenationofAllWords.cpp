//
// Created by sunsijie on 16-2-28.
//

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty()) {
            return vector<int>();
        }
        size_t len = words[0].length();
        size_t size = words.size();
        map<string, int> wordMap;
        map<string, int> initMap;
        vector<int> res;

        for (auto &w : words) {
            initMap[w]++;
        }

        //记录已经找到的单词数目
        int count = 0;
        for (int i = 0; i < len; i++) {
            int leftCursor = i, rightCursor = i;
            while (leftCursor + (len * size) <= s.size()) {
                if (rightCursor + len > s.size()) {
                    break;
                } else {
                    string tmp(s, (unsigned long)rightCursor, len);
                    const auto initValue = initMap[tmp];
                    auto& wordValue = wordMap[tmp];
                    if (initValue == 0) {
                        //不存在这个单词
                        leftCursor = rightCursor = rightCursor + (int)len;
                        wordMap.clear();
                        count = 0;
                    } else if (wordValue >= initValue) {
                        //已经有过
                        //把其他都清空
                        wordMap.clear();
                        count = 0;
                        leftCursor += len;
                        rightCursor = leftCursor;
                    } else {
                        //出现的次数还没超过总共的个数
                        wordValue++;
                        count++;
                        rightCursor += (int)len;
                    }

                    if (count == size) {
                        res.push_back(leftCursor);
                        wordMap.clear();
                        count = 0;
                        leftCursor += (int)len;
                        rightCursor = leftCursor;
                    }
                }
            }
        }
        return res;
    }
};

int main(int argc, char* argv[], char* env[])
{
    string s = "abababab";
    vector<string> w = {"a", "b", "a"};

    Solution so;
    auto r = so.findSubstring(s,w);

    for (auto& i : r) {
        cout<<i;
    }
    cout<<endl;
}
