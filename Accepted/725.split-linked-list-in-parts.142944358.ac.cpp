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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int num = 0;
        auto step = root;
        while (step) {
            num++;
            step = step->next;
        }
        step = root;
        int per = num / k;
        int remain = num - per * k;
        while (k--) {
            auto tmp = per;

            if (remain-- > 0) {
                tmp++;
            }
            auto head = step;
            while (--tmp > 0) {
                if (step) {
                    step = step->next;
                }
            }
            auto prev = step;
            if (step) {
                step = step->next;
            }
            if (prev) {
                prev->next = nullptr;
            }
            res.push_back(head);
        }
        return res;
    }
};
