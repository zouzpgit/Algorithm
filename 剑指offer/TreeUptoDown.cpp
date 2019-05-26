#include "stdafx.h"
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int > data;
	queue<TreeNode* >treeq;
	if (root == NULL)
		return data;
	else
		treeq.push(root);
	while (!treeq.empty()){
		TreeNode* node=treeq.front();
		data.push_back(node->val);
		if (node->left!=NULL)
			treeq.push(node->left);
		if (node->right!=NULL)
			treeq.push(node->right);
		treeq.pop();
	}
	return data;

}

vector<vector<int> > Printzhi(TreeNode* pRoot) {
	vector<vector< int >> data;
	vector<int > tmpji, tmpou;
	stack<TreeNode* > qji, qou;
	if (pRoot == NULL)
		return data;
	else{
		qji.push(pRoot); //��1��
	}
	while (!qji.empty() || !qou.empty())
	{
		while (!qji.empty()){
			//������,ÿ�ζ�Ҫȥջ����
			TreeNode* node = qji.top();
			tmpji.push_back(node->val);
			//���������һ�����ջ˳�����������
			if (node->left != NULL)//������������е�˳���ż�����෴ 
				qou.push(node->left);
			if (node->right != NULL)
				qou.push(node->right);

			qji.pop();
		}
		if (!tmpji.empty())
		{
			data.push_back(tmpji);
			tmpji.clear();
		}
		while (!qou.empty()){
			//ż���� ��ÿ�ζ�Ҫȥջ����
			TreeNode* node = qou.top();
			tmpou.push_back(node->val);
			//��ջ������˳��Ҫ�෴����ʱ�����Һ���ż�������һ�����ջ˳�������Һ���
			if (node->right != NULL)
				qji.push(node->right);
			if (node->left != NULL)
				qji.push(node->left);
			qou.pop();
		}
		if (!tmpou.empty()){
			data.push_back(tmpou);
			tmpou.clear();
		}

	}
	return data;
}