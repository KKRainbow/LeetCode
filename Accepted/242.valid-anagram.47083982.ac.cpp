/*
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram
 *
 * Easy (46.09%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '""\n""'
 *
 * Given two strings s and t, write a function to determine if t is an anagram
 * of s. 
 * 
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 */
class Solution {
	public:
		bool isAnagram(string s, string t) {
			unordered_map<char,int> hash;
			for(auto &c:s)
			{
				hash[c]++;
			}
			for(auto&c:t)
			{
				auto& tmp = hash[c];
				if(tmp == 0)return false;
				else tmp--;
			}
			return s.size() == t.size();
		}
};
