//
// Created by sunsijie on 16-3-8.
//

#include <vector>
#include <iostream>
#include <memory>
#include <cmath>
#include <set>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class comp {
public:
    static bool lessFirst;
    bool operator ()(ListNode* a, ListNode* b)
    {
        if (!a) {
            return false;
        }
        if (!b) {
            return true;
        }
        if (comp::lessFirst) {
            return a->val < b->val;
        } else {
            return a->val > b->val;
        }
    }
};

bool comp::lessFirst = true;

class Solution {
    vector<vector<ListNode*>> tree;
    ListNode* winner;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*, comp> s;
        for (auto& n : lists) {
            if (n) {
                s.insert(n);
            }
        }

        ListNode* res, *step;

        res = step = *s.begin();

        while (!s.empty()) {
            s.erase(s.begin());
            if (step->next) {
                s.insert(step->next);
            }
            auto next = *s.begin();
            step->next = next;
            step = next;
        }

        return res;
    }
};

int main(int argc, char* argv[], char* env[])
{
    Solution so;
    vector<ListNode*> node;
    cout << so.mergeKLists(node) << endl;
}