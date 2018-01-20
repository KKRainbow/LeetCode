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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        ListNode *hare = head, *tortoise = head;
        while (1) {
            tortoise = tortoise->next;
            if (!tortoise) return nullptr;
            hare = hare->next->next;
            if (!hare || !(hare->next)) {
                return nullptr;
            }
            if (hare == tortoise) {
                break;
            }
        }
        
        while (tortoise != head) {
            tortoise = tortoise->next;
            head = head->next;
        }
        return head;
    }
};