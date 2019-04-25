#include "stdafx.h"
#include <iostream>
using namespace std;

/* ⽤于要排序数组个数最⼤值，可根据需要修改 */
#define MAXSIZE 10
typedef struct
{
	/* ⽤于存储要排序数组，r[0]⽤作哨兵或临时变量 */
	int r[MAXSIZE ];
	/* ⽤于记录顺序表的⻓度 */
	int length;
} SqList;

void swap(SqList *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

/* 对顺序表L作冒泡排序 */
void BubbleSort2(SqList *L)
{
	int i, j;
	int cycletimes = 0;
	/* flag⽤来作为标记 */
	BOOL flag = TRUE;
	/* 若flag为true说明有过数据交换，否则停⽌循环 */
	for (i = 1; i < L->length&&flag; i++)
	{
		/* 初始为false */
		flag = FALSE;
		for (j = L->length - 1; j >= i; j--)
		{
			cycletimes++;
			if (L->r[j] > L->r[j + 1])
			{
				/* 交换L->r[j]与L->r[j+1]的值 */
				swap(L, j, j + 1);
				/* 如果有数据交换，则flag为true */
				flag = TRUE;
			}
		}
	}
}

/* 对顺序表L作插入排序 */
void InsertSort(SqList *L)
{
	int i, j;
	for (i = 2; i <= L->length; i++)
	{
		/* 需将L->r[i]插⼊有序⼦表 */
		if (L->r[i] < L->r[i - 1])
		{
			/* 设置哨兵 */
			L->r[0] = L->r[i];
			for (j = i - 1; L->r[j] > L->r[0]; j--)
				/* 记录后移 */
				L->r[j + 1] = L->r[j];
			/* 插⼊到正确位置 */
			L->r[j + 1] = L->r[0];
		}
	}
}

/* 对顺序表L作希尔排序 */
void ShellSort(SqList *L)
{
	int i, j;
	int increment = L->length;
	do
	{
		/* 增量序列 */
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= L->length; i++)
		{
			if (L->r[i] < L->r[i - increment])
			{
				/* 需将L->r[i]插⼊有序增量⼦表 */
				/* 暂存在L->r[0] */
				L->r[0] = L->r[i];
				for (j = i - increment; j > 0 &&
					L->r[0] < L->r[j]; j -= increment)
					/* 记录后移，查找插⼊位置 */
					L->r[j + increment] = L->r[j];
				/* 插⼊ */
				L->r[j + increment] = L->r[0];
			}

		}
	}
	while (increment > 1);
}



/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的
TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	/* 将SR中记录由⼩到⼤归并⼊TR */
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			/* 将剩余的SR[i..m]复制到TR */
			TR[k + l] = SR[i + l];
	}
	if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			/* 将剩余的SR[j..n]复制到TR */
			TR[k + l] = SR[j + l];
	}
}


/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAXSIZE + 1];
	if (s == t)
		TR1[s] = SR[s];
	else
	{
		/* 将SR[s..t]平分为SR[s..m]和SR[m+1..t] */
		m = (s + t) / 2;
		/* 递归将SR[s..m]归并为有序的TR2[s..m] */
		MSort(SR, TR2, s, m);
		/* 递归将SR[m+1..t]归并为有序TR2[m+1..t] */
		MSort(SR, TR2, m + 1, t);
		/* 将TR2[s..m]和TR2[m+1..t] */
		/* 归并到TR1[s..t] */
		Merge(TR2, TR1, s, m, t);
	}
}


/* 对顺序表L作归并排序 */
void MergeSort(SqList *L)
{
	MSort(L->r, L->r, 1, L->length);
}


/* 交换顺序表L中⼦表的记录，使枢轴记录到位，
并返回其所在位置 */
/* 此时在它之前（后）的记录均不⼤（⼩）于
它。 */
int Partition(SqList *L, int low, int high)
{
	int pivotkey;
	/* ⽤⼦表的第⼀个记录作枢轴记录 */
	pivotkey = L->r[low];
	/* 从表的两端交替向中间扫描 */
	while (low < high)
	{
		while (low < high && L->r[high] >= pivotkey)
			high--;
		/* 将⽐枢轴记录⼩的记录交换到低端 */
		swap(L, low, high);
		while (low < high && L->r[low] <= pivotkey)
			low++;
		/* 将⽐枢轴记录⼤的记录交换到⾼端 */
		swap(L, low, high);
	}
	/* 返回枢轴所在位置 */
	return low;
}


/* 对顺序表L中的⼦序列L->r[low..high]作快速排
序 */
void QSort(SqList *L, int low, int high)
{
	int pivot;
	if (low < high)
	{
		/* 将L->r[low..high]⼀分为⼆， */
		/* 算出枢轴值pivot */
		pivot = Partition(L, low, high);
		/* 对低⼦表递归排序 */
		QSort(L, low, pivot - 1);
		/* 对⾼⼦表递归排序 */
		QSort(L, pivot + 1, high);
	}
}



/* 对顺序表L作快速排序 */
void QuickSort(SqList *L)
{
	QSort(L, 1, L->length);
}

int main()
{
	SqList list1;
	int a[10] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	int i;
	for (i = 0; i<10; i++)
	{
		list1.r[i] = a[i];
	}
	list1.length = i-1;

	QuickSort(&list1);


	//MergeSort(&list1);

	

	//ShellSort(&list1);

	//InsertSort(&list1);

	//BubbleSort2(&list1);

	return 0;
}

