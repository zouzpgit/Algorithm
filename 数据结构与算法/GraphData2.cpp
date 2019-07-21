#include "stdafx.h"
#include "GraphLearning.h"
#include<iostream>
#include<queue>
#include<string>

using namespace std;

//图的邻接链表存储结构

//边表节点结构，一个adjvex用来存储邻接点的位置，一个next指针用来指向下一个节点
typedef struct EdgeNode
{
	int adjvex;  //存储顶点下标信息
	struct EdgeNode *next;
} EdgeNode;

//顶点表节点结构
typedef struct
{
	string Vexs;  //用来存储顶点信息
	EdgeNode *firstedge;  //用来存储当前顶点的下一个顶点
} VexList;

//这里用动态数组存储顶点表，然后numVertex,numEdge是一个图的顶点数和边数
typedef struct
{
	vector<VexList> VexList;
	int Vertexs, Edges;
} GraphList;

//一个定位函数，返回顶点当前的下标
/*int position(GraphList *G, string val)
{
	for (int i = 0; i<G->Vertexs; i++)
	{
		if (G->VexList[i].Vexs== val)
			return i;
	}
	return -1;
}*/

void CreateGraph(GraphList * G)
{
	string v1, v2;
	EdgeNode * e, *p, *q;
	cout << "请输入顶点数和边数：" << endl;
	cin >> G->Vertexs >> G->Edges;
	cout << "请输入顶点的信息：" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		VexList tmp;
		cin >> tmp.Vexs;
		tmp.firstedge = NULL;
		G->VexList.push_back(tmp);
	}
	for (int k = 0; k < G->Edges; ++k){
		int i, j;//(Vi，Vj)
		cout << "请输入边（Vi,Vj）：" << endl;
		cin >> i >> j;
		if (G->VexList[i].firstedge == NULL){//当前顶点i后面没有顶点
			e = new EdgeNode;
			e->adjvex = j;
			e->next = NULL;
			G->VexList[i].firstedge = e;
		}
		else{  //当前i后面有顶点
			EdgeNode *p = G->VexList[i].firstedge;
			while (p->next){
				p = p->next;
			}
			e = new EdgeNode;
			e->adjvex = j;
			e->next = NULL;
			p->next = e;
		}
		//因为是无向图，所以（Vi,Vj）与（Vj,Vi）都要连接起来
		if (G->VexList[j].firstedge == NULL) //当前顶点j后面没有顶点
		{
			e = new EdgeNode;
			e->adjvex = i;
			e->next = NULL;
			G->VexList[j].firstedge = e;
		}
		else{  //当前i后面有顶点
			EdgeNode *p = G->VexList[j].firstedge;
			while (p->next){
				p = p->next;
			}
			e = new EdgeNode;
			e->adjvex = j;
			e->next = NULL;
			p->next = e;
		}
	}

}

//打印连接链表
void PrintGraph(GraphList *G)
{
	cout << "所建立的邻接表如以下所示：" << endl;
	for (int i = 0; i<G->Vertexs; i++)
	{
		cout << G->VexList[i].Vexs;             //先输出顶点信息
		EdgeNode * e = G->VexList[i].firstedge;
		while (e)                              //然后就开始遍历输出每个边表所存储的邻接点的下标
		{
			cout << "-->" << e->adjvex;
			e = e->next;
		}
		cout << endl;
	}
}

bool Visited_List[100];

//开始基于邻接链表数据结构的深度优先遍历和广度有限遍历


//DFS
void DFS(GraphList *G, int i)
{

	EdgeNode * p;
	Visited_List[i] = true;
	cout << G->VexList[i].Vexs << "  ";
	p = G->VexList[i].firstedge;
	while (p)
	{
		if (!Visited_List[p->adjvex])
			DFS(G, p->adjvex);
		p = p->next;
	}
	
}

void DFSTraver(GraphList *G)
{
	cout << "深度优先遍历顺序：" << endl;
	for (int i = 0; i<G->Vertexs; ++i)
		Visited_List[i] = false;
	for (int i = 0; i<G->Vertexs; ++i){
		if (!Visited_List[i])
			DFS(G, i);
	}
	cout << endl;
}


//BFS  特点要使用队列，很像树的层序遍历
void BFSTraver(GraphList *G)
{
	cout << "广度优先遍历顺序：" << endl;
	EdgeNode * p;
	queue<int> Q;
	for (int i = 0; i<G->Vertexs; ++i)
		Visited_List[i] = false;
	for (int i = 0; i<G->Vertexs; ++i){
		if (!Visited_List[i]){
			Visited_List[i] = true;
			cout << G->VexList[i].Vexs << "  ";
			Q.push(i);
			while (!Q.empty()){
				i = Q.front();
				Q.pop();
				p = G->VexList[i].firstedge;
				while (p){//把当前顶点下相连接的点找完
					if (!Visited_List[p->adjvex])
					{
						Visited_List[p->adjvex] = true;
						cout << G->VexList[p->adjvex].Vexs << "  ";
						Q.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}

int main()
{
	GraphList g;
	CreateGraph(&g);
	//打印建立的矩阵表
	PrintGraph(&g);
	DFSTraver(&g);
	BFSTraver(&g);
	return 0;
}

