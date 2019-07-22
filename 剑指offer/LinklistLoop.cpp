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
			fast = fast->next; //�ٶ���һ��
		else  // �л�
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
	for (int i = 0; i < N; i++){  //��fastָ������N��
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
