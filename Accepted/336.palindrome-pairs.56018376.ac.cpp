/*
 * [336] Palindrome Pairs
 *
 * https://leetcode.com/problems/palindrome-pairs
 *
 * Hard (25.92%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * 
 * ⁠   Given a list of unique words, find all pairs of distinct indices (i, j)
 * in the given list, so that the concatenation of the two words, i.e. words[i]
 * + words[j] is a palindrome.
 * 
 * 
 * 
 * ⁠   Example 1:
 * ⁠   Given words = ["bat", "tab", "cat"]
 * ⁠   Return [[0, 1], [1, 0]]
 * ⁠   The palindromes are ["battab", "tabbat"]
 * 
 * 
 * ⁠   Example 2:
 * ⁠   Given words = ["abcd", "dcba", "lls", "s", "sssll"]
 * ⁠   Return [[0, 1], [1, 0], [3, 2], [2, 4]]
 * ⁠   The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
 * 
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating
 * all test cases.
 */
class Solution {
	struct Str {
		string str;
		enum { normal, reverse } order;
		int index;
		bool operator < (const Str a)
		{
			return this->str < a.str;
		}
	};
	vector<Str> ordered;
	bool isPalin(const string& str, int begin, int end)
	{
		while (begin <= end) {
			if (str[begin] != str[end - 1]) {
				return false;
			}
			begin++, end--;
		}
		return true;
	}
	public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		int idx = 0;
		set<pair<int, int>> res;
		//vector<vector<int>> res;
		for_each (words.begin(), words.end(), [this, &idx](string& a) -> void {
				Str ns, rs;
				rs.str = ns.str = a;
				reverse(rs.str.begin(), rs.str.end());
				ns.order = Str::normal;
				rs.order = Str::reverse;
				rs.index = ns.index = idx++;
				this->ordered.push_back(ns);
				this->ordered.push_back(rs);
				});
		sort(ordered.begin(), ordered.end());

		for (int i = 0; i < ordered.size(); i++) {
			for (int j = i + 1; j < ordered.size() && ordered[j].str.length() >= ordered[i].str.length(); j++) {
				if (ordered[i].order == ordered[j].order) {
					continue;
				}
				string& lo = ordered[j].str, sh = ordered[i].str;
				if (lo.compare(0, sh.length(), sh) == 0) {
					int left = ordered[i].index, right = ordered[j].index;
					if (left == right) {
						continue;
					}
					if (ordered[i].order == Str::reverse) {
						swap(left, right);
					}
					if (sh.length() == lo.length()) {
						res.insert({left, right});
						res.insert({right, left});
					} else {
						if (isPalin(lo, sh.length(), lo.length())) {
							res.insert({left, right});
						}
					}
				} else {
					break;
				}
			}
		}

		vector<vector<int>> ret;
		ret.reserve(res.size());
		for_each(res.begin(), res.end(), [&ret](const pair<int,int>& p) {
				ret.push_back({p.first, p.second});
				});
		return ret;
	}
};
