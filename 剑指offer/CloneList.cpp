#include "stdafx.h"
#include<vector>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL){
		return NULL;
	}
	//暂存random暴力法
	vector<RandomListNode*> Rdata;
	RandomListNode *tmp = new RandomListNode(-1);
	RandomListNode *Newhead = new RandomListNode(pHead->label);
	tmp->next = Newhead;
	Rdata.push_back(pHead->random);
	RandomListNode *pNode = pHead->next;
	while (pNode){
		Newhead->next = new RandomListNode(pNode->label);
		Rdata.push_back(pNode->random);  //将random放到数组中
		Newhead = Newhead->next;
		pNode = pNode->next;
	}
	//整个循环完成以后节点的next已经复制完成
	Newhead = tmp->next; //将头指针再指回头
	int i = 0;
	pNode = Newhead;
	while (pNode){
		RandomListNode * rand = Rdata[i];
		RandomListNode *p = Newhead;
		while (p&&rand&&rand->label != p->label){
			p = p->next;
		}
		if (rand == NULL)
			pNode->random = NULL;
		else
			pNode->random = p;
		pNode = pNode->next;
		i++;
	}
	return Newhead;
}