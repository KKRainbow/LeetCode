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
    pair<ListNode*, ListNode*> helper(ListNode* head, int k) {
        if (!head) return { head, nullptr };
        
        ListNode *prev = nullptr;
        auto step = head;
        while (k--) {
            auto tmp = step->next;
            step->next = prev;
            prev = step;
            step = tmp;
        }
        
        return { prev, head };
    }
    
    pair<bool, ListNode*> getLast(ListNode* head, int k) {
        int tmp = k;
        auto step = head;
        while (tmp) {
            if (!step) {
                break;
            }
            step = step->next;
            tmp--;
        }
        if (tmp) return { false, nullptr };
        else return { true, step };
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto cur = head;
        ListNode* prevTail = nullptr, *realHead = nullptr;
        while (cur) {
            auto tp = getLast(cur, k);
            if (!tp.first) {
                if (prevTail) {
                    prevTail->next = cur;
                }
                break;
            }
            
            auto p = helper(cur, k);
            if (prevTail) {
                prevTail->next = p.first;
            }
            if (!realHead) {
                realHead = p.first;
            }
            if (!p.second) {
                break;
            }
            prevTail = p.second;
            cur = tp.second;
        }
        return realHead ? realHead : head;
    }
};
