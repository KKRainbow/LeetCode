/*
 * [132] Palindrome Partitioning II
 *
 * https://leetcode.com/problems/palindrome-partitioning-ii
 *
 * Hard (23.99%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"aab"'
 *
 * 
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * 
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced
 * using 1 cut.
 * 
 */
class Solution {
	string ms;
	vector<vector<bool>> isPTable;
	private:
	bool isPalindrome(int b, int e)
	{
		if (ms[e - 1] != ms[b]) {
			return false;
		} else {
			if (e - b <= 2) {
				return true;
			} else {
				return isPTable[b + 1][e - 1];
			}
		}
	}
	public:
	int minCut(string s) {
		if (!s.length()) {
			return 0;
		}
		vector<int> table(s.length() + 1, (int)s.length());
		this->isPTable = vector<vector<bool>>(s.length() + 1, vector<bool>(s.length() + 1, false));

		table[0] = -1;
		ms = move(s);

		for (int i = 1; i <= ms.length(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (isPalindrome(j, i)) {
					isPTable[j][i] = true;
					int tmp = table[j] + 1;
					if (tmp < table[i]) {
						table[i] = tmp;
					}
				}
			}
		}

		return table[ms.length()];
	}
};
