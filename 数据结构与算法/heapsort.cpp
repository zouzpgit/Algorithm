#include "stdafx.h"
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b)
{
	b = a + b;
	a = b - a;
	b = b - a;
}

void adjustheap(vector<int > &arr,int i,int heapsize)
{
	int left = 2 * i + 1, right = 2 * i + 2, largest = i;
	if (left<heapsize&&arr[left] > arr[largest])
		largest = left;
	if (right<heapsize&&arr[right] > arr[largest])
		largest = right;
	//��Ϊ�㽫�ϴ�ĺ��ӷŵ��˸��ڵ㣬���ǴӸ��ڵ㻻���������ݷŵ����ӽڵ��ϣ�
	//��ʱ���������Ϊ���ڵ��������һ��������󶥶ѣ��ֲ���������Ҫ���³�
	if (largest != i){//˵�����ӽڵ��д��ڸ��ڵ��
		swap(arr[i], arr[largest]);
		adjustheap(arr, largest, heapsize);

	}
}

int bulidheap(vector<int > &arr)
{
	int heapsize = arr.size();
	for (int i = heapsize / 2 - 1; i >= 0; --i){
		adjustheap(arr, i, heapsize);
	}
	return heapsize;
}
void heapsort(vector<int > &arr)
{
	//�Ƚ��ѣ����걣֤arr[0]������
	int heapsize = bulidheap(arr);
	for (int i = arr.size()-1; i > 0; --i){
		//�����ķŵ�����ĩβ
		swap(arr[i], arr[0]);
		heapsize--;
		//����ά��heap,��֤arr[o]�Ǵ󶥶ѵ����ֵ
		adjustheap(arr, 0, heapsize);
	}
}

int main()
{
	vector<int > data = { 9, 5, 6, 7, 1, 2, 3, 4, 8 };
	cout << "����ǰ" << endl;
	for (int i=0; i < data.size(); ++i){
		cout << data[i] << ' ';
	}
	cout << endl;
	heapsort(data);
	cout << "�����" << endl;
	for (int i=0; i < data.size(); ++i){
		cout << data[i] << ' ';
	}
	return 0;
}
