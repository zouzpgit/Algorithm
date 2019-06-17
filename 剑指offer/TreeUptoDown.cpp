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

//1.从上往下打印出二叉树的每个节点，同层节点从左至右打印。
vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int > data;
	queue<TreeNode* >treeq;
	if (root == NULL)
		return data;
	else
		treeq.push(root);
	while (!treeq.empty()){//这个是层序遍历
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


//2.从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。和之字打印一个意思
vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int >> data;
	queue<TreeNode* >treeq1, treeq2;
	if (pRoot == NULL)
		return data;
	else
		treeq1.push(pRoot);
	int i = 0;
	vector<int > tmp;
	while (!treeq1.empty() || !treeq2.empty()){
		while (!treeq1.empty()){ //前一层
			TreeNode* node1 = treeq1.front();
			tmp.push_back(node1->val);
			if (node1->left != NULL)
				treeq2.push(node1->left);
			if (node1->right != NULL)
				treeq2.push(node1->right);
			treeq1.pop();
		}
		if (!tmp.empty())
		{
			data.push_back(tmp);
			tmp.clear();
			i++;
		}
		while (!treeq2.empty()){ //后一层
			TreeNode* node2 = treeq2.front();
			tmp.push_back(node2->val);
			if (node2->left != NULL)
				treeq1.push(node2->left);
			if (node2->right != NULL)
				treeq1.push(node2->right);
			treeq2.pop();
		}
		if (!tmp.empty())
		{
			data.push_back(tmp);
			tmp.clear();
			i++;
		}
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
			//奇数层,每次都要取栈顶的
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
			//偶数层 ，每次都要取栈顶的
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