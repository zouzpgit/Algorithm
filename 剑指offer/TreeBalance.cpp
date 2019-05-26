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


//计算二叉树的深度
int TreeDepth(TreeNode* pRoot)
{
	//思路：从尾到头计数，这样子的话，就不用想着要从函数里面传深度数据进去了
	if (pRoot == NULL)
		return 0;
	int leftDepth = TreeDepth(pRoot->left);
	int rightDepth = TreeDepth(pRoot->right);

	return (leftDepth>rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

//判断平衡二叉树，稍微好一点的解法，直接往底下冲，有一个不符合平衡二叉树的特点就不用继续递归了
bool IsBalance(TreeNode* pRoot, int *depth)
{
	if (pRoot == NULL){
		*depth = 0;
		return true;
	}
	int left, right;
	//一开始就直接往下一直走，先不用记录上层的深度数据
	if (IsBalance(pRoot->left, &left) && IsBalance(pRoot->right, &right)){
		int dif = left - right;
		if (dif >= -1 && dif <= 1){
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false; //子要达到此处一次，那么后面就都不用继续进if()了
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	int depth;
	return IsBalance(pRoot, &depth);
}



//判断平衡二叉树，最辣鸡暴力的解法，从上到下，会重复把下面的节点遍历很多次
bool IsBalanced_Solution(TreeNode* pRoot) {
	//能找到最底下就说明你前面的都是平衡的，所以此处返回的是true
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
