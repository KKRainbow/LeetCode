/*
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval
 *
 * Hard (27.32%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * 
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 * 
 * 
 * 
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 * [1,2],[3,10],[12,16].
 * 
 * 
 * 
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * 
 */
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
