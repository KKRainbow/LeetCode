/*
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses
 *
 * Hard (23.00%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length
 * = 2.
 * 
 * 
 * Another example is ")()())", where the longest valid parentheses substring
 * is "()()", which has length = 4.
 * 
 */
class Solution {
	public:
		int longestValidParentheses(string s) {
			stack<pair<char, int>> stk;
			int res = 0;
			stk.push(make_pair('*', -1));
			for (int i = 0 ;i < s.length(); i++) {
				char c = s[i];
				int count = 0;
				if (c == ')' && !stk.empty() && stk.top().first == '(') {
					stk.pop();
					res = max(res, i - stk.top().second);
				} else {
					stk.push(make_pair(c, i));
				}
			}
			return res;
		}
};
