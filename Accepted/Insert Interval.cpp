//
// Created by sunsijie on 16-3-12.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    bool isOverlap(const Interval& a, const Interval& b)
    {
        if ((a.start >= b.start && a.start <= b.end) ||
            (a.end >= b.start && a.end <= b.end)) {
            return true;
        }
        return false;
    }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }
        vector<Interval> res;
        //intervals.push_back(newInterval);
        int begin = -1, end = (int)intervals.size();
        auto step = newInterval;
        for (int i = 0; i < intervals.size(); i++) {
            if (isOverlap(step, intervals[i]) || isOverlap(intervals[i], step)) {
                if (begin == -1) {
                    begin = i;
                }
                step.start = min(step.start, intervals[i].start);
                step.end = max(step.end, intervals[i].end);
            } else {
                if (step.end < intervals[i].start) {
                    end = i;
                    break;
                }
            }
        }
        if (begin == -1) {
            begin = end;
        }
        cout << begin <<' ' << end<<endl;
        res.insert(res.end(), intervals.begin(), intervals.begin() + begin);
        if ((step.start == newInterval.start && step.end == newInterval.end) || begin != end) {
            res.push_back(step);
        }
        res.insert(res.end(), intervals.begin() + end, intervals.end());
        sort(res.begin(), res.end(), [](const struct Interval& a, const struct Interval& b) -> bool {
            if (a.start < b.start) {
                return true;
            } else {
                return a.end < b.end;
            }
        });
        return res;
    }
};

int main(int argc, char* argv[], char* env[])
{
    vector<Interval> m = {
            {1,5}
    };
    Interval n = {6, 8};
    Solution so;
    auto res = so.insert(m, n);
    for_each(res.begin(), res.end(), [](struct Interval& i) {
        cout << i.start <<' ' << i.end << endl;
    });
}
