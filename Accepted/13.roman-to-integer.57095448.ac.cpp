/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer
 *
 * Easy (45.28%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"DCXXI"'
 *
 * Given a roman numeral, convert it to an integer.
 * 
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
	public:
		int romanToInt(string str) {
			unordered_map<char, int> v({
					{'Z', 0},
					{'I', 1}, 
					{'V', 5},
					{'X', 10},
					{'L', 50},
					{'C', 100},
					{'D', 500},
					{'M', 1000},
					});

			str.push_back('Z'); //guard

			int res = 0;
			for (int i = 0; i < str.length() - 1; ) {
				char c = str[i];
				char n = str[i + 1];
				if (v[c] < v[n]) {
					res += v[n] - v[c];
					i += 2;
				} else {
					res += v[c];
					i += 1;
				}
			}
			return res;
		}
};

