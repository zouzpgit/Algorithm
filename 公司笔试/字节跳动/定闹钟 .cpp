#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
*字节跳动秋招笔试题：定闹钟
*小明会定很多的闹钟，只有在闹钟想的时候他才会醒来并决定起不起床，从他起床到教室需要X分钟，上课时间为当天的A时B分。
*第一个输入：N（闹钟个数）如：3
*接下来时闹钟时间        如： 5 0，6 0，7 0。分别表示早上5点6点7点的闹钟
*再接下来是从起床到教室花费的时间 如：59 ，表示花费59分钟
*最后是上课时间  6 59 .表示上课时间是6点59分
*输出：小明最晚的起床时间。
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
