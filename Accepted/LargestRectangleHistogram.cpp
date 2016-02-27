//
// Created by sunsijie on 16-2-27.
//

#include<stack>
#include<vector>
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