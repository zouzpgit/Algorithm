#include "stdafx.h"
#include <iostream>
#include <vector>
#include <numeric>
#include<string>
#include<algorithm>
#include <limits>

/*
*小米：最长递增子序列的应用
*/

using namespace std;

int getdizeng(vector<int > &da)
{
	vector<int > dp(da.size(), 0);
	dp[0] = 1;
	int res=0;
	for (int i = 1; i < da.size(); ++i){
		int max = 0;
		for (int j = 0; j < i; ++j){
			if (da[j]<da[i] && dp[j]>max)
				max = dp[j];
		}
		dp[i] = max + 1;
		res = dp[i]>res ? da[i] : res;
	}
	return res;
}

int getdijian(vector<int > &da)
{
	vector<int > dp(da.size(), 0);
	dp[0] = 1;
	int res = 0;
	for (int i = 1; i < da.size() ; ++i){
		int max = 0;
		for (int j = 0; j < i; ++j){
			if (da[j]>da[i] && dp[j]>max)
				max = dp[j];
		}
		dp[i] = max + 1;
		res = dp[i]>res? dp[i] : res;
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int > data;
	for (int i = 0; i<N; ++i){
		int tmp;
		cin >> tmp;
		data.push_back(tmp);
	}
	int zeng = getdizeng(data);
	int jian = getdijian(data);
	return data.size() - (zeng > jian ? zeng : jian);
}