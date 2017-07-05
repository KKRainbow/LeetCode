/*
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * Medium (24.20%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 * answer must be a substring, "pwke" is a subsequence and not a substring.
 */
class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (s.empty()) {
				return 0;
			}
			int begin = 0, end = 1;
			int res = 1;
			for (int i = 1; i < s.length(); i++) {
				int tmp = begin;
				while (tmp != end && s[tmp] != s[i]) {
					tmp++;
				}

				if (tmp != end) {
					begin = tmp + 1;
				}
				end++;

				res = max(res, end - begin);
			}
			return res;
		}
};
