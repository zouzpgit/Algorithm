#include"stdafx.h"
#include<vector>
#include<string>
#include<list>
#include<algorithm>


/*
* 题目: 圆圈中最后剩下的数字
*
* 描述: 给出一个数字n(可以认为是给出了一个数组存放的是从0-n-1的数字），但是这个数组是首尾相连的。随机指定一个数m，然后头开始报数0.1...m-1，
* 当数组中叫到m-1的数字要删除掉，然后从m-1的下一个开始从0报数，依次循环，直到数组中只剩最后一个数
*
* 思路: 模拟法，就按照题目给的思路来写，就是要处理首尾相连这部分的工作
*/

using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n == 0 || m == 0)
		return -1;
	list<int > childnum;
	for (int i = 0; i<n; ++i){//将孩子们的编号装入到list中
		childnum.push_back(i);
	}
	list<int >::iterator ptr = childnum.begin(), preptr = ptr;
	preptr++;
	int k = 0;
	while (1){
		if (k == m - 1){               //找到第m个孩子了，删除掉
			ptr = childnum.erase(ptr); //删除后指向下一个元素
			//更新与k
			k = 0;
		}
		if (ptr == childnum.end())//指针指向了末尾，则需要重新指回来
			ptr = childnum.begin();
		preptr = ptr;
		ptr++;
		k++;
		if (ptr == childnum.end() && preptr == childnum.begin())//如果当前的指针为最后一个指针则跳出循环
			break;
		if (ptr == childnum.end())//指针指向了末尾，则需要重新指回来
			ptr = childnum.begin();

	}
	return *preptr;

}