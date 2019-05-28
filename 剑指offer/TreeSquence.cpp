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

//判断序列是不是二叉搜索树的后序遍历
bool VerifySquenceOfBST(vector<int> sequence) {

	int root = sequence.back();//得到最后的根节点
	vector<int > left, right;
	int i = 0;
	for (; i < sequence.size() - 1; i++){
		if (sequence[i] < root)
			left.push_back(sequence[i]);
		else
			break;  //找到一个树比跟节点大，那么说明找到了右子树，或者序列里面的左子树出现了比根节点大的数
	}
	int j = i;
	for (j; j < sequence.size() - 1; j++){
		if (sequence[j] > root)
			right.push_back(sequence[j]);
		else
			return false;  //如果右子树中出现比根小的，则直接返回false，证明该序列不是后序遍历序列
	}

	bool leftflag = true;
	if (i > 0)//初步说明还有左子树，所以要继续递归
		leftflag = VerifySquenceOfBST(left);

	bool rightflag = true;
	if (j>i) //初步说明还有右子树，所以要继续递归
		rightflag = VerifySquenceOfBST(right);

	return leftflag&&rightflag;

}
