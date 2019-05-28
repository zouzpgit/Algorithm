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

//�ж������ǲ��Ƕ����������ĺ������
bool VerifySquenceOfBST(vector<int> sequence) {

	int root = sequence.back();//�õ����ĸ��ڵ�
	vector<int > left, right;
	int i = 0;
	for (; i < sequence.size() - 1; i++){
		if (sequence[i] < root)
			left.push_back(sequence[i]);
		else
			break;  //�ҵ�һ�����ȸ��ڵ����ô˵���ҵ�����������������������������������˱ȸ��ڵ�����
	}
	int j = i;
	for (j; j < sequence.size() - 1; j++){
		if (sequence[j] > root)
			right.push_back(sequence[j]);
		else
			return false;  //����������г��ֱȸ�С�ģ���ֱ�ӷ���false��֤�������в��Ǻ����������
	}

	bool leftflag = true;
	if (i > 0)//����˵������������������Ҫ�����ݹ�
		leftflag = VerifySquenceOfBST(left);

	bool rightflag = true;
	if (j>i) //����˵������������������Ҫ�����ݹ�
		rightflag = VerifySquenceOfBST(right);

	return leftflag&&rightflag;

}
