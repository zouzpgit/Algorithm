// 360����0815.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

/*
* 360 �����������������N*M�ľ������򣬸���һ��Aij�߶ȣ������Ϊ1��1*1���������壩
* ���룺N M
*      A11 A12 A....A1M
*       .
*       .
*      An1 ......
* ���������룺 2 2
*			  2 1
*			  1 1
*	   ����� 20
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
			//��ǰ����ɨ��
			if (i == 0) 
				res += cube[i][j];
			else{
				if (cube[i - 1][j] < cube[i][j])//��ǰ�ĸ߶�Ҫ����ǰ��һ��
					res += cube[i][j] - cube[i - 1][j];
			}

			//�Ӻ���ǰɨ��
			if (i == N - 1)
				res += cube[i][j];
			else{
				if (cube[i + 1][j] < cube[i][j])//��ǰ�ĸ߶�Ҫ����ǰ��һ��
					res += cube[i][j] - cube[i + 1][j];
			}

			//��������ɨ��
			if (j == 0)
				res += cube[i][j];
			else{
				if (cube[i][j - 1] < cube[i][j])//��ǰ�ĸ߶�Ҫ����ǰ��һ��
					res += cube[i][j] - cube[i][j - 1];
			}

			//��������ɨ��
			if (j == M - 1)
				res += cube[i][j];
			else{
				if (cube[i][j + 1] < cube[i][j])//��ǰ�ĸ߶�Ҫ����ǰ��һ��
					res += cube[i][j] - cube[i][j + 1];
			}
		}
	}

	int result = M*N * 2 + res;
	cout << result << endl;
	return 0;
}
