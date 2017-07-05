/*
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say
 *
 * Easy (34.14%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * 
 * 
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * 
 * 
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * Example 1:
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 4
 * Output: "1211"
 * 
 * 
 */
class Solution {
	public:
		string countAndSay(int n) {
			string curr = "1";
			ostringstream stream;
			while (--n) {
				int curri = 0;
				size_t len = curr.length();
				for (int i = 0; i < len; ) {
					curri = i;
					while (i < curr.length() && curr[i] == curr[curri]) {
						i++;
					}
					stream << i - curri << curr[curri];
				}
				curr = stream.str();
				stream.clear();
				stream.str("");
			}
			return curr;
		}
};
