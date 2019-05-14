#include "stdafx.h"
#include<vector>
#include<stack>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	if (pListHead == nullptr)
		return nullptr;
	ListNode *behind, *ahead;
	behind = ahead = pListHead;
	int i = 0;
	while (i<k)//ahead 先走k步
	{
		if (ahead){ // 防止走K步，直接给走超了。
			ahead = ahead->next;
			i++;
		}
		else //K步还没走完，结果直接到头了，所以返回null
			return nullptr;

	}
	while (ahead){
		ahead = ahead->next;
		behind = behind ->next;
	} //behind 此时对应的就是倒数第K个节点
	return behind;
}

int main()
{
	return 0;

}