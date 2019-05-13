#include "stdafx.h"
#include<vector>
#include<stack>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


vector<int> printListFromTailToHead1(ListNode* head){
	//反转链表的做法
	ListNode  *p=nullptr,*q=nullptr,*pr=nullptr;
	p = head;
	head = nullptr;
	while (p){
		pr = p->next;
		p->next = q;
		q = p;
		p = pr;
	}
	head= q;
	vector<int > data;
	ListNode *pt = head->next;
	while (pt){
		data.push_back(pt->val);
		pt = pt->next;
	}
	return data;

}

vector<int> printListFromTailToHead2(ListNode* head){
	//不改变链表结构的做法，用栈处理
	stack<ListNode*> nodes;
	ListNode *p = head,*q=nullptr;
	while (p != nullptr){
		nodes.push(p);
		p = p->next;
	
	}
	vector<int > data;
	while (!nodes.empty()){
		q = nodes.pop();
		data.push_back(q->val);
	}
	return data;

}
