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
	if (pNode == NULL) //递归结束条件
		return;
	TreeNode *pCurrent = pNode;

	if (pCurrent->left != NULL){
		ConvertNode(pCurrent->left, pLastNode);
	}

	//因为是中序遍历，所以处理顺序肯定是左中右，那么最新处理好结点的更新顺序肯定是左中右
	pCurrent->left = *pLastNode;  //当左遍历完成以后，开始处理最最左边的（最小的）的双向链表，left即代表当前点的前驱是最新的处理好的结点
	if (*pLastNode != NULL){
		(*pLastNode)->right = pCurrent; //将最新处理好的结点的left与当前结点相连接，也即，最新处理好的结点的后续是当前结点
	}
	*pLastNode = pCurrent;//Current 与前面的最新结点的链接已经完毕（前驱与后继已经处理完成），因此，此时的最新处理好的结点pLastNode要更新为Current

	if (pCurrent->right != NULL){//最后处理好的结点一定是某一局部子树的右节点，因此，该右结点（pLastNode）肯定会和其根结点相连接，则又是左->中的连接 
		ConvertNode(pCurrent->right, pLastNode);
	}
	//当整个数的左子树处理完成以后，那么最新处理好的结点就是整个树的根节点，因此根结点最后直接与右子树里面的最最左边的结点相连接，也右子树的局部最小结点
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	TreeNode* PLastNode = NULL;  //最新被处理好的结点
	ConvertNode(pRootOfTree, &PLastNode);

	TreeNode* Head = PLastNode; //此时的头节点等于最新处理的结点

	while (Head != NULL&&Head->left != NULL){
		Head = Head->left;
	}

	return Head;
}
