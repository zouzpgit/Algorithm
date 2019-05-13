#include "stdafx.h"
#include<algorithm>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
	//排序后查找重复元素
	if (length <= 0)
	{
		*duplication = NULL;
		return false;
	}
	sort(numbers, numbers + length);
	bool flag = false;
	int i = 1;
	for (; i<length; i++){
		*duplication = numbers[i-1];
		if (numbers[i] == *duplication){
			*duplication = numbers[i];
			flag = true; break;
		}
	}
	if (i == length){
		*duplication = NULL;
		flag = false;
	}
	return flag;
}

bool duplicate1(int numbers[], int length, int* duplication) {
	//hash表的解法
	if (numbers==nullptr||length <= 0)
	{
		*duplication =-1;
		return false;
	}
	int num = 0,i=0;
	for (; i < length; i++){
		num = numbers[i];
		if (num == i) continue;
		else{
			if (num == numbers[num])
			{
				*duplication = num;
				return true;
			}
			else{
				swap(num, numbers[num]);
			}
		}
	}
	if (i == length){
		*duplication = -1;
		return  false;
	}
}

/*int main()
{
	int arr[] = {2,3,1,0,2,5,3};
	int res=0;
	bool data = duplicate1(arr,7,&res);
	return 0;
}*/