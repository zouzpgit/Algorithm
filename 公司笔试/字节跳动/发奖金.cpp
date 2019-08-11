// 字节0811.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

/*
*字节跳动秋招笔试题：发奖金
*根据每个员工的资历来发工资，最少是100，资历老的比资料小的要多100，资历小的比资料老的要少100。
*比如：资历分别是： 4 2 2 1 2 4   则奖金是：300 200 200 100 200 300
*比如：资历分别是： 2 2 2 2 2 2   则奖金是：100 100 100 100 100 100
*输出：发放的总奖金数
*/

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int > Old;
	for (int i = 0; i < N; ++i){
		int tmp;
		cin >> tmp;
		Old.push_back(tmp);
	}
	vector<int > salary(N,100);
	for (int i = 0; i < N-1; ++i)
	{
		if (Old[i + 1]>Old[i])
			salary[i + 1] = salary[i + 1] > (salary[i] + 100) ? salary[i + 1] : (salary[i] + 100);
		else if (Old[i + 1] == Old[i])
			salary[i + 1] = salary[i];
	}
	for (int i = N-1; i >0; --i){
		if (Old[i - 1] > Old[i])
			salary[i - 1] = salary[i - 1] > (salary[i] + 100) ? salary[i - 1] : (salary[i] + 100);
		else if (Old[i - 1] == Old[i])
			salary[i - 1] = salary[i];
	}
	int res = 0;
	for (int i = 0; i < N; ++i){
		res += salary[i];
	}
	cout << res << endl;
	return 0;
}