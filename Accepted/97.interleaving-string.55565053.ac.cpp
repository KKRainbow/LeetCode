/*
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string
 *
 * Hard (24.43%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n""\n""'
 *
 * 
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * 
 * 
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * 
 * 
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 * 
 */
class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if (s3.length() != s1.length() + s2.length()) {
				return false;
			}
			if (s3.empty()) {
				if (s1.empty() && s2.empty()) {
					return true;
				} else {
					return false;
				}
			}
			set<pair<int, int>> curr;
			set<pair<int, int>> next;

			curr.insert(make_pair(0, 0));

			for (int i = 0; i < s3.length(); i++) {
				for (auto& p : curr) {
					int p1 = p.first, p2 = p.second;
					int n = -2;

					if (p1 < s1.length() && s1[p1] == s3[i]) {
						next.insert(make_pair(p1 + 1, p2));
					}

					if (p2 < s2.length() && s2[p2] == s3[i]) {
						next.insert(make_pair(p1, p2 + 1));
					}
				}
				curr.swap(next);
				next.clear();
			}

			return !curr.empty();
		}
};
