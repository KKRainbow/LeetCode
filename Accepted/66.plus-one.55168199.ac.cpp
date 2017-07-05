/*
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one
 *
 * Easy (38.29%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[0]'
 *
 * Given a non-negative integer represented as a non-empty array of digits,
 * plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 */
class Solution {
	public:
		vector<int> plusOne(vector<int>& digits) {
			int i = (int)digits.size() - 1;
			while (i >= 0 && digits[i] == 9) {
				digits[i] = 0;
				i--;
			}
			if (i == -1) digits.insert(digits.begin(), 1);
			else digits[i]++;
			return digits;
		}
};
