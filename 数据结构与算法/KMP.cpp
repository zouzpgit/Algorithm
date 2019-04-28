#include "stdafx.h"
#include <iostream>
#include<string>

using namespace std;

/* 通过计算返回⼦串T的next数组。 */
void get_next(string T, int *next)
{
	int i, j;
	//T[0]中不存放字符串的长度，因此i从0开始，j从-1开始，next数组的从-1开始
	i = 0;
	j = -1;
	next[0] = -1; 

	while (i < T.size() - 1)
	{
		/* T[i]表示后缀的单个字符， */
		/* T[j]表示前缀的单个字符 */
		if (j == -1 || T[i] == T[j])  //j=-1则说明回溯到头了
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			/* 若字符不相同，则j值回溯 */
			j = next[j];
		}

	}
}

/* 返回⼦串T在主串S中第pos个字符之后的位置。
若不存在，则函数返回值为0。 */
/* T⾮空，1≤pos≤StrLength(S)。 */
int Index_KMP(string S,string  T,int pos)
{
	/* i⽤于主串S当前位置下标值，若pos不为1， */
	/* 则从pos位置开始匹配 */
	int i = pos;
	/* j⽤于⼦串T中当前位置下标值 */
	int j = 0;
	/* 定义⼀next数组 */
	int Next[255];
	/* 对串T作分析，得到next数组 */
	get_next(T, Next);

	/* 循环继续 */
	while (i <= S.size() && j <= T.size())
	{
		/* 两字⺟相等则继续，相对于朴素算法增加了 */
		/* j=0判断 */
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		/* 指针后退重新开始匹配 */
		else
		{
			/* j退回合适的位置，i值不变 */
			j = Next[j];
		}
	}
	if (j > T.size())
		return i - T.size()-1;
	else
		return 0;
}

int main()
{
	string Source, Target;
	cin >> Source >> Target;
	int data = Index_KMP(Source, Target, 0);
	return 0;
}