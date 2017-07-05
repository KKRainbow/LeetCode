/*
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers
 *
 * Medium (27.50%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	ListNode* push(ListNode* tail, int val)
	{
		auto node = new ListNode(val);
		if (tail) { 
			tail->next = node;
		}
		return node;
	}
	public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l2) {
			return l1;
		}
		if (!l1) {
			return l2;
		}
		int c = 0;
		auto head = push(nullptr, 0);

		auto step = head;
		do {
			if (l1) {
				c += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				c += l2->val;
				l2 = l2->next;
			}
			step = push(step, c % 10);
			c /= 10;
		} while(c || l1 || l2);

		return head->next;
	}
};
