#include "stdafx.h"
#include<vector>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	//if (pHead == NULL || pHead->next == NULL)
		//return NULL;
	ListNode *fast, *slow, *mark = nullptr;
	slow = pHead;
	fast = pHead->next;
	while (1)
	{
		if (fast == NULL || slow == NULL)
			return NULL;
		fast = fast->next;
		slow = slow->next;

		if (fast != slow)
			fast = fast->next; //再多走一步
		else  // 有环
		{
			mark = slow; break;
		}
			
	}
	ListNode *p = mark->next;
	int N = 1;
	while (p!=mark)
	{
		p = p->next;
		N++;
	}
	fast = slow = pHead;
	for (int i = 0; i < N; i++){  //让fast指针先走N步
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
