/*
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words
 *
 * Hard (21.88%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * 
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 * 
 */
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;
class Solution {
	public:
		vector<int> findSubstring(string s, vector<string>& words) {
			if (words.empty()) {
				return vector<int>();
			}
			size_t len = words[0].length();
			size_t size = words.size();
			map<string, int> wordMap;
			map<string, int> initMap;
			vector<int> res;

			for (auto &w : words) {
				initMap[w]++;
			}

			//记录已经找到的单词数目
			int count = 0;
			for (int i = 0; i < len; i++) {
				int leftCursor = i, rightCursor = i;
				while (leftCursor + (len * size) <= s.size()) {
					if (rightCursor + len > s.size()) {
						break;
					} else {
						string tmp(s, (unsigned long)rightCursor, len);
						const auto initValue = initMap[tmp];
						auto& wordValue = wordMap[tmp];
						if (initValue == 0) {
							//不存在这个单词
							leftCursor = rightCursor = rightCursor + (int)len;
							wordMap.clear();
							count = 0;
						} else if (wordValue >= initValue) {
							//已经有过
							//把其他都清空
							wordMap.clear();
							count = 0;
							leftCursor += len;
							rightCursor = leftCursor;
						} else {
							//出现的次数还没超过总共的个数
							wordValue++;
							count++;
							rightCursor += (int)len;
						}

						if (count == size) {
							res.push_back(leftCursor);
							wordMap.clear();
							count = 0;
							leftCursor += (int)len;
							rightCursor = leftCursor;
						}
					}
				}
			}
			return res;
		}
};

