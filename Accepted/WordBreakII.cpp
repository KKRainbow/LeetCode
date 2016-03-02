//
// Created by sunsijie on 16-3-2.
//

#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <deque>

using namespace std;

class Solution {
    vector<string> res;
    string cs;
    vector<vector<int>> vec;
    vector<bool> access; //判断i之前的子字符串是否有可能的分解，如果没有，就忽略它就好，后面dfs的时候就只剩解，而不会做无用功
    deque<int> stk;
    string now;
    void aux(int s, int e) {
        stk.push_front(s);
        if (s == 0) {
            now.clear();
            now += cs.substr(stk[0], stk[1]);
            for (int j = 1; j < stk.size() - 1; j++) {
                now.push_back(' ');
                int t1 = stk[j], t2 = stk[j + 1] - t1;
                now += cs.substr(t1, t2);
            }
            res.push_back(now);
        } else {
            for (auto& i : vec[s]) {
                aux(i, s);
            }
        }

        stk.pop_front();
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vec = vector<vector<int>>(s.length() + 1);
        access = vector<bool>(s.length() + 1, false);
        cs = move(s);

        access[0] = true;
        for (int i = 1; i <= cs.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                auto iter = wordDict.find(cs.substr(j, (unsigned)i - j));
                if (iter != wordDict.end()) {
                    if (access[j]) {
                        vec[i].push_back(j);
                        access[i] = true;
                    }
                }
            }
        }
        //构造答案
        stk.push_back(cs.npos);
        for (auto& i : vec[cs.length()]) {
            aux(i, cs.length());
        }

        return res;
    }
};

int main(int argc, char* argv[], char* env[])
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
            "aaaaaaaaaaaaaaaaaaaaaaaaaa""aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> d = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    Solution so;
    for (auto& i : so.wordBreak(s, d)) {
        cout<<i<<' '<<i.length()<<endl;
    }
}