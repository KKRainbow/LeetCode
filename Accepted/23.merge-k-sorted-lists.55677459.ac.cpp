/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists
 *
 * Hard (26.96%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 */
class comp {
	public:
		static bool lessFirst;
		bool operator ()(ListNode* a, ListNode* b)
		{
			if (!a) {
				return false;
			}
			if (!b) {
				return true;
			}
			if (comp::lessFirst) {
				return a->val < b->val;
			} else {
				return a->val > b->val;
			}
		}
};

bool comp::lessFirst = true;

class Solution {
	ListNode* winner;
	public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		multiset<ListNode*, comp> s;
		for (auto& n : lists) {
			if (n) {
				s.insert(n);
			}
		}

		ListNode* res, *step;

		if (s.empty()) {
			return nullptr;
		}

		res = step = *s.begin();

		while (!s.empty()) {
			s.erase(s.begin());
			//s.erase(step);
			//cout << s.size() <<endl;
			if (step->next) {
				s.insert(step->next);
			}
			auto next = *s.begin();
			step->next = next;
			step = next;
		}

		return res;
	}
};
