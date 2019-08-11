// �ֽ�0811.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

/*
*�ֽ��������б����⣺������
*����ÿ��Ա���������������ʣ�������100�������ϵı�����С��Ҫ��100������С�ı������ϵ�Ҫ��100��
*���磺�����ֱ��ǣ� 4 2 2 1 2 4   �򽱽��ǣ�300 200 200 100 200 300
*���磺�����ֱ��ǣ� 2 2 2 2 2 2   �򽱽��ǣ�100 100 100 100 100 100
*��������ŵ��ܽ�����
*/

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int > Old;
	for (int i = 0; i < N; ++i){
		int tmp;
		cin >> tmp;
		Old.push_back(tmp);
	}
	vector<int > salary(N,100);
	for (int i = 0; i < N-1; ++i)
	{
		if (Old[i + 1]>Old[i])
			salary[i + 1] = salary[i + 1] > (salary[i] + 100) ? salary[i + 1] : (salary[i] + 100);
		else if (Old[i + 1] == Old[i])
			salary[i + 1] = salary[i];
	}
	for (int i = N-1; i >0; --i){
		if (Old[i - 1] > Old[i])
			salary[i - 1] = salary[i - 1] > (salary[i] + 100) ? salary[i - 1] : (salary[i] + 100);
		else if (Old[i - 1] == Old[i])
			salary[i - 1] = salary[i];
	}
	int res = 0;
	for (int i = 0; i < N; ++i){
		res += salary[i];
	}
	cout << res << endl;
	return 0;
}