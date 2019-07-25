#include "stdafx.h"
#include<vector>

using namespace std;


bool CanArrvie(char* matrix, vector<bool> &visited, int rows, int cols, int now_r, int now_c, char *now, int k)
{
	return now_r >= 0 && now_r < rows&&now_c >= 0 && now_c < cols&&
		!visited[now_r*cols + now_c] && matrix[now_r*cols + now_c] == now[k];
}

bool dfs(char* matrix, vector<bool> &visited, int rows, int cols, int now_row, int now_col, char *now_char, int k)
{

	//如果当前字符str不可达直接返回false
	if (!CanArrvie(matrix, visited, rows, cols, now_row, now_col, now_char, k))
		return false;
	else
	{
		if (k == (int)strlen(now_char) - 1)//已经走到最后一个了，返回true
			return true;
		visited[now_row*cols + now_col] = true;
		if (dfs(matrix, visited, rows, cols, now_row + 1, now_col, now_char, k + 1) ||
			dfs(matrix, visited, rows, cols, now_row - 1, now_col, now_char, k + 1) ||
			dfs(matrix, visited, rows, cols, now_row, now_col + 1, now_char, k + 1) ||
			dfs(matrix, visited, rows, cols, now_row, now_col - 1, now_char, k + 1))//此处只要有一个到达就行
			return true;
	}
	return false;
}

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	bool  res = false;
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			vector<bool> Visited(rows*cols, false);
			if (dfs(matrix, Visited, rows, cols, i, j, str, 0))
				return true;
		}
	}
	return false;
}
};