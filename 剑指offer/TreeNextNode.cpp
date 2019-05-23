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

//好难！！！
//可以分为两个大类，1.当前节点有右孩子；2.当前节点没有右孩子
//1.当前节点有右孩子：那么走到右孩子的子树（right）当中去，然后right疯狂向左走，直到right当前左孩子为NULL;
//那么right即为当前节点的在中序遍表中的下一个节点。
//2.当前节点没有右孩子：首先保证当前节点的父节点是存在的，不然直接返回NULL，接下来就是找left是自己父节点的左孩子
//只要left是其父节点的右孩子，那么left疯狂往上走，直到left是其父节点的左孩子，那么此时left的父节点就是
//当前节点的在中序遍表中的下一个节点。

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	TreeLinkNode *pNext = NULL;
	if (pNode->right != NULL){//当前节点有右孩子
		TreeLinkNode *pright = pNode->right;
		while (pright->left){
			pright = pright->left;
		}
		pNext = pright;
	}
	else if (pNode->next != NULL){//当前节点没有右孩子，并且保证当前节点的父亲节点是非空的，不然直接赏你一个NULL;
		TreeLinkNode *pleft = pNode->next; //left为当前节点的父节点
		TreeLinkNode *pcurrent = pNode;
		while (pleft&&pcurrent == pleft->right){//只要当前节点是其父节点的右孩子，就继续往上走
			pcurrent = pleft;
			pleft = pleft->next;
		}
		pNext = pcurrent;
	}
	return pNext;//直接赏给你的

}