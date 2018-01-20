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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *s1 = head, *s2 = head;
        while (1) {
            s1 = s1->next;
            s2 = s2->next ? s2->next->next : nullptr;
            if (!s1 || !s2) return false;
            if (s1 == s2) return true;
        }
    }
};