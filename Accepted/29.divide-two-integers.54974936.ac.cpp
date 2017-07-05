/*
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers
 *
 * Medium (15.98%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '0\n1'
 *
 * 
 * Divide two integers without using multiplication, division and mod
 * operator.
 * 
 * 
 * If it is overflow, return MAX_INT.
 * 
 */
class Solution {
	public:
		int divide(int dividend, int divisor) {
			int res = 0;
			if (!divisor) {
				return INT_MAX;
			}
			if (divisor == INT_MIN && dividend == INT_MIN) {
				return 1;
			}
			if (divisor == INT_MIN) {
				return 0;
			}
			if (dividend == INT_MIN) {
				res++;
				if (divisor > 0) {
					dividend += abs(divisor);
				} else {
					dividend -= divisor;
				}
			}
			int origin = divisor;
			int flag = dividend < 0 ? -1 : 1;
			int flag2 = divisor < 0 ? -1 : 1;
			dividend = abs(dividend);
			divisor = abs(divisor);

			int power = 0;
			while (divisor > 0 && dividend > divisor) {
				divisor <<= 1;
				power++;
			}

			if (power > 0) {
				power--;
				divisor = (unsigned)divisor >> 1;
			}

			while (dividend >= abs(origin)) {
				if (dividend - divisor >= 0) {
					dividend -= divisor;
					res += 1<<power;
				} else {
					power--;
					divisor >>= 1;
				}
			}

			if (flag != flag2) {
				return -res;
			} else {
				if (res < 0) {
					return INT_MAX;
				}
				return res;
			}
		}
};
