/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){return a.start < b.start;});
        result.push_back(intervals[0]);
        auto* ptr = &result.back();
        for (int i = 1; i < intervals.size(); i++) {
            auto c = intervals[i];
            if (c.start <= ptr->end) {
                ptr->end = max(ptr->end, c.end);
            } else {
                result.push_back(c);
                ptr = &result.back();
            }
        }
        return result;
    }
};