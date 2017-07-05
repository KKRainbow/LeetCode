/*
 * [341] Flatten Nested List Iterator
 *
 * https://leetcode.com/problems/flatten-nested-list-iterator
 *
 * Medium (40.95%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[[1,1],2,[1,1]]'
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 * 
 * Each element is either an integer, or a list -- whose elements may also be
 * integers or other lists.
 * 
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,1,2,1,1].
 * 
 * 
 * 
 * Example 2:
 * Given the list [1,[4,[6]]],
 * 
 * By calling next repeatedly until hasNext returns false, the order of
 * elements returned by next should be: [1,4,6].
 * 
 * 
 */
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedIterator {
	stack<pair<const vector<NestedInteger>*, int>> stk;
	bool hasNextFlag = false;
	bool getFirst(const vector<NestedInteger> &nestedList)
	{
		stk.push(make_pair(&nestedList, 0));
		auto lis = stk.top().first;
		auto& idx = stk.top().second;
		for (auto& l : nestedList) {
			if (l.isInteger()) {
				return true;
			} else {
				if (getFirst(l.getList())) {
					return true;
				}
			}
			idx++;
		}
		stk.pop();
		return false;
	}
	public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		hasNextFlag = getFirst(nestedList);
	}
	int next() {
		auto lis = stk.top().first;
		auto* idx = &(stk.top().second);
		int res = ((*lis).begin() + *idx)->getInteger();
		goto to_get;
		while (*idx == lis->size()) {
			stk.pop();
			if (stk.empty()) {
				hasNextFlag = false;
				return res;
			} else {
				lis = stk.top().first;
				idx = &(stk.top().second);
to_get:
				*idx = *idx + 1;
				if (*idx < lis->size()) {
					auto& v = (*lis)[*idx];
					if (v.isInteger()) {
						return res;
					} else {
						if (getFirst(v.getList())) {
							return res;
						} else {
							goto to_get;
						}
					}
				} else {
					continue;
				}
			}
		}
		return res;
	}
	bool hasNext() {
		return hasNextFlag;
	}
};
