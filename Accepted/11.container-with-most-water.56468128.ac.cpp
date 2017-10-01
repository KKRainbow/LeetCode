/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * algorithms
 * Medium (36.72%)
 * Total Accepted:    153.9K
 * Total Submissions: 419.1K
 * Testcase Example:  '[1,1]'
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 */
class Solution {
    int max(int a, int b) 
    {
        return a > b ? a : b;
    }

    int min(int a, int b) 
    {
        return a < b ? a : b;
    }

public:
    int maxArea(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0;
        res = max(res, min(arr[l], arr[r]) * (r - l));

        while (l < r) {
            if (arr[l] < arr[r]) {
                while(l < r && arr[l] < arr[r]) {
                    l++;
                    if (arr[l] > arr[l - 1]) {
                        res = max(res, min(arr[l], arr[r]) * (r - l));
                    }
                }
            }
            else if (arr[r] < arr[l]) {
                while(l < r && arr[r] < arr[l]) {
                    r--;
                    if (arr[r] > arr[r + 1]) {
                        res = max(res, min(arr[l], arr[r]) * (r - l));
                    }
                }
            } else {
                l++;
                r--;
            }
            res = max(res, min(arr[l], arr[r]) * (r - l));
        }
        return res;
    }
};
