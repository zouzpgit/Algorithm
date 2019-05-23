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
	//�ݴ�random������
	vector<RandomListNode*> Rdata;
	RandomListNode *tmp = new RandomListNode(-1);
	RandomListNode *Newhead = new RandomListNode(pHead->label);
	tmp->next = Newhead;
	Rdata.push_back(pHead->random);
	RandomListNode *pNode = pHead->next;
	while (pNode){
		Newhead->next = new RandomListNode(pNode->label);
		Rdata.push_back(pNode->random);  //��random�ŵ�������
		Newhead = Newhead->next;
		pNode = pNode->next;
	}
	//����ѭ������Ժ�ڵ��next�Ѿ��������
	Newhead = tmp->next; //��ͷָ����ָ��ͷ
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