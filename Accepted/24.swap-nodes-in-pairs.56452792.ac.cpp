/*
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs
 *
 * Medium (38.09%)
 * Total Accepted:    
 * Total Submissions: 
 * Testcase Example:  '[]'
 *
 * 
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * 
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 * 
 * Your algorithm should use only constant space. You may not modify the values
 * in the list, only nodes itself can be changed.
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
		ListNode* swapPairs(ListNode* head) {
			auto tmp = head && head->next ? head->next : head;
			ListNode* before = nullptr;
			while(head && head->next) {
				auto tmp = head->next;
				head->next = tmp->next;
				tmp->next = head;
				if (before) {
					before->next = tmp;
				}
				before = head;
				head = head->next;
			}
			return tmp;
		}
};
