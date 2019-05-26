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
		qji.push(pRoot); //第1层
	}
	while (!qji.empty() || !qou.empty())
	{
		while (!qji.empty()){
			//奇数层,每次都要去栈顶的
			TreeNode* node = qji.top();
			tmpji.push_back(node->val);
			//奇数层对下一层的入栈顺序是先左后右
			if (node->left != NULL)//左右子树入队列的顺序和偶数层相反 
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
			//偶数层 ，每次都要去栈顶的
			TreeNode* node = qou.top();
			tmpou.push_back(node->val);
			//入栈的左右顺序要相反，此时是先右后左，偶数层对下一层的入栈顺序是先右后左
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