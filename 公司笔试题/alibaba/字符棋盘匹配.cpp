// ali0830.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<vector>
#include<stack>
#include<iostream>
#include<unordered_set>

/*
*  ��Ŀ��Դ��ali ���Կ��������⣬��һ�������ַ���board,Ȼ����һ��ƥ���ַ���chars,��Ŀ��˼�����ַ������������ҵ������chars���ַ�����
* ���磺board��"ABCEDF, CBDAAB, DCBABE"   chars:'A','B' ��ô��ľ���AABAB(5)
*/
using namespace std;
// ����Ҫͻ��һ��˼ά��ʽ����Ҫ������Ϊ���еı�����Ӧ�÷���main�����������ȫ�ֱ����������ӵ������ʵ�Ǵ���ģ�����main����������������ı������Ǿֲ�����
// �ֲ��������Ǵ����ջ�ڴ��еģ�ȫ�ֱ����Ƿ��ں�������ģ�����ڿɶ������棬����������ȫ�֣������Ϊ����CPP�ļ���������Ŀ��Լ�������Ա��������������������static�ؼ��ֺ󣬱���Ҳ����ڿɶ���
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

	if (!canarrive(bd, vs,myset, rows, cols, now_r, now_c)){//���ɴ�
		max=cnt>max?cnt:max;
		return;
	}
	else{
		if (!len.empty())//����ļ���̫�ؼ��ˣ����˰��죬�������Ϊdfs�õĵݹ飬������stack���ŵ�ǰ�ַ�������ȣ�ջ���������ǵ�ǰ�ַ��������֣�
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
			col++;//�ҵ��ж�����
		if (board[i] == ',')
			row++;//�ҵ��ж�����
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