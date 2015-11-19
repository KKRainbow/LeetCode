/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<tuple>
using namespace std;
class Solution {
	//start before_start end
	typedef tuple<ListNode*, ListNode*, ListNode*> MediaState;
	static inline ListNode* TransferNodeTo(ListNode* pos, ListNode* before_pos, ListNode* before_src)
	{
		if(!before_src || !pos)return nullptr;
		ListNode* src = before_src->next;
		if(!src)return nullptr;
		before_src->next = src->next;
		src->next = pos;
		if(before_pos)before_pos->next = src;
		return src;
	}
	static inline ListNode* PartialSort(ListNode* start, ListNode* before_start, ListNode* end)
	{
		ListNode* before_pos = before_start, *pivot = start;
		ListNode* step = pivot, *pos = pivot;
		while(step && step->next != end)
		{
			if(pivot->val > step->next->val)
			{
				pos = TransferNodeTo(pos, before_pos, step);
			}
			else
			{
				step = step->next;
			}
		}
		return pivot;
	}
	static inline void QuickSort(ListNode* start, ListNode* before_start, ListNode* end)
	{
		if(!start || start == end)return;
		ListNode* middle = nullptr;
		middle= PartialSort(start,before_start,end);
		ListNode* tmp = middle;
		while(middle && middle->next && middle->next->val == middle->val)
		{
			middle = middle->next;
		}
		QuickSort(before_start->next,before_start, tmp);
		QuickSort(middle->next, middle, end);
	}
	public:
	ListNode* sortList(ListNode* head) {
		if(!head)return nullptr;
		ListNode res(*head);
		res.next = head;
		QuickSort(head,&res, nullptr);
		return res.next;
	}
};
