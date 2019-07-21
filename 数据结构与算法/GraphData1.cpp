#include "stdafx.h"
#include "GraphLearning.h"
#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

//图的邻接矩阵存储结构
typedef struct  Graph{
	//顶点表
	vector<string> Vexs;
	//边表，表示顶点与顶点之间的连接关系
	vector<vector<int>> arc;
	//存储顶点和边的个数
	int Vertexs,Edges;
}Graph;

void CreateGraph(Graph *G)
{
	cout << "请输入顶点个数和边的个数" <<endl;
	cin >> G->Vertexs >> G->Edges;
	cout << "请输入顶点信息" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		string tmp;
		cin >> tmp;
		G->Vexs.push_back(tmp);
	}
	//边表初始化
	vector<vector<int>> data(G->Vertexs, vector<int>(G->Vertexs, 0));
	G->arc = data;
	for (int i = 0; i < G->Vertexs; ++i){
		for (int j = 0; j < G->Vertexs; ++j){
			//因为是对称矩阵
			if (i != j){
				G->arc[i][j] = 1000;
				G->arc[j][i] = 1000;
			}
		}
		
	}
	//边表正式录入数据
	for (int k = 0; k < G->Edges; ++k){
		int i,j;
		cout << "请输入边（Vi,Vj）" << endl;
		cin >> i >> j;
		//（Vi,Vj）是连通的顶点，则acr[i][j]与arc[j][i]都为1 
		G->arc[i][j] = 1;
		G->arc[j][i] = 1;
	}
	return;
}

//打印连接链表
void PrintGraph(Graph *G)
{
	cout << "所建立的矩阵表如以下所示：" << endl;
	for (int i = 0; i<G->Vertexs; i++)
	{
		cout << G->Vexs[i]<<"：";             //先输出顶点信息
		for (int j = 0; j<G->Vertexs; ++j){ //然后就开始遍历输出每个边表所存储的邻接点的下标
			cout << G->arc[i][j] ;
		}
		cout << endl;
	}
}

bool Visited_matrix[100];
//开始基于邻接矩阵数据结构的深度优先遍历和广度有限遍历


//DFS
void DFS(Graph *G, int i)
{
	//只要你进来了，就说明你已经访问了
	Visited_matrix[i] = true;
	cout << "当前节点为：" << G->Vexs[i];
	for (int j = 0; j < G->Vertexs; ++j){
		//arc[i][j]之间要有通路，并且J还没有被访问
		if (G->arc[i][j] == 1 && !Visited_matrix[j])
			DFS(G, j);
	}
	cout << endl;
}

void DFSTraver(Graph *G)
{
	//将访问列表初始化
	cout << "DFS遍历顺序为" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		Visited_matrix[i] = false;
	}
	for (int i = 0; i < G->Vertexs; ++i){
		if (!Visited_matrix[i])
			DFS(G, i);
	}
}


//BFS  特点要使用队列，很像树的层序遍历
void BFSTraver(Graph *G)
{
	cout << "BFS遍历顺序为" << endl;
	//辅助队列
	queue<int> Q;
	//同样要初始化访问数组
	for (int i = 0; i < G->Vertexs; ++i)
		Visited_matrix[i] = false;
	//开始对每个顶点循环
	for (int i = 0; i < G->Vertexs; ++i){
		if (!Visited_matrix[i]){
			Q.push(i);
			Visited_matrix[i] = true;
			cout << "当前节点为：" << G->Vexs[i];
			while(!Q.empty()){
				i = Q.front();
				Q.pop();
				for (int j = 0; j < G->Vertexs; ++j){
					if (G->arc[i][j] == 1 && !Visited_matrix[j]){
						Visited_matrix[j] = true;
						cout << "当前节点为：" << G->Vexs[j];
						Q.push(j);
					}
				}
			}
		}
	}
	return;
}

int main()
{
	Graph g;
	CreateGraph(&g);
	//打印建立的矩阵表
	PrintGraph(&g);
	DFSTraver(&g);
	BFSTraver(&g);
	return 0;
}