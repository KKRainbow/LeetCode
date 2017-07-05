/*
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one
 *
 * Hard (28.16%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '-1'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * 
 * For example: 
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12,
 * 13.
 * 
 */
class Solution {
	public:
		int countDigitOne(int n) {
			if (n <= 0) {
				return 0;
			}
			string s;
			while (n) {
				s.push_back((n % 10) + '0');
				n /= 10;
			}
			int curr = 0, cnt = 0, num = 0, res = 0;
			for (auto r = s.rbegin(); r != s.rend(); r++) {
				curr = *r - '0';
				res = (res - cnt) * 10 + min(curr, 1) + num + cnt * (curr + 1);
				if (curr == 1) {
					cnt ++;
				}
				num = num * 10 + curr;
			}
			return res;
		}
};
