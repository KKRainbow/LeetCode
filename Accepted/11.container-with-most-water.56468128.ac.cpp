/*
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water
 *
 * Medium (36.41%)
 * Total Accepted:    
 * Total Submissions: 
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
	public:
		int maxArea(vector<int>& height) {
			map<int, vector<int>> m;
			int res = 0;
			for (int i = 0; i < height.size(); i++) {
				m[height[i]].push_back(i);
			}

			int left = 0, right = height.size() - 1;
			for (auto& p : m) {
				int hei = p.first;
				auto& idx= p.second;
				while (height[left] < hei) {
					left++;
				}
				while (height[right] < hei) {
					right--;
				}
				res = max (res, ((*(--idx.end())) - left) * hei);
				res = max(res, (right - (*idx.begin())) * hei);
			}

			return res;
		}
};
