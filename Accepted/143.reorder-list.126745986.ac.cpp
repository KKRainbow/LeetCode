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
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        for (auto h = head; h;  h = h->next) {
            vec.push_back(h);
        }
        int l = 0, h = vec.size() - 1;
        ListNode* tail = nullptr;
        while (l <= h) {
            vec[l]->next = vec[h];
            if (tail) {
                tail->next = vec[l];
            }
            tail = vec[h];
            l++; h--;
        }
        if (tail) tail->next = nullptr;
    }
};