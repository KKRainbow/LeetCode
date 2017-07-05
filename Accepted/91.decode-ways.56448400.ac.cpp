/*
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways
 *
 * Medium (19.43%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Given an encoded message containing digits, determine the total number of
 * ways to decode it.
 * 
 * 
 * 
 * For example,
 * Given encoded message "12",
 * it could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * 
 * The number of ways decoding "12" is 2.
 * 
 */
class Solution {
	int n(char c)
	{
		return c - '0';
	}
	public:
	int numDecodings(string s) {
		if (s.empty()) {
			return 0;
		}
		if (s.length() == 1 && s[0] == '0') {
			return 0;
		}
		vector<int> table(s.length() + 1, 1);
		if (s[s.length() - 1] == '0') {
			table[s.length() - 1] = 0;
		}
		for (int i = s.length() - 2; i >= 0; i--) {
			int numSmall = n(s[i]);
			int numLarge = n(s[i]) * 10 + n(s[i + 1]);
			if (numLarge <= 26) {
				if (numSmall == 0) {
					table[i] = 0;
				} else {
					table[i] = table[i + 1] + table[i + 2];
				}
			} else {
				table[i] = table[i + 1];
			}
		}
		return table[0];
	}
};
