// ali0830.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<stack>
#include<iostream>
#include<unordered_set>

/*
*  题目来源：ali 测试开发笔试题，给一个棋盘字符串board,然后还有一个匹配字符串chars,题目意思是在字符串棋盘里面找到最长符合chars的字符串，
* 比如：board："ABCEDF, CBDAAB, DCBABE"   chars:'A','B' 那么最长的就是AABAB(5)
*/
using namespace std;
// 这里要突破一个思维定式，不要老是认为所有的变量都应该放在main函数里面就是全局变量，这样子的理解其实是错误的，放在main函数和其他函数里的变量都是局部变量
// 局部变量都是存放在栈内存中的，全局变量是放在函数外面的，存放在可读段里面，生存周期是全局（我理解为整个CPP文件）（具体的可以见《程序员的自我修养》），加上static关键字后，变量也存放在可读段
stack<int > len;
int max = 0;
int cnt = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

bool canarrive(vector<vector<char>> & bd, vector<vector<bool >> &vs, unordered_set<char > &myset, int rows, int cols, int now_r, int now_c)
{
	if (now_r < 0 || now_r >= rows) return false;
	if (now_c < 0 || now_c >= cols) return false;
	if (vs[now_r][now_c]) return false;
	if (!(myset.end() != myset.find(bd[now_r][now_c]))) return false;
	return true;
}

void dfs(vector<vector<char>> & bd, vector<vector<bool >> &vs, unordered_set<char > &myset, int rows, int cols, int now_r, int now_c)
{

	if (!canarrive(bd, vs,myset, rows, cols, now_r, now_c)){//不可达
		max=cnt>max?cnt:max;
		return;
	}
	else{
		if (!len.empty())//这里的计数太关键了，想了半天，最后发现因为dfs用的递归，所以用stack来放当前字符的最长长度（栈顶的数就是当前字符串的数字）
			cnt = len.top();
		cnt++;
		len.push(cnt);
		vs[now_r][now_c] = true;
		dfs(bd, vs, myset, rows, cols, now_r + 1, now_c);
		dfs(bd, vs, myset, rows, cols, now_r - 1, now_c);
		dfs(bd, vs, myset, rows, cols, now_r, now_c + 1);
		dfs(bd, vs, myset, rows, cols, now_r, now_c - 1);
		vs[now_r][now_c] = false;
		len.pop();
		return;
	}
	
}


int getmaxlength(string board, string chars)
{
	int row = 0,col=0,res=0,maxres=0;
	int length = board.size();
	for (int i = 0; i <length; ++i)
	{
		if (row == 0 && board[i] >= 'A'&&board[i] <= 'Z')
			col++;//找到有多少列
		if (board[i] == ',')
			row++;//找到有多少行
	}
	row++;
	unordered_set<char > myset;
	string pattern=chars;
	for (int i = 0; i < chars.size(); ++i){
		myset.insert(chars[i]);
	}

	vector<vector<char>> bd(row,vector<char>(col,'.'));
	vector<vector<bool>> visited(row , vector<bool>(col , false));
	int j = 0,k=0;
	for (int i = 0; i <length; ++i)
	{
		if (board[i] >= 'A'&&board[i] <= 'Z'){
			bd[j][k++] = board[i];
		}
			
		if (board[i] == ','){
			j++;
			k = 0;
		}
			
	}
	
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < col; ++j){
			cnt = 0;
			dfs(bd, visited, myset, row, col, i, j);
		}
	}
	cout << max << endl;
	return 0;
}

int main()
{
	/*unordered_set<char > myset; hash_set
	
	myset.insert('C');
	myset.insert('B');
	myset.insert('A');
	myset.insert('B');
	unordered_set<char >::iterator f = myset.find('B');*/

	
	int res = getmaxlength("ABCEDF, CBDAAB, DCBABE", "A,B");
	return 0;
}