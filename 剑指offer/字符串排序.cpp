#include "stdafx.h"
#include<vector>
#include<string>
#include<algorithm>

/*
* 题目: 字符串的全排列
* 比如：例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
*/

using namespace std;

vector<string > res;

void swap(char & a, char &b)
{
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void  Permut(string &str, int i)
{
	if (i == str.size() - 1){// 递归结束条件：索引已经指向str最后一个元素时
		if (find(res.begin(), res.end(), str) == res.end())
		{
			// 如果res中不存在str，才添加；避免aa和aa重复添加的情况
			res.push_back(str);
		}
	}
	else{
		for (int j = i; j < str.size(); ++j){
			swap(str[i], str[j]);
			Permut(str, i + 1);
			//回溯（或者叫复位）
			swap(str[i], str[j]);
		}
	}

}

vector<string> Permutation(string str) {
	if (str.size() == 0)
		return res;
	Permut(str, 0);
	// 此时得到的result中排列并不是字典顺序，可以单独再排下序
	sort(res.begin(), res.end());
	return res;
}
