#include "stdafx.h"
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


//1 ����������
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	while (pHead1)
	{
		ListNode *p = pHead2;
		while (p){
			if (pHead1 == p)
				return pHead1;;
			p = p->next;
		}
		pHead1 = pHead1->next;
	}
	return NULL;
}

//2 �ռ任ʱ�� ��ʹ��ջ
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	stack<ListNode*> Node1, Node2;
	ListNode *p1 = pHead1, *p2 = pHead2, *FCP;
	//�ռ�O(m+n) ,ʱ��O(m+n)
	while (p1){
		Node1.push(p1);
		p1 = p1->next;
	}
	while (p2){
		Node2.push(p2);
		p2 = p2->next;
	}
	FCP = nullptr;
	while (!Node1.empty() && !Node2.empty()){
		if (Node1.top() != Node2.top()){
			break;
		}
		FCP = Node1.top();
		Node1.pop();
		Node2.pop();
	}
	return FCP;
}

//3 ʱ��ͬ����O(m+n)������N��
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
		return NULL;
	ListNode *p1 = pHead1, *p2 = pHead2;
	int length1 = 0, length2 = 0;
	//��������ĳ��ȣ�ʱ��O(m+n)
	while (p1){
		length1++;
		p1 = p1->next;
	}
	while (p2){
		length2++;
		p2 = p2->next;
	}
	p1 = pHead1, p2 = pHead2;//p1,p2�ص�ͷ�ڵ�
	int N = length1 - length2;
	if (N>0){ //����1�ϳ�
		for (int i = 0; i < N; i++)
			p1 = p1->next;
	}
	else if (N<0){  //����2�ϳ�
		int M = -N;
		for (int i = 0; i < M; i++)
			p2 = p2->next;
	}
	while (p1&&p2){
		if (p1 != p2){
			p1 = p1->next;
			p2 = p2->next;
		}
		else{
			return p1;
		}
	}
	return NULL;
}