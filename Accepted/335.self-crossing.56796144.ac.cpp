/*
 * [335] Self Crossing
 *
 * https://leetcode.com/problems/self-crossing
 *
 * Hard (24.95%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[2,1,1,2]'
 *
 * 
 * ⁠   You are given an array x of n positive numbers. You start at point (0,0)
 * and moves x[0] metres to the north, then x[1] metres to the west,
 * ⁠   x[2] metres to the south,
 * ⁠   x[3] metres to the east and so on. In other words, after each move your
 * direction changes
 * ⁠   counter-clockwise.
 * 
 * 
 * ⁠   Write a one-pass algorithm with O(1) extra space to determine, if your
 * path crosses itself, or not.
 * 
 * 
 * 
 * Example 1:
 * 
 * Given x = [2, 1, 1, 2],
 * ┌───┐
 * │   │
 * └───┼──>
 * ⁠   │
 * 
 * Return true (self crossing)
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Given x = [1, 2, 3, 4],
 * ┌──────┐
 * │      │
 * │
 * │
 * └────────────>
 * 
 * Return false (not self crossing)
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * Given x = [1, 1, 1, 1],
 * ┌───┐
 * │   │
 * └───┼>
 * 
 * Return true (self crossing)
 * 
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
	bool isSelfCrossingAux(vector<int>& x, int start, int startLimit) 
	{
		for (int i = start; i < x.size(); i++) {
			if (x[i] >= startLimit) {
				cout << i <<  ' '<< startLimit << endl;
				return true;
			} else {
				startLimit = x[i - 1];
			}
		}
		return false;
	}
	public:
	bool isSelfCrossing(vector<int>& x) {
		if (x.size() <= 3) {
			return false;
		} else {
			if (x[2] <= x[0]) {
				return isSelfCrossingAux(x, 3, x[1]);
			} else {
				if (x[3] < x[1]) {
					return isSelfCrossingAux(x, 4, x[2]);
				} else if (x[3] == x[1]) {
					return isSelfCrossingAux(x, 4, x[2] - x[0]);
				} else {
					for (int i = 4; i < x.size(); i++) {
						//cout << "i:" << i << "x[i - 2]" << x[i - 2] << "x[i - 4]" << x[i - 4] << endl;
						if (x[i] < x[i - 2] - x[i - 4]) {
							return isSelfCrossingAux(x, i + 1, x[i - 1]);
						} else if (x[i] <= x[i - 2]) {
							return isSelfCrossingAux(x, i + 1, x[i - 1] - x[i -3]);
						}
					}
					return false;
				}
			}
		}
	}
};   
