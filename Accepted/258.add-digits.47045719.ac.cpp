/*
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits
 *
 * Easy (50.97%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '0'
 *
 * 
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit. 
 * 
 * 
 * 
 * For example:
 * 
 * 
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only
 * one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
class Solution {
	public:
		int addDigits(int num) {
			if(num == 0)return num;
			else 
			{
				int a = num%9;
				if(a == 0)return 9;
				else return a;
			}
		}
};
