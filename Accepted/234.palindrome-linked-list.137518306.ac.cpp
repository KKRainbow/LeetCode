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
    bool isPalindrome(ListNode* head) {
        if (!head || !(head->next)) {
            return true;
        }
        // 找中心的过程中，把前半段翻转了，然后直接比较就行
        ListNode *newHead = nullptr, *slow = head, *fast = head, *tmp = head;
        while (fast) {
            if (fast->next == nullptr) break;
            tmp = fast->next;
            fast = tmp->next;
            
            auto tmp = slow->next;
            slow->next = newHead;
            newHead = slow;
            slow = tmp;
        }
        if (fast) {
            slow = slow->next;
        }
        while (newHead) {
            if (newHead->val != slow->val) return false;
            newHead = newHead->next;
            slow = slow->next;
        }
        return true;
    }
};