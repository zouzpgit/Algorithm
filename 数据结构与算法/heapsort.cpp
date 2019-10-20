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
	//因为你将较大的孩子放到了父节点，但是从父节点换下来的数据放到孩子节点上，
	//此时以这个孩子为父节点的子树不一定还满足大顶堆（局部），所以要往下沉
	if (largest != i){//说明孩子节点有大于父节点的
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
	//先建堆，建完保证arr[0]是最大的
	int heapsize = bulidheap(arr);
	for (int i = arr.size()-1; i > 0; --i){
		//将最大的放到数组末尾
		swap(arr[i], arr[0]);
		heapsize--;
		//继续维护heap,保证arr[o]是大顶堆的最大值
		adjustheap(arr, 0, heapsize);
	}
}

int main()
{
	vector<int > data = { 9, 5, 6, 7, 1, 2, 3, 4, 8 };
	cout << "排序前" << endl;
	for (int i=0; i < data.size(); ++i){
		cout << data[i] << ' ';
	}
	cout << endl;
	heapsort(data);
	cout << "排序后" << endl;
	for (int i=0; i < data.size(); ++i){
		cout << data[i] << ' ';
	}
	return 0;
}
