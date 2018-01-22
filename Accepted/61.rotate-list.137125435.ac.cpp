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
    ListNode* rotateRight(ListNode* head, int k) {
        int ok = k;
        if (k <= 0 || !head) {
            return head;
        }
        ListNode h(0);
        h.next = head;
        
        ListNode **front, **back;
        back = front = &(h.next);
        while (k--) {
            if (!(*front)) {
                auto len  = ok - k - 1;
                return rotateRight(head ,ok % len);
            }
            front = &((*front)->next);
        }
        while (*front) {
            front = &((*front)->next);
            back = &((*back)->next);
        }
        auto result = *back;
        *back = nullptr;
        *front = h.next;
        return result;
    }
};