//
// Created by sunsijie on 16-2-29.
//
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int begin = 0, end = 1;
        int nextEnd = 1;
        int currStep = 0;

        while (end <= nums.size() - 1) {
            while (begin < end) {
                int tmp = begin + nums[begin];
                if (tmp + 1 > nextEnd) {
                    nextEnd = tmp + 1;
                }
                begin++;
            }
            end = nextEnd;
            currStep++;
        }
        return currStep;
    }
};