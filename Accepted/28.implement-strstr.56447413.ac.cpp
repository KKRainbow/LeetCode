/*
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr
 *
 * Easy (27.87%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n""'
 *
 * 
 * Implement strStr().
 * 
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 */
class Solution {
	vector<int> next;
	void getNext(string& s) 
	{
		next[0] = next[1] = 0;
		for (int i = 2; i < s.length(); i++) {
			int t = next[i - 1];
			while (t != 0 && s[t] != s[i - 1]) {
				t = next[t];
			}
			next[i] = s[t] == s[i - 1] ? t + 1 : 0;
		}
	}
	public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}

		next.resize(needle.length() + 1);
		getNext(needle);

		int t = 0;
		for (int i = 0; i < haystack.length();) {
			if (haystack[i] == needle[t]) {
				i++;
				t++;
			} else if (t) {
				t = next[t];
			} else {
				i++;
			}
			if (t == needle.length()) {
				return i - t;
			}
		}

		return -1;
	}
};
