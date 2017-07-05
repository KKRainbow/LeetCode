/*
 * [171] Excel Sheet Column Number
 *
 * https://leetcode.com/problems/excel-sheet-column-number
 *
 * Easy (46.72%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"A"'
 *
 * Related to question Excel Sheet Column Title
 * Given a column title as appear in an Excel sheet, return its corresponding
 * column number.
 * 
 * For example:
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test
 * cases.
 */
class Solution {
	public:
		int titleToNumber(string s) {
			int base = 1;
			int res = 0;
			for(int i = s.size() - 1;i>=0;i--)
			{
				res += base * (s[i] - 'A' + 1);
				base *= 26;
			}
			return res;
		}
};
