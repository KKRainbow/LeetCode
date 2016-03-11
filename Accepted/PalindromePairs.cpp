//
// Created by sunsijie on 16-3-11.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
    struct Str {
        string str;
        enum { normal, reverse } order;
        int index;
        bool operator < (const Str a)
        {
            return this->str < a.str;
        }
    };
    vector<Str> ordered;
    bool isPalin(const string& str, int begin, int end)
    {
        while (begin <= end) {
            if (str[begin] != str[end - 1]) {
                return false;
            }
            begin++, end--;
        }
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int idx = 0;
        set<pair<int, int>> res;
        //vector<vector<int>> res;
        for_each (words.begin(), words.end(), [this, &idx](string& a) -> void {
            Str ns, rs;
            rs.str = ns.str = a;
            reverse(rs.str.begin(), rs.str.end());
            ns.order = Str::normal;
            rs.order = Str::reverse;
            rs.index = ns.index = idx++;
            this->ordered.push_back(ns);
            this->ordered.push_back(rs);
        });
        sort(ordered.begin(), ordered.end());

        for (int i = 0; i < ordered.size(); i++) {
            for (int j = i + 1; j < ordered.size() && ordered[j].str.length() >= ordered[i].str.length(); j++) {
                if (ordered[i].order == ordered[j].order) {
                    continue;
                }
                string& lo = ordered[j].str, sh = ordered[i].str;
                if (lo.compare(0, sh.length(), sh) == 0) {
                    int left = ordered[i].index, right = ordered[j].index;
                    if (left == right) {
                        continue;
                    }
                    if (ordered[i].order == Str::reverse) {
                        swap(left, right);
                    }
                    if (sh.length() == lo.length()) {
                        res.insert({left, right});
                        res.insert({right, left});
                    } else {
                        if (isPalin(lo, sh.length(), lo.length())) {
                            res.insert({left, right});
                        }
                    }
                } else {
                    break;
                }
            }
        }

        vector<vector<int>> ret;
        ret.reserve(res.size());
        for_each(res.begin(), res.end(), [&ret](const pair<int,int>& p) {
            ret.push_back({p.first, p.second});
        });
        return ret;
    }
};

int main(int argc, char* argv[], char* env[])
{
    vector<string> m = {
            "",
            "a",
    };
    Solution so;
    auto t = so.palindromePairs(m);
    for_each(t.begin(), t.end(), [](vector<int>& v) {
        cout<<v[0] << ' ' << v[1] <<endl;
    });
}