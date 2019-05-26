#include "stdafx.h"
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};


//��������������
int TreeDepth(TreeNode* pRoot)
{
	//˼·����β��ͷ�����������ӵĻ����Ͳ�������Ҫ�Ӻ������洫������ݽ�ȥ��
	if (pRoot == NULL)
		return 0;
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);

	return (leftDepth>rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

//�ж�ƽ�����������΢��һ��Ľⷨ��ֱ�������³壬��һ��������ƽ����������ص�Ͳ��ü����ݹ���
bool IsBalance(TreeNode* pRoot, int *depth)
{
	if (pRoot == NULL){
		*depth = 0;
		return true;
	}
	int left, right;
	//һ��ʼ��ֱ������һֱ�ߣ��Ȳ��ü�¼�ϲ���������
	if (IsBalance(pRoot->left, &left) && IsBalance(pRoot->right, &right)){
		int dif = left - right;
		if (dif >= -1 && dif <= 1){
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false; //��Ҫ�ﵽ�˴�һ�Σ���ô����Ͷ����ü�����if()��
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	int depth;
	return IsBalance(pRoot, &depth);
}



//�ж�ƽ��������������������Ľⷨ�����ϵ��£����ظ�������Ľڵ�����ܶ��
bool IsBalanced_Solution(TreeNode* pRoot) {
	//���ҵ�����¾�˵����ǰ��Ķ���ƽ��ģ����Դ˴����ص���true
	if (pRoot == NULL)
		return true;

	int leftDepth = TreeDepth(pRoot->left);
	int  rightDepth = TreeDepth(pRoot->right);
	
	int dif = leftDepth - rightDepth;

	if (dif>1||dif<-1){
		return false;
	}

	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	
}
