// GraphLearning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GraphLearning.h"


#include<iostream>
#include<math.h>
#include<vector>
#include<cstring>
#include<assert.h>
#include<algorithm>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define INFINITY 10000


// The one and only application object

CWinApp theApp;

using namespace std;

template<typename T>


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: change error code to suit your needs
			_tprintf(_T("Fatal Error: MFC initialization failed\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: GetModuleHandle failed\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

void swap(int *data1, int *data2)
{
	int temp;
	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void BubbleSort2(int *L,int length)
{
	int i, j;
	/* flag⽤来作为标记 */
	bool flag = TRUE;
	/* 若flag为true说明有过数据交换，否则停⽌循环 */
	for (i = 1; i <length && flag; i++)
	{
		/* 初始为false */
		flag = FALSE;
		for (j =length - 1; j >= i; j--)
		{
			if (L[j-1] > L[j])
			{
				/* 交换L->r[j]与L->r[j-1]的值 */
				swap(&L[j] ,&L[j - 1]);
				/* 如果有数据交换，则flag为true */
				flag = TRUE;
			}
		}
	}
}

/* 建⽴⽆向⽹图的邻接矩阵表示 */
void CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	cout<<"输入顶点数和边数:" <<endl;
	/* 输⼊顶点数和边数 */
	cin >> G->numVertexes >> G->numEdges;
	/* 读⼊顶点信息，建⽴顶点表 */
	for (i = 0; i < G->numVertexes; i++)
		cin >> G->vexs[i];
		//scanf(&G->vexs[i]);
	for (i = 0; i < G->numVertexes; i++)
		for (j = 0; j <G->numVertexes; j++)
			/* 邻接矩阵初始化 */
			if (i == j)
			{
				G->arc[i][j] = 0;    //对角线上的数据为0
			}
			else
				G->arc[i][j] = 10000;
	/* 读⼊numEdges条边，建⽴邻接矩阵 */
	for (k = 0; k < G->numEdges; k++)
	{
		cout << "输入边(vi,vj)上的下标i，下标j和权w:" << endl;
		/* 输⼊边(vi,vj)上的权w */
		cin >> i >> j >> w;

		G->arc[i][j] = w;
		/* 因为是⽆向图，矩阵对称 */
		G->arc[j][i] = G->arc[i][j];
	}
}

/* Prim算法⽣成最⼩⽣成树 */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;

	/* 保存相关顶点下标 */
	int adjvex[MAXVEX] = {0};
	/* 保存相关顶点间边的权值 */
	int lowcost[MAXVEX] = {0};
	/* 初始化第⼀个权值为0，即v0加⼊⽣成树 */
	/* lowcost的值为0，在这⾥就是此下标的顶点已经加⼊⽣成树 */
	lowcost[0] = 0;
	/* 初始化第⼀个顶点下标为0 */
	adjvex[0] = 0;
	/* 循环除下标为0外的全部顶点 */
	for (i = 1; i < G.numVertexes; i++)
	{
		/* 将v0顶点与之有边的权值存⼊数组 */
		lowcost[i] = G.arc[0][i];
		/* 初始化都为v0的下标 */
		adjvex[i] = 0;
	}
	for (i = 1; i < G.numVertexes; i++)
	{
		/* 初始化最⼩权值为∞， */
		/* 通常设置为不可能的⼤数字如32767、65535等 */
		min = 10000;
		j = 1; k = 0;

		// add  找终点
		/* 循环全部顶点 */
		while (j < G.numVertexes)
		{
			/* 如果权值不为0且权值⼩于min */
			if (lowcost[j] != 0 && lowcost[j] < min)
			{
				/* 则让当前权值成为最⼩值 */
				min = lowcost[j];
				/* 将当前最⼩值的下标存⼊k */
				k = j;
			}
			j++;
		}
		/* 打印当前顶点边中权值最⼩边 */
		printf("(%d,%d)", adjvex[k], k);
		/* 将当前顶点的权值设置为0，表示此顶点已经完成任务 */
		lowcost[k] = 0;

		// add  找起点
		/* 循环所有顶点 */
		for (j = 1; j < G.numVertexes; j++)
		{
			/* 若下标为k顶点各边权值⼩于此前这些顶点未被加⼊⽣成树权值 */
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				/* 将较⼩权值存⼊lowcost */
				lowcost[j] = G.arc[k][j];
				/* 将下标为k的顶点存⼊adjvex */
				adjvex[j] = k;
			}
		}
	}
}

int main()
{
	MGraph mgraph;

	
	//初始化二维数组
	for (int i = 0; i < MAXVEX; i++)
	{
		for (int j = 0; j < MAXVEX; j++)
		{
			mgraph.arc[i][j] = 0;
		}
	}

	CreateMGraph(&mgraph);

	MiniSpanTree_Prim(mgraph);

	return 0;
	//BubbleSort2(a.data(), a.size());
		
	
}
