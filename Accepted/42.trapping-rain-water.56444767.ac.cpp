/*
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water
 *
 * Hard (36.45%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after
 * raining. 
 * 
 * 
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * 
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 */
class Solution {
	public:
		int trap(vector<int>& height) {
			int stepBegin = 0, stepEnd = height.size() - 1;
			vector<int> sorted = height;
			sort(sorted.begin(), sorted.end());

			int res = 0;
			int oldHei = 0;
			int count = 0;
			for (auto hei : sorted) {
				count++;
				if (hei == oldHei) {
					continue;
				}
				while (height[stepBegin] < hei) {
					stepBegin++;
				}
				while (height[stepEnd] < hei) {
					stepEnd--;
				}
				int tmp = stepEnd - stepBegin;
				if (tmp == 0) {
					break;
				} else {
					tmp++;
				}
				//cout << hei << ' ' << stepBegin << ' ' << stepEnd << ' ' << ' ' << sorted.size() - count + 1 << endl;
				res += (tmp - (sorted.size() - count + 1)) * (hei - oldHei);
				//cout << ' ' << res << endl;
				oldHei = hei;
			}
			return res;
		}
};
