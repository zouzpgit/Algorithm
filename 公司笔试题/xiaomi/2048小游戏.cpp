// xiaomi0911.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <numeric>
#include<string>
#include <limits>

using namespace std;

/*
*小米：2048小游戏，2 2 2 2 --> 4 4 0 0
*/


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
vector<string> solution(vector < string > input) {
	vector<string > res;
	for (int i = 0; i<input.size(); ++i){
		string tmp="";
		int cnt = 0;
		string tmpdata = input[i];
		for (int j = 0; j<tmpdata.size();){
			if (tmpdata[j] == '0'){ //记录0的个数
				cnt++;
				j = j + 2;
				continue;
			}		
			else{
				if (j == tmpdata.size() - 1){//最后一个
					tmp += tmpdata[j]+" ";
					break;
				}
				if (tmpdata[j] == tmpdata[j+2]){			
					tmp += to_string(int(tmpdata[j] - '0') + int(tmpdata[j+2] - '0'))+" ";//合并了一个，cnt++
					cnt++;
					j=j+4;
				}
				else{
					tmp += tmpdata[j];//没有合并。继续往前走
					tmp.append(" ");
					j = j + 2;
					continue;
				}
			}
		}
		for (int k = 0; k < cnt; ++k){
			if (k == cnt - 1){
				tmp += to_string(0);
				break;
			}
			tmp  += to_string(0)+' ';
		}
		res.push_back(tmp);
	}
	return res;
}
/******************************结束写代码******************************/

int main() {
	vector<string> res;

	int _input_size = 0;
	cin >> _input_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<string> _input;
	string _input_item;
	for (int _input_i = 0; _input_i<_input_size; _input_i++) {
		getline(cin, _input_item);
		_input.push_back(_input_item);
	}

	res = solution(_input);
	for (int i = 0; i < res.size(); ++i){
		cout << res[i] << endl;
	}
	
	return 0;

}

