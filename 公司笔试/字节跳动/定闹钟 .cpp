#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
*�ֽ��������б����⣺������
*С���ᶨ�ܶ�����ӣ�ֻ�����������ʱ�����Ż��������������𴲣������𴲵�������ҪX���ӣ��Ͽ�ʱ��Ϊ�����AʱB�֡�
*��һ�����룺N�����Ӹ������磺3
*������ʱ����ʱ��        �磺 5 0��6 0��7 0���ֱ��ʾ����5��6��7�������
*�ٽ������Ǵ��𴲵����һ��ѵ�ʱ�� �磺59 ����ʾ����59����
*������Ͽ�ʱ��  6 59 .��ʾ�Ͽ�ʱ����6��59��
*�����С���������ʱ�䡣
*/

int main()
{
	int N;
	cin >> N;
	vector<int > alarm;
	for (int i = 0; i < N; ++i){
		int hour, minute;
		cin >> hour >> minute;
		alarm.push_back(hour * 60 + minute);
	}
	sort(alarm.begin(), alarm.end());
	int spend;
	cin >> spend;
	int target_hour, target_minute;
	cin >> target_hour >> target_minute;
	int deadline = target_hour * 60 + target_minute;
	int precise = deadline - spend;
	int i = 0;
	for (; i < N; ++i){
		if (alarm[i] == precise){
			cout << alarm[i] / 60 << " " << alarm[i] % 60 << endl;;
			return 0;
		}
		if (alarm[i]>precise){
			break;
		}
	}
	if (i != 0){
		cout << alarm[i - 1] / 60 << " " << alarm[i - 1] % 60 << endl;
	}
	else
	{
		cout << alarm[0] / 60 << " " << alarm[0] % 60 << endl;
	}
	return 0;
}
