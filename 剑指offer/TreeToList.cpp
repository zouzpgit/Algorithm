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
void ConvertNode(TreeNode* pNode, TreeNode **pLastNode)
{
	if (pNode == NULL) //�ݹ��������
		return;
	TreeNode *pCurrent = pNode;

	if (pCurrent->left != NULL){
		ConvertNode(pCurrent->left, pLastNode);
	}

	//��Ϊ��������������Դ���˳��϶��������ң���ô���´���ý��ĸ���˳��϶���������
	pCurrent->left = *pLastNode;  //�����������Ժ󣬿�ʼ����������ߵģ���С�ģ���˫������left������ǰ���ǰ�������µĴ���õĽ��
	if (*pLastNode != NULL){
		(*pLastNode)->right = pCurrent; //�����´���õĽ���left�뵱ǰ��������ӣ�Ҳ�������´���õĽ��ĺ����ǵ�ǰ���
	}
	*pLastNode = pCurrent;//Current ��ǰ������½��������Ѿ���ϣ�ǰ�������Ѿ�������ɣ�����ˣ���ʱ�����´���õĽ��pLastNodeҪ����ΪCurrent

	if (pCurrent->right != NULL){//�����õĽ��һ����ĳһ�ֲ��������ҽڵ㣬��ˣ����ҽ�㣨pLastNode���϶���������������ӣ���������->�е����� 
		ConvertNode(pCurrent->right, pLastNode);
	}
	//������������������������Ժ���ô���´���õĽ������������ĸ��ڵ㣬��˸�������ֱ���������������������ߵĽ�������ӣ�Ҳ�������ľֲ���С���
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* PLastNode = NULL;  //���±�����õĽ��
	ConvertNode(pRootOfTree, &PLastNode);

	TreeNode* Head = PLastNode; //��ʱ��ͷ�ڵ�������´���Ľ��

	while (Head != NULL&&Head->left != NULL){
		Head = Head->left;
	}

	return Head;
}
