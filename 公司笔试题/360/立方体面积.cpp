// 360笔试0815.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

/*
* 360 立方体算面积，给出N*M的矩形区域，给出一个Aij高度（底面积为1（1*1）的立方体）
* 输入：N M
*      A11 A12 A....A1M
*       .
*       .
*      An1 ......
* 样例：输入： 2 2
*			  2 1
*			  1 1
*	   输出： 20
*/


using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int >> cube(N, vector<int >(M, 0));
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			int tmp;
			cin >> tmp;
			cube[i][j] = tmp;
		}
	}
	
	int res = 0;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			//从前往后扫描
			if (i == 0) 
				res += cube[i][j];
			else{
				if (cube[i - 1][j] < cube[i][j])//当前的高度要大于前面一个
					res += cube[i][j] - cube[i - 1][j];
			}

			//从后往前扫描
			if (i == N - 1)
				res += cube[i][j];
			else{
				if (cube[i + 1][j] < cube[i][j])//当前的高度要大于前面一个
					res += cube[i][j] - cube[i + 1][j];
			}

			//从左往右扫描
			if (j == 0)
				res += cube[i][j];
			else{
				if (cube[i][j - 1] < cube[i][j])//当前的高度要大于前面一个
					res += cube[i][j] - cube[i][j - 1];
			}

			//从右往左扫描
			if (j == M - 1)
				res += cube[i][j];
			else{
				if (cube[i][j + 1] < cube[i][j])//当前的高度要大于前面一个
					res += cube[i][j] - cube[i][j + 1];
			}
		}
	}

	int result = M*N * 2 + res;
	cout << result << endl;
	return 0;
}
