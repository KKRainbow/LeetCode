/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern
 *
 * Easy (32.85%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
	public:
		bool wordPattern(string pattern, string str) {
			stringstream ss(str);
			unordered_map<char, string> hash;
			set<string> t;
			int c = 1;
			string s;
			for (auto c : pattern) {
				ss >> s;
				if (s.length() == 0) {
					return false;
				} else {
					try {
						if (s != hash.at(c)) {
							return false;
						}
					} catch (...) {
						if (t.find(s) != t.end()) {
							return false;
						} else {
							hash[c] = s;
							t.insert(s);
						}
					}
				}
			}
			return ss.eof();
		}
};
