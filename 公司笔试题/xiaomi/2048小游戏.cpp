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
*С�ף�2048С��Ϸ��2 2 2 2 --> 4 4 0 0
*/


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
vector<string> solution(vector < string > input) {
	vector<string > res;
	for (int i = 0; i<input.size(); ++i){
		string tmp="";
		int cnt = 0;
		string tmpdata = input[i];
		for (int j = 0; j<tmpdata.size();){
			if (tmpdata[j] == '0'){ //��¼0�ĸ���
				cnt++;
				j = j + 2;
				continue;
			}		
			else{
				if (j == tmpdata.size() - 1){//���һ��
					tmp += tmpdata[j]+" ";
					break;
				}
				if (tmpdata[j] == tmpdata[j+2]){			
					tmp += to_string(int(tmpdata[j] - '0') + int(tmpdata[j+2] - '0'))+" ";//�ϲ���һ����cnt++
					cnt++;
					j=j+4;
				}
				else{
					tmp += tmpdata[j];//û�кϲ���������ǰ��
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
/******************************����д����******************************/

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

