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
    ListNode* partition(ListNode* head, int x) {
        ListNode *a = nullptr, *b = nullptr;
        ListNode *ha = nullptr, *hb = nullptr;
        for (;head ; head = head->next) {
            if (head->val < x) {
                if (!a) {
                    a = head;
                    ha = a;
                } else {
                    a->next = head;         
                    a = a->next;
                }
            } else {
                if (!b) {
                    b = head;
                    hb = b;
                } else {
                    b->next = head;
                    b = b->next;
                }
            }
        }
        if (a) a->next = hb; 
        if (b) b->next = nullptr;
        return ha ? ha : hb;
    }
};