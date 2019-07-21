#include "stdafx.h"
#include "GraphLearning.h"
#include<iostream>
#include<queue>
#include<string>

using namespace std;

//ͼ���ڽ�����洢�ṹ

//�߱�ڵ�ṹ��һ��adjvex�����洢�ڽӵ��λ�ã�һ��nextָ������ָ����һ���ڵ�
typedef struct EdgeNode
{
	int adjvex;  //�洢�����±���Ϣ
	struct EdgeNode *next;
} EdgeNode;

//�����ڵ�ṹ
typedef struct
{
	string Vexs;  //�����洢������Ϣ
	EdgeNode *firstedge;  //�����洢��ǰ�������һ������
} VexList;

//�����ö�̬����洢�����Ȼ��numVertex,numEdge��һ��ͼ�Ķ������ͱ���
typedef struct
{
	vector<VexList> VexList;
	int Vertexs, Edges;
} GraphList;

//һ����λ���������ض��㵱ǰ���±�
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
	cout << "�����붥�����ͱ�����" << endl;
	cin >> G->Vertexs >> G->Edges;
	cout << "�����붥�����Ϣ��" << endl;
	for (int i = 0; i < G->Vertexs; ++i){
		VexList tmp;
		cin >> tmp.Vexs;
		tmp.firstedge = NULL;
		G->VexList.push_back(tmp);
	}
	for (int k = 0; k < G->Edges; ++k){
		int i, j;//(Vi��Vj)
		cout << "������ߣ�Vi,Vj����" << endl;
		cin >> i >> j;
		if (G->VexList[i].firstedge == NULL){//��ǰ����i����û�ж���
			e = new EdgeNode;
			e->adjvex = j;
			e->next = NULL;
			G->VexList[i].firstedge = e;
		}
		else{  //��ǰi�����ж���
			EdgeNode *p = G->VexList[i].firstedge;
			while (p->next){
				p = p->next;
			}
			e = new EdgeNode;
			e->adjvex = j;
			e->next = NULL;
			p->next = e;
		}
		//��Ϊ������ͼ�����ԣ�Vi,Vj���루Vj,Vi����Ҫ��������
		if (G->VexList[j].firstedge == NULL) //��ǰ����j����û�ж���
		{
			e = new EdgeNode;
			e->adjvex = i;
			e->next = NULL;
			G->VexList[j].firstedge = e;
		}
		else{  //��ǰi�����ж���
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

//��ӡ��������
void PrintGraph(GraphList *G)
{
	cout << "���������ڽӱ���������ʾ��" << endl;
	for (int i = 0; i<G->Vertexs; i++)
	{
		cout << G->VexList[i].Vexs;             //�����������Ϣ
		EdgeNode * e = G->VexList[i].firstedge;
		while (e)                              //Ȼ��Ϳ�ʼ�������ÿ���߱����洢���ڽӵ���±�
		{
			cout << "-->" << e->adjvex;
			e = e->next;
		}
		cout << endl;
	}
}

bool Visited_List[100];

//��ʼ�����ڽ��������ݽṹ��������ȱ����͹�����ޱ���


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
	cout << "������ȱ���˳��" << endl;
	for (int i = 0; i<G->Vertexs; ++i)
		Visited_List[i] = false;
	for (int i = 0; i<G->Vertexs; ++i){
		if (!Visited_List[i])
			DFS(G, i);
	}
	cout << endl;
}


//BFS  �ص�Ҫʹ�ö��У��������Ĳ������
void BFSTraver(GraphList *G)
{
	cout << "������ȱ���˳��" << endl;
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
				while (p){//�ѵ�ǰ�����������ӵĵ�����
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
	//��ӡ�����ľ����
	PrintGraph(&g);
	DFSTraver(&g);
	BFSTraver(&g);
	return 0;
}

