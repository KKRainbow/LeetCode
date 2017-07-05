/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses
 *
 * Easy (33.21%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"["'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all
 * valid but "(]" and "([)]" are not.
 * 
 */
class Solution {
	public:
		bool isValid(string s) {
			stack<char> stk;
			for (auto c : s) {
				char rep = 0;
				switch (c) {
					case ')':
						rep = '(';
						break;
					case '}':
						rep = '{';
						break;
					case ']':
						rep = '[';
						break;
					default:
						stk.push(c);
						continue;
				}
				if (stk.empty() || stk.top() != rep) {
					return false;
				} else {
					stk.pop();
				}
			}
			return stk.empty();
		}
};
