#include "stdafx.h"
#include "GraphLearning.h"
#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

//ͼ���ڽӾ���洢�ṹ
typedef struct  Graph{
	//�����
	vector<string> Vexs;
	//�߱���ʾ�����붥��֮������ӹ�ϵ
	vector<vector<int>> arc;
	//�洢����ͱߵĸ���
	int Vertexs,Edges;
}Graph;

void CreateGraph(Graph *G)
{
	cout << "�����붥������ͱߵĸ���" <<endl;
	cin >> G->Vertexs >> G->Edges;
	cout << "�����붥����Ϣ" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		string tmp;
		cin >> tmp;
		G->Vexs.push_back(tmp);
	}
	//�߱��ʼ��
	vector<vector<int>> data(G->Vertexs, vector<int>(G->Vertexs, 0));
	G->arc = data;
	for (int i = 0; i < G->Vertexs; ++i){
		for (int j = 0; j < G->Vertexs; ++j){
			//��Ϊ�ǶԳƾ���
			if (i != j){
				G->arc[i][j] = 1000;
				G->arc[j][i] = 1000;
			}
		}
		
	}
	//�߱���ʽ¼������
	for (int k = 0; k < G->Edges; ++k){
		int i,j;
		cout << "������ߣ�Vi,Vj��" << endl;
		cin >> i >> j;
		//��Vi,Vj������ͨ�Ķ��㣬��acr[i][j]��arc[j][i]��Ϊ1 
		G->arc[i][j] = 1;
		G->arc[j][i] = 1;
	}
	return;
}

//��ӡ��������
void PrintGraph(Graph *G)
{
	cout << "�������ľ������������ʾ��" << endl;
	for (int i = 0; i<G->Vertexs; i++)
	{
		cout << G->Vexs[i]<<"��";             //�����������Ϣ
		for (int j = 0; j<G->Vertexs; ++j){ //Ȼ��Ϳ�ʼ�������ÿ���߱����洢���ڽӵ���±�
			cout << G->arc[i][j] ;
		}
		cout << endl;
	}
}

bool Visited_matrix[100];
//��ʼ�����ڽӾ������ݽṹ��������ȱ����͹�����ޱ���


//DFS
void DFS(Graph *G, int i)
{
	//ֻҪ������ˣ���˵�����Ѿ�������
	Visited_matrix[i] = true;
	cout << "��ǰ�ڵ�Ϊ��" << G->Vexs[i];
	for (int j = 0; j < G->Vertexs; ++j){
		//arc[i][j]֮��Ҫ��ͨ·������J��û�б�����
		if (G->arc[i][j] == 1 && !Visited_matrix[j])
			DFS(G, j);
	}
	cout << endl;
}

void DFSTraver(Graph *G)
{
	//�������б��ʼ��
	cout << "DFS����˳��Ϊ" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		Visited_matrix[i] = false;
	}
	for (int i = 0; i < G->Vertexs; ++i){
		if (!Visited_matrix[i])
			DFS(G, i);
	}
}


//BFS  �ص�Ҫʹ�ö��У��������Ĳ������
void BFSTraver(Graph *G)
{
	cout << "BFS����˳��Ϊ" << endl;
	//��������
	queue<int> Q;
	//ͬ��Ҫ��ʼ����������
	for (int i = 0; i < G->Vertexs; ++i)
		Visited_matrix[i] = false;
	//��ʼ��ÿ������ѭ��
	for (int i = 0; i < G->Vertexs; ++i){
		if (!Visited_matrix[i]){
			Q.push(i);
			Visited_matrix[i] = true;
			cout << "��ǰ�ڵ�Ϊ��" << G->Vexs[i];
			while(!Q.empty()){
				i = Q.front();
				Q.pop();
				for (int j = 0; j < G->Vertexs; ++j){
					if (G->arc[i][j] == 1 && !Visited_matrix[j]){
						Visited_matrix[j] = true;
						cout << "��ǰ�ڵ�Ϊ��" << G->Vexs[j];
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
	//��ӡ�����ľ����
	PrintGraph(&g);
	DFSTraver(&g);
	BFSTraver(&g);
	return 0;
}