/*
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two
 *
 * Easy (39.96%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * 
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
	public:
		bool isPowerOfTwo(int n) {
			return n>0 && (!(n & (n-1)));
		}
};
