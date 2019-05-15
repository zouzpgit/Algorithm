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
	if (pHead == NULL || pHead->next == NULL)
		return NULL;
	ListNode *fast, *slow, *mark = nullptr;
	int N = 0;
	slow = pHead;
	fast = pHead->next;
	while (fast != NULL&&slow != NULL&&fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
		if (fast != slow)
			fast = fast->next; //�ٶ���һ��
	}

	fast = slow = pHead->next;
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

int main()
{

	return 0;	
}
