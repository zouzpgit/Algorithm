// DPlearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


int getMax(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

//问题来自于https://www.cnblogs.com/little-YTMM/p/5372680.html

//最长递增子序列（Longest Increasing Subsequence）
//如果ai>=aj，则可以将ai放到b[j]的后面，得到比b[j]更长的子序列。从而：b[i] = max{b[j]}+1. s.t. A[i] > A[j] && 0 <= j < i.

//找到LIS的最大长度
int LIS(vector<int > A)
{
	if (A.size() == 0)
		return 0;
	vector<int > B(A.size());
	B[0] = 1;//第一个的长度为1
	int result = 1;
	for (int i = 1; i < A.size(); i++){
		int max = -1;
		for (int j = 0; j < i; j++){
			if (A[j]<A[i] && B[j]>max)
				max = B[j];
		}
		B[i] = max + 1; //状态转移公式
		result = getMax(result, B[i]);
	}
	return result;
}

vector<vector<int>> LISSelf(vector<int > A)
{
	vector<vector<int>> data(A.size());
	if (A.size() == 0)
		return data;
	

	vector<int > B(A.size());
	vector<int > B1(A.size());
	B[0] = 1;//第一个的长度为1
	B1[0] = -1;//第一个前驱为-1
	int result = 1, index = 0;
	for (int i = 1; i < A.size(); i++){
		int max = 0;
		bool flag = false;
		for (int j = 0; j < i; j++){
			if (A[j]<A[i] && B[j]>max){
				flag = true;
				max = B[j];
				B1[i] = j;
			}

		}
		if (flag == false){ B1[i] = -1; }//这个就是没有前驱，貌似不可能哦
		B[i] = max + 1; //状态转移公式


		if (result < B[i]){
			result = B[i];
			index = i;
		}
	}
	for (int i = 0; i < A.size(); i++){
		data[i].push_back(A[i]);
		for (index=B1[i]; index >= 0;)
		{
			data[i].push_back(A[index]);
			index = B1[index];
		}
	}

	return data;
}


//字符串混编，问题来自于https://www.nowcoder.com/profile/388457713/codeBookDetail?submissionId=47036807

bool chkMixture(string A, int n, string B, int m, string C, int v) {
	if (n + m != v)
	{
		return false;
	}
	vector<vector<bool >> dp(n+1);

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			dp[i].push_back(false);
		}
	}
	dp[0][0] = true;
	//初始化第0行
	for (int i = 1; i <= n; i++){
		if (B[i - 1] == C[i - 1]){
			dp[0][i] = true;
		}
		else
			break;
	}

	//初始化第0列
	for (int i = 1; i <= m; i++){
		if (A[i - 1] == C[i - 1]){
			dp[i][0] = true;
		}
		else
			break;
	}

	//开始状态转移方程

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (!dp[i][j]){
				if (dp[i - 1][j] && A[i - 1] == C[i + j - 1])
					dp[i][j] = true;
				if (dp[i][j - 1] && B[j - 1] == C[i + j - 1])
					dp[i][j] = true;
			}
		}
	}

	return dp[n][m];
}


int pailieC(int N1, int N2){
	int fenzi = 1, fenmu = 1;
	for(int i = N2; i>0; i--){
		fenzi *= N1--;
	}
	for(int i = N2; i>0; i--){
		fenmu *= N2--;
	}
	return fenzi/fenmu;
}

//牛客网，跳台阶问题

int jumpFloorok(int number) {
	if (number <= 2)
		return number;
	else{
		int num1 = 0, Max_num2 = 0,total = 0, stepnum = 0;
		Max_num2 = number / 2;
		for(int i = Max_num2; i >= 1; i--){
			num1 = number - i * 2;
			total = num1 + i;
			stepnum += pailieC(total, i);
		}
		return stepnum+1;
	}

}

int JumpFloor(int target) {
	if (target <= 0) {
		return -1;
	}
	else if (target == 1) {
		return 1;
	}
	else if (target == 2) {
		return 2;
	}
	else {
		return  JumpFloor(target - 1) + JumpFloor(target - 2);
	}
}

int main()
{
	//vector<int > a = { 1, 4, 6, 2, 8, 9, 7 };
	//int data1 = LIS(a);
	//vector<vector<int>> data2 = LISSelf(a);
	//vector<vector<int> > dp(5+ 1, vector<int>(7, 1));

	//bool data = chkMixture("ABC", 3, "AABC", 4, "AAABCBC", 7);

	int data = JumpFloor(39);

	return 0;
}