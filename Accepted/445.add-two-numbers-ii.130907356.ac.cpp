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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        queue<int> c;
        while (l1) {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            b.push(l2->val);
            l2 = l2->next;
        }
        ListNode anchor(0);
        int carry = 0;
        while (!a.empty() || !b.empty() || carry) {
            int an = 0, bn = 0;
            if (!a.empty()) {
                an = a.top();
                a.pop();
            }
            if (!b.empty()) {
                bn = b.top();
                b.pop();
            }
            auto sum = an + bn + carry;
            carry = sum >= 10 ? 1 : 0;
            
            auto cn = carry ? sum - 10 : sum;
            auto next = anchor.next;
            anchor.next = new ListNode(cn);
            anchor.next->next = next;
        }
        return anchor.next;
    }
};