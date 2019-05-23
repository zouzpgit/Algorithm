#include "stdafx.h"
#include<vector>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

//���ѣ�����
//���Է�Ϊ�������࣬1.��ǰ�ڵ����Һ��ӣ�2.��ǰ�ڵ�û���Һ���
//1.��ǰ�ڵ����Һ��ӣ���ô�ߵ��Һ��ӵ�������right������ȥ��Ȼ��right��������ߣ�ֱ��right��ǰ����ΪNULL;
//��ôright��Ϊ��ǰ�ڵ�����������е���һ���ڵ㡣
//2.��ǰ�ڵ�û���Һ��ӣ����ȱ�֤��ǰ�ڵ�ĸ��ڵ��Ǵ��ڵģ���Ȼֱ�ӷ���NULL��������������left���Լ����ڵ������
//ֻҪleft���丸�ڵ���Һ��ӣ���ôleft��������ߣ�ֱ��left���丸�ڵ�����ӣ���ô��ʱleft�ĸ��ڵ����
//��ǰ�ڵ�����������е���һ���ڵ㡣

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	TreeLinkNode *pNext = NULL;
	if (pNode->right != NULL){//��ǰ�ڵ����Һ���
		TreeLinkNode *pright = pNode->right;
		while (pright->left){
			pright = pright->left;
		}
		pNext = pright;
	}
	else if (pNode->next != NULL){//��ǰ�ڵ�û���Һ��ӣ����ұ�֤��ǰ�ڵ�ĸ��׽ڵ��Ƿǿյģ���Ȼֱ������һ��NULL;
		TreeLinkNode *pleft = pNode->next; //leftΪ��ǰ�ڵ�ĸ��ڵ�
		TreeLinkNode *pcurrent = pNode;
		while (pleft&&pcurrent == pleft->right){//ֻҪ��ǰ�ڵ����丸�ڵ���Һ��ӣ��ͼ���������
			pcurrent = pleft;
			pleft = pleft->next;
		}
		pNext = pcurrent;
	}
	return pNext;//ֱ���͸����

}