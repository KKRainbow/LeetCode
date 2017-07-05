/*
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram
 *
 * Hard (26.39%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * For example,
 * Given heights = [2,1,5,6,2,3],
 * return 10.
 * 
 */
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
	public:
		int largestRectangleArea(vector<int>& heights) {
			if (heights.size() == 0) {
				return 0;
			}
			heights.push_back(0);
			stack<int> s;
			size_t size = heights.size();
			int maxArea = -1;
			for (int i = 0; i < size; ) {
				int h = heights[i];
				if ((s.empty() || heights[s.top()] <= h) && i != size - 1) {
					s.push(i);
					i++;
				} else {
					//每次弹出都要算左面积和右面积
					int idx = s.top();
					s.pop();
					int hei = heights[idx]; //以左面矩形的高度作为高
					int lidx = 0;
					if (s.empty()) {
						lidx = 0;
					} else {
						lidx = s.top() + 1;
					}
					int larea = (i - lidx) * hei;

					int rarea = 0;
					if (s.empty()) {
						rarea = (i + 1) * h;
					} else {
						rarea = (i - idx + 1) * h;
					}
					maxArea = max(larea, max(rarea, maxArea));

					if (i == size - 1 && s.empty()) {
						break;
					}
				}
			}
			return maxArea;
		}
};
