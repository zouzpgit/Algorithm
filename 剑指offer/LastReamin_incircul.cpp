#include"stdafx.h"
#include<vector>
#include<string>
#include<list>
#include<algorithm>


/*
* ��Ŀ: ԲȦ�����ʣ�µ�����
*
* ����: ����һ������n(������Ϊ�Ǹ�����һ�������ŵ��Ǵ�0-n-1�����֣������������������β�����ġ����ָ��һ����m��Ȼ��ͷ��ʼ����0.1...m-1��
* �������не�m-1������Ҫɾ������Ȼ���m-1����һ����ʼ��0����������ѭ����ֱ��������ֻʣ���һ����
*
* ˼·: ģ�ⷨ���Ͱ�����Ŀ����˼·��д������Ҫ������β�����ⲿ�ֵĹ���
*/

using namespace std;

int LastRemaining_Solution(int n, int m)
{
	if (n == 0 || m == 0)
		return -1;
	list<int > childnum;
	for (int i = 0; i<n; ++i){//�������ǵı��װ�뵽list��
		childnum.push_back(i);
	}
	list<int >::iterator ptr = childnum.begin(), preptr = ptr;
	preptr++;
	int k = 0;
	while (1){
		if (k == m - 1){               //�ҵ���m�������ˣ�ɾ����
			ptr = childnum.erase(ptr); //ɾ����ָ����һ��Ԫ��
			//������k
			k = 0;
		}
		if (ptr == childnum.end())//ָ��ָ����ĩβ������Ҫ����ָ����
			ptr = childnum.begin();
		preptr = ptr;
		ptr++;
		k++;
		if (ptr == childnum.end() && preptr == childnum.begin())//�����ǰ��ָ��Ϊ���һ��ָ��������ѭ��
			break;
		if (ptr == childnum.end())//ָ��ָ����ĩβ������Ҫ����ָ����
			ptr = childnum.begin();

	}
	return *preptr;

}