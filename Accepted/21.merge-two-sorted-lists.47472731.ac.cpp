/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists
 *
 * Easy (38.94%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]\n[]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
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
	ListNode* compare(ListNode*& l1,ListNode*& l2)
	{
		ListNode* tmp = nullptr;
		if(!l1 && !l2)return nullptr;
		if(!l1 && l2)
		{
			tmp = l2;
			l2 = l2->next;
		}
		else if(!l2 && l1)
		{
			tmp = l1;
			l1 = l1->next;
		}
		else if(l1->val < l2->val)
		{
			tmp = l1;
			l1 = l1->next;
		}
		else
		{
			tmp = l2;
			l2 = l2->next;
		}
		return tmp;
	}
	public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		auto head = compare(l1,l2);
		auto step = head;
		while(step)
		{
			step->next = compare(l1,l2);
			step = step->next;
		}
		return head;
	}
};
