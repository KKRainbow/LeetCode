/*
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii
 *
 * Hard (23.00%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. You may assume the dictionary does not contain
 * duplicate words.
 * 
 * 
 * 
 * Return all such possible sentences.
 * 
 * 
 * 
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * 
 * 
 * 
 * A solution is ["cats and dog", "cat sand dog"].
 * 
 * 
 * 
 * UPDATE (2017/1/4):
 * The wordDict parameter had been changed to a list of strings (instead of a
 * set of strings). Please reload the code definition to get the latest
 * changes.
 * 
 */
#include <vector>
#include <iostream>
#include <unordered_set>
#include <stack>
#include <deque>

using namespace std;

class Solution {
	struct Info {
		int pos;
		bool accessible;
	};
	vector<string> res;
	string cs;
	vector<vector<int>> vec;
	vector<bool> access;
	deque<int> stk;
	string now;
	void aux(int s, int e) {
		stk.push_front(s);
		if (s == 0) {
			now.clear();
			now += cs.substr(stk[0], stk[1]);
			for (int j = 1; j < stk.size() - 1; j++) {
				now.push_back(' ');
				int t1 = stk[j], t2 = stk[j + 1] - t1;
				now += cs.substr(t1, t2);
			}
			res.push_back(now);
		} else {
			for (auto& i : vec[s]) {
				aux(i, s);
			}
		}

		stk.pop_front();
	}
	public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vec = vector<vector<int>>(s.length() + 1);
		access = vector<bool>(s.length() + 1, false);
		cs = move(s);

		access[0] = true;
		for (int i = 1; i <= cs.length(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				auto iter = wordDict.find(cs.substr(j, (unsigned)i - j));
				if (iter != wordDict.end()) {
					if (access[j]) {
						vec[i].push_back(j);
						access[i] = true;
					}
				}
			}
		}
		//构造答案
		stk.push_back(cs.npos);
		for (auto& i : vec[cs.length()]) {
			aux(i, cs.length());
		}

		return res;
	}
};
