/*
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string
 *
 * Hard (28.91%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"a"\n"a"'
 *
 * 
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 */
class Solution {
	unordered_map<string, bool> hash;
	bool recursive(const string& target, const string& str)
	{
		//cout << target << ' ' << str << endl;

		if (target.length() == 0) {
			return true;
		}
		if (target.length() == 1) {
			return target == str;
		}

		for (int i = 1 ; i < target.length(); i++) {
			bool l = recursive(target.substr(0, i), str.substr(0, i)) && 
				recursive(target.substr(i), str.substr(i));
			bool r = recursive(target.substr(0, i), str.substr(str.length() - i)) &&
				recursive(target.substr(i), str.substr(0, str.length() - i));
			if (l || r) {
				return true;
			}
		}

		return false;
	}


	bool dp(const string& dest, const string& str)
	{
		vector<vector<set<int>>> table(str.length() + 1);
		table[1].resize(str.length());
		for (int i = 0; i < str.length(); i++) {
			auto diter = find(dest.begin(), dest.end(), str[i]);
			while (diter != dest.end()) {
				table[1][i].insert(diter - dest.begin());
				diter++;
				diter = find(diter, dest.end(), str[i]);
			}
		}

		for (int len = 2; len <= str.length(); len++) {
			table[len].resize(str.length() - len + 2);
			for (int idx = 0; idx <= str.length() - len; idx++) {
				for (int sublen = 1; sublen < len; sublen++) {
					for (auto leftIdx : table[sublen][idx]) {
						for (auto rightIdx : table[len - sublen][idx + sublen]) {
							bool flag = false;
							if (leftIdx + sublen == rightIdx) {
								flag = true;
								table[len][idx].insert(leftIdx);
							} else if (rightIdx + (len - sublen) == leftIdx) {
								flag = true;
								table[len][idx].insert(rightIdx);
							}
							if (flag && len == str.length()) {
								return true;
							}
						}
					}
				}
			}
			//cout << len << endl;
		}
		return false;
	}


	public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) {
			return false;
		} else if (s1.length() == 1 && s1 == s2) {
			return true;
		} else {
			return dp(s1, s2);
		}
	}
};
