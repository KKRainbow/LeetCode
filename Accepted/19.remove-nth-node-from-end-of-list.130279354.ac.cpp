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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode beg(1), **prev = &(beg.next), *adv = head;
        beg.next = head;
        while (n--) {
            adv = adv->next;
        }
        while (adv) {
            adv = adv->next;
            prev = &((*prev)->next);
        }
        auto tmp = (*prev);
        if ((*prev)->next) {
            *prev = (*prev)->next;
        }
        else *prev = nullptr;
        delete tmp;
        return beg.next;
    }
};