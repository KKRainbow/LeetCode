/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal
 *
 * Medium (17.35%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1\n5'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * 
 * 
 * 
 * Credits:Special thanks to @Shangrila for adding this problem and creating
 * all test cases.
 */
class Solution {
	public:
		string fractionToDecimal(long long numerator, long long denominator) {
			if (!denominator) {
				return "";
			}
			bool isNeg = ((numerator ^ denominator) & INT_MIN) != 0;
			long long rem = abs(numerator) % abs(denominator), quo = abs(numerator) / abs(denominator);
			stringstream s;
			if (isNeg && numerator) {
				s << '-';
			}
			s << quo;
			if (rem) {
				s << '.';
			}
			unordered_map<int, int> hash;

			string str;
			hash[rem] = -1;
			while (rem) {
				rem *= 10;
				quo = rem / abs(denominator);
				rem = rem % abs(denominator);
				if (hash.find(rem) == hash.end()) {
					hash[rem] = str.length();
					str.push_back(quo + '0');
				} else {
					int pos = hash[rem];
					str.push_back(quo + '0');
					str.insert(hash[rem] + 1, "(");
					str.push_back(')');
					break;
				}
			}

			s << str;
			return s.str();
		}
};
