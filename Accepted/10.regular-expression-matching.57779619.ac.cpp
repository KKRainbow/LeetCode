/*
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching
 *
 * Hard (24.04%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aa"\n"a"'
 *
 * Implement regular expression matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 */
class Solution {
	int curr = 0;
	int i = 0;
	//ppos spos len
	stack<tuple<int, int, int>> stk;
	bool backTrace()
	{

		while (1) {
			if (stk.empty()) {
				return false;
			}
			auto& top = stk.top(); 
			if (get<2>(top) == 0) {
				stk.pop();
			} else {
				i = get<0>(top);
				--get<2>(top);
				curr = get<1>(top) + get<2>(top);
				//cout << i << ' ' << curr << ' ' << get<2>(top) << endl;
				break;
			}
		}
		return true;
	}
	public:
	bool isMatch(string s, string p) {
		for (; i < p.length();) {
			//cout << endl << curr << "     " << i << endl;
			if (p[i] == '.' && curr < s.length()) {
				if (p[i + 1] == '*') {
					stk.push(make_tuple(i + 2, curr, s.length() - curr));
					curr = s.length();
					i += 2;
				} else {
					curr++;
					i += 1;
				}
			} else if (isalpha(p[i]) && curr < s.length()) {
				if (p[i + 1] == '*') {
					int maxpos = curr;
					while (s[maxpos] == p[i]) {
						maxpos++;
					}
					//cout << p[i] << ' ' << maxpos << ' ' << curr << endl;
					stk.push(make_tuple(i + 2, curr, maxpos - curr));
					curr = maxpos;
					i += 2;
				} else {
					//cout << "c: " << curr << "i " << i << endl;
					if (p[i] != s[curr]) {
						if (!backTrace()) {
							return false;
						} else {
							continue;
						}
					} else {
						curr++;
						i += 1;
					}
				}
			}
			bool a = (i >= p.length());
			bool b = (curr >= s.length());
			bool flag = false;

			if (b) {
				int tmpi = i;
				for (; tmpi + 1 <= p.length(); tmpi+=2) {
					//cout << tmpi << endl;
					if (p[tmpi + 1] != '*') {
						flag = true;
						break;
					}
				}
			}
			//cout << i;

			if (b && flag) {
				if (!backTrace()) {
					return false;
				} else {
					continue;
				}
			} else {
				if (b && !flag) {
					return true;
				} else {
					continue;
				}
			}
		}
		return curr == s.length();
	}
};
