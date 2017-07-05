/*
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list
 *
 * Easy (39.67%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * 
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
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if(!head)return nullptr;
			ListNode* f = head;
			ListNode* l = head->next;
			while(l || f != l)
			{
				if(l && f->val == l->val)l = l->next;
				else
				{
					ListNode* tmp = f->next;
					while(tmp != l)
					{
						f->next = tmp->next;
						delete tmp;
						tmp = f->next;
					}
					f = l;
				}
			}
			return head;
		}
};
