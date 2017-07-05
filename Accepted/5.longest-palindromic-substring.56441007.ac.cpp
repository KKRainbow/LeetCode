/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring
 *
 * Medium (25.14%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * 
 * Output: "bab"
 * 
 * Note: "aba" is also a valid answer.
 * 
 * 
 * 
 * Example:
 * 
 * Input: "cbbd"
 * 
 * Output: "bb"
 * 
 * 
 */
class Solution {
	public:
		string longestPalindrome(string s) {
			vector<vector<int>> table(2);
			int res = 0;
			int end = 0, begin = 0;
			table[0].push_back(0);

			for (int i = 1; i < s.length();i++) {
				for (int j = 0; j < table[0].size(); j++) {
					int begin = table[0][j];
					if (begin > 0) {
						if (s[i] == s[begin - 1]) {
							table[1].push_back(begin - 1);
						}
					}
				}
				if (s[i] == s[i - 1]) {
					table[1].push_back(i - 1);
				}
				table[1].push_back(i);
				int tmp = i - table[1][0] + 1;
				if (tmp > res) {
					res = tmp;
					begin = table[1][0];
					end = i;
				}
				table[0].swap(table[1]);
				table[1].clear();
			}
			return s.substr(begin, end - begin + 1);
		}
};
