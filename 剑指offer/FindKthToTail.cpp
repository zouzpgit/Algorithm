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
	while (i<k)//ahead ����k��
	{
		if (ahead){ // ��ֹ��K����ֱ�Ӹ��߳��ˡ�
			ahead = ahead->next;
			i++;
		}
		else //K����û���꣬���ֱ�ӵ�ͷ�ˣ����Է���null
			return nullptr;

	}
	while (ahead){
		ahead = ahead->next;
		behind = behind ->next;
	} //behind ��ʱ��Ӧ�ľ��ǵ�����K���ڵ�
	return behind;
}

int main()
{
	return 0;

}