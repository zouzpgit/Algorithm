#include "stdafx.h"
#include<vector>
#include<string>
#include<algorithm>

/*
* ��Ŀ: �ַ�����ȫ����
* ���磺���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��
*/

using namespace std;

vector<string > res;

void swap(char & a, char &b)
{
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void  Permut(string &str, int i)
{
	if (i == str.size() - 1){// �ݹ���������������Ѿ�ָ��str���һ��Ԫ��ʱ
		if (find(res.begin(), res.end(), str) == res.end())
		{
			// ���res�в�����str������ӣ�����aa��aa�ظ���ӵ����
			res.push_back(str);
		}
	}
	else{
		for (int j = i; j < str.size(); ++j){
			swap(str[i], str[j]);
			Permut(str, i + 1);
			//���ݣ����߽и�λ��
			swap(str[i], str[j]);
		}
	}

}

vector<string> Permutation(string str) {
	if (str.size() == 0)
		return res;
	Permut(str, 0);
	// ��ʱ�õ���result�����в������ֵ�˳�򣬿��Ե�����������
	sort(res.begin(), res.end());
	return res;
}
