#include "stdafx.h"
#include<vector>

using namespace std;

int getnum(int row, int col)
{
	int sum = 0, sum_row=0, sum_col = 0;
	while (row%10)
	{
		sum_row += row % 10;//ȡ���λ��
		row = row / 10;
	}
	while (col% 10)
	{
		sum_col += col % 10;//ȡ���λ��
		col = col / 10;
	}
	return sum_row + sum_col;

}

bool CanArrive(int threshold, vector<bool> &visited,int rows, int cols, int now_row, int now_col)
{
	return now_row>=0 && now_row <= rows&& now_col>=0 && now_col <= cols&&
		!visited[now_row*cols + now_col] && getnum(now_row, now_col) <= threshold;//���㵱ǰ��������ֵ��[0��max]��δ�������ҵ�ǰ��������ֵ֮��С��threshold
}

int dfs_Count(int threshold, vector<bool> &visited,int rows, int cols, int now_r, int now_c)
{
	int count = 0;
	if (CanArrive(threshold, visited,rows, cols, now_r, now_c))
	{
		visited[now_r*cols + now_c] = true;
		count = 1 + dfs_Count(threshold, visited, rows, cols, now_r + 1, now_c) +
			dfs_Count(threshold, visited, rows, cols, now_r - 1, now_c) +
			dfs_Count(threshold, visited, rows, cols, now_r, now_c + 1) +
			dfs_Count(threshold, visited, rows, cols, now_r, now_c - 1);
	}
	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	int res = 0;
	vector<bool> Visited(rows*cols, false);
	res = dfs_Count(threshold, Visited, rows, cols, 0, 0);
	return res;

}