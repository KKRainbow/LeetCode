/*
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams
 *
 * Medium (33.98%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * 
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 * 
 * [
 * ⁠ ["ate", "eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note: All inputs will be in lower-case.
 */
class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> vec;
			unordered_map<string, vector<string>> hash;
			for (int i = 0; i < strs.size(); i++) {
				auto s = strs[i];
				sort(s.begin(), s.end());
				hash[s].push_back(strs[i]);
			}
			for (auto& p : hash) {
				auto& v = p.second;
				sort(v.begin(), v.end());
				vec.push_back(v);
			}
			return vec;
		}
};
