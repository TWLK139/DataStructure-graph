#pragma once
#ifndef GRAPH_H

#define GRAPH_H

#define DEBUG

#define INF 65535          //���������
#define MaxVerNum  100     //������󶥵����

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<filesystem>

using namespace std;

typedef char elementType;									//����ͼ�ж������������
typedef int eInfoType;										//�������й��ڱߵ���Ϣ���������ͣ����磬��Ȩͼ�п��Ա�ʾ�ߵ�Ȩֵ  
typedef int cellType;										//�ڽӾ����ֵ����Ȩͼ��1���ڣ�0�����ڣ�����Ȩͼ��Ϊ�ߵ�Ȩֵ���ޱ��������
typedef enum { UDG, UDN, DG, DN } GraphKind;				//ö��ͼ������--����ͼ��������������ͼ��������

//***************************�������ṹ����*****************************//
typedef struct lBNode													//
{																		//
	elementType data;													//
	struct lBNode* lChild, * rChild;									//
}BiNode, * BiTree;														//
//**********************************************************************//

//**************************�ı����������нṹ**************************//
//�����н��ṹ														//
typedef struct LNode													//
{																		//
	BiTree point;								//����ַ���			//
	int serial;									//���Ԫ�����			//
	elementType data;							//Ԫ��ֵ���			//
	struct LNode* next, * prior;				//��һ������һ��ָ��	//
}queueNode;																//
																		//
//�����нṹ															//
typedef struct LNodes													//
{																		//
	queueNode* front;							//��ͷָ��				//
	queueNode* rear;							//��βָ��				//
	bool flag = false;							//������ڴ�ӡ������	//
}linkQueue, * lQP;														//
//**********************************************************************//

//***************************Prim�㷨�ߴ洢*****************************//
typedef struct minEdgeType												//
{																		//
	int v;										//������ѡһ�˶�����	//
	eInfoType eWeight;							//�ߵ�Ȩֵ				//
} MinEdgeType;									//�������Ԫ������		//
//**********************************************************************//

//***************************Kruskal�㷨�ߴ洢**************************//
//�߽��ṹ															//
typedef struct kEdgeType												//
{																		//
	int vBegin;									//�ߵ���ʼ����			//
	int vEnd;									//�ߵĽ�������			//
	eInfoType eWeight;							//�ߵ�Ȩֵ				//
} KruskalEdge;									//�������Ԫ������		//
//�ߴ洢�ṹ															//
typedef struct kEdges													//
{																		//
	KruskalEdge data[MaxVerNum + 1];									//
	int len = 0;														//
} KEdges;																//
//**********************************************************************//

//*************************Dijkstra�㷨����洢*************************//
//������ṹ															//
typedef struct DResNode													//
{																		//
	int path;									//�������·����Ϣ		//
	int dist;									//�������·��ֵ		//
} DijkstraResNode;														//
//����洢�ṹ															//
typedef struct DijkstraRes												//
{																		//
	DijkstraResNode data[MaxVerNum + 1];								//
	int len = 0;														//
} DRes;																	//
//**********************************************************************//

//***************************Floyd�㷨����洢**************************//
//����ṹ																//
typedef struct FResNode													//
{																		//
	int path[MaxVerNum + 1][MaxVerNum + 1];		//�������·����Ϣ		//
	int dist[MaxVerNum + 1][MaxVerNum + 1];		//�������·��ֵ		//
} FRes;																	//
//**********************************************************************//

//*********************TopologicalSort�㷨����洢**********************//
//����洢�ṹ															//
typedef struct TopologicalSortRes										//
{																		//
	int serial[MaxVerNum + 1] = { -1 };									//
	elementType data[MaxVerNum + 1] = { '\0' };							//
	int len = 0;														//
} TRes;																	//
//**********************************************************************//

//*****************************************************ͼ���ڽӾ�����ʽ*****************************************************//
typedef struct GraphAdjMatrix																								//
{																															//
	elementType Data[MaxVerNum + 1];					//�������飬��Ŷ���Ԫ�ص�ֵ��Data[0]��Ԫ����						//
	cellType AdjMatrix[MaxVerNum + 1][MaxVerNum + 1];	//�ڽӾ��������±�Ϊ0��Ԫ���ã���AdjMatrix[1][1]��Ԫ��ʼ			//
	int VerNum;											//������															//
	int ArcNum;											//�����ߣ���														//
	GraphKind gKind;									//ͼ������:0-����ͼ��1-��������2-����ͼ��3-������					//
} GraphM;												//ͼ��������														//
//**************************************************************************************************************************//

//******************************************************ͼ���ڽӱ���ʽ******************************************************//
//��������ṹ																											//
typedef struct eNode																										//
{																															//
	int adjVer;											//�ڽӶ����ַ���˴�Ϊ�����ڶ��������ţ���1��ʼ					//
	eInfoType eInfo;									//�������б�ʾ�ߵ������Ϣ��������Ȩֵ							//
	struct eNode* next;									//ָ��������е���һ�����											//
}EdgeNode;												//������������													//
//�������Ԫ�ؽṹ																											//
typedef struct vNode																										//
{																															//
	elementType data;									//���ͼ�ж��������												//
	EdgeNode* firstEdge;								//ָ��˶�������ĵ�һ���ߵ�ָ�룬���������ͷָ��					//
}VerNode;																													//
//ͼ���ڽӱ�ṹ																											//
typedef struct GraphAdjLinkList																								//
{																															//
	VerNode VerList[MaxVerNum + 1];						//��Ŷ����˳�������0��Ԫ����									//
	int VerNum;											//������															//
	int ArcNum;											//�����ߣ���														//
	GraphKind gKind;									//ͼ������:0-����ͼ��1-��������2-����ͼ��3-������					//
}GraphL;												//ͼ��������														//
//**************************************************************************************************************************//


//******************************************************��������************************************************************//
//ͨ�ú�������																												//
void strLTrim(char* str);																//ɾ���ַ������ַ�������߿ո�		//
//���к�������																												//
bool initialQueue(lQP& Q);																//�����г�ʼ��						//
bool enQueue(lQP Q, int data);															//���������						//
bool enQueue(lQP Q, elementType data);													//���������						//
bool enQueue(lQP Q, BiTree data);														//���������						//
bool enQueue(lQP Q, int data, BiTree point);											//���������						//
bool outQueue(lQP Q, int& data);														//�����г���						//
bool outQueue(lQP Q, elementType& data);												//�����г���						//
bool outQueue(lQP Q, BiTree& data);														//�����г���						//
bool outQueue(lQP Q, int& data, BiTree& point);											//�����г���						//
bool reOutQueue(lQP Q, int& data);														//������������ӣ�ջ��				//
//������ͨ�ú�������																										//
bool addTreeNode(BiTree* Tpp, elementType x);											//�����������½��					//
void preTraverse(BiTree T);																//�������������					//
void inOrderTraverse(BiTree T);															//�������������					//
void postTraverse(BiTree T);															//�������������					//
void printBST(BiTree T);																//��ӡ������						//
void destoryTreeNode(BiTree T);															//���ٶ�����						//
bool destoryTree(BiTree& T);															//���ٶ�����						//
//�ڽӾ���ͼ��������																										//
int LocateVertex(GraphM& G, elementType v);												//ͼ�в���Ŀ�궥��					//
int firstAdj(GraphM& G, int v);															//���һ���ڽӵ�					//
int nextAdj(GraphM& G, int v, int w);													//����һ���ڽӵ�					//
void printGraph(GraphM& G);																//��ӡͼ�������Ϣ					//
bool CreateGrpFromFile(char fileName[], GraphM& G);										//�ļ�����ͼ						//
void DFS(GraphM& G, int verID, bool visited[]);											//������ȱ���						//
bool DFS(GraphM& G, int verID = 1);														//������ȱ���						//
bool BFS(GraphM& G, int verID = 1);														//������ȱ���						//
int getEdgeNum(GraphM& G);																//�����							//
void DFSMakeTree(BiTree& T, GraphM& G, int verID, bool visited[]);						//������ȱ���������				//
bool DFSMakeTree(BiTree& T, GraphM& G, int verID = 1);									//������ȱ���������				//
bool BFSMakeTree(BiTree& T, GraphM& G, int verID = 1);									//������ȱ���������				//
//�ڽӱ�ͼ��������																											//
int LocateVertex(GraphL& G, elementType v);												//ͼ�в���Ŀ�궥��					//
int firstAdj(GraphL& G, int v);															//���һ���ڽӵ�					//
int nextAdj(GraphL& G, int v, int w);													//����һ���ڽӵ�					//
void printGraph(GraphL& G);																//��ӡͼ�������Ϣ					//
bool CreateGrpFromFile1(char fileName[], GraphL& G);									//�ļ�����ͼ						//
bool CreateGraphFromFile(char fileName[], GraphL& G);									//�ļ�����ͼ						//
void DestroyGraph(GraphL& G);															//����ͼ							//
void DFS(GraphL& G, int verID, bool visited[]);											//������ȱ���						//
bool DFS(GraphL& G, int verID = 1);														//������ȱ���						//
bool BFS(GraphL& G, int verID = 1);														//������ȱ���						//
int getEdgeNum(GraphL& G);																//�����							//
void DFSMakeTree(BiTree& T, GraphL& G, int verID, bool visited[]);						//������ȱ���						//
bool DFSMakeTree(BiTree& T, GraphL& G, int verID = 1);									//������ȱ���						//
bool BFSMakeTree(BiTree& T, GraphL& G, int verID = 1);									//������ȱ���������				//
//Prim�㷨																													//
bool HasEdge(GraphM& G, int vBegin, int vEnd, eInfoType& eWeight);						//�ж��Ƿ��б�						//
void InitialTE(GraphM& G, MinEdgeType TE[], int verID);									//��ʼ��������						//
int GetMinEdge(GraphM& G, MinEdgeType TE[], bool visited[]);							//��ȡ��СȨֵ��					//
void UpdateTE(GraphM& G, MinEdgeType TE[], int vID, bool visited[]);					//���º�ѡ������					//
void Prim(BiTree& T, GraphM& G, int verID = 1);											//Prim�㷨							//
bool HasEdge(GraphL& G, int vBegin, int vEnd, eInfoType& eWeight);						//�ж��Ƿ��б�						//
void InitialTE(GraphL& G, MinEdgeType TE[], int verID);									//��ʼ��������						//
int GetMinEdge(GraphL& G, MinEdgeType TE[], bool visited[]);							//��ȡ��СȨֵ��					//
void UpdateTE(GraphL& G, MinEdgeType TE[], int vID, bool visited[]);					//���º�ѡ������					//
void Prim(BiTree& T, GraphL& G, int verID = 1);											//Prim�㷨							//
//Kruskal�㷨																												//
void getEdges(GraphM& G, KEdges& edges);												//��ȡ��							//
void getEdges(GraphL& G, KEdges& edges);												//��ȡ��							//
KruskalEdge getMinEdge(GraphM& G, KEdges& edges, bool edgeUsed[], int& edgeIndex);		//��ȡ��С��						//
KruskalEdge getMinEdge(GraphL& G, KEdges& edges, bool edgeUsed[], int& edgeIndex);		//��ȡ��С��						//
void Kruskal(BiTree& T, GraphM& G);														//Kruskal�㷨						//
void Kruskal(BiTree& T, GraphL& G);														//Kruskal�㷨						//
//Dijkstra�㷨																												//
void printDijkstra(GraphM& G, DRes res, int verID);										//��ӡDijkstra						//
void printDijkstra(GraphL& G, DRes res, int verID);										//��ӡDijkstra						//
void Dijkstra(GraphM& G, int verID = 1);												//Dijkstra�㷨						//
void Dijkstra(GraphL& G, int verID = 1);												//Dijkstra�㷨						//
//Floyd�㷨																													//
void printFloyd(GraphM& G, FRes res);													//��ӡFloyd							//
void printFloyd(GraphL& G, FRes res);													//��ӡFloyd							//
void Floyd(GraphM& G);																	//Floyd�㷨							//
void Floyd(GraphL& G);																	//Floyd�㷨							//
//��������������																											//
int getInDegree(GraphM& G, int v);														//��ȡ��ʼ���						//
int getInDegree(GraphL& G, int v);														//��ȡ��ʼ���						//
bool TopologicalSort(GraphM& G, TRes& topoList);										//��������							//
bool TopologicalSort(GraphL& G, TRes& topoList);										//��������							//
void printTopologicalSort(GraphM& G, TRes& topoList);									//��ӡFloyd							//
void printTopologicalSort(GraphL& G, TRes& topoList);									//��ӡFloyd							//
//�ؼ�·����������																											//
int getWeight(GraphL& G, int vBegin, int vEnd);											//��ȡ��������Ȩֵ				//
void printKeyPath(GraphM& G, TRes topoList, int vet[], int vlt[]);						//��ӡ�ؼ�·��						//
void printKeyPath(GraphL& G, TRes topoList, int vet[], int vlt[]);						//��ӡ�ؼ�·��						//
bool keyPath(GraphM& G);																//��ؼ�·��						//
bool keyPath(GraphL& G);																//��ؼ�·��						//
//**************************************************************************************************************************//

#endif // !GRAPH_H

//*********************************************************��������*********************************************************//

//******************************************************ͨ�ú�������******************************************************//

//����������ɾ���ַ������ַ�������߿ո�
//���룺�ַ���ָ��
void strLTrim(char* str)
{
	int i, j;
	int n = 0;
	n = strlen(str) + 1;
	for (i = 0; i < n; i++)
	{
		if (str[i] != ' ')  //�ҵ������һ���ǿո�λ��
			break;
	}
	//�Ե�һ���ǿո��ַ�Ϊ���ַ��ƶ��ַ���
	for (j = 0; j < n; j++)
	{
		str[j] = str[i];
		i++;
	}
}


//******************************************************�����к�������******************************************************//

//���������������г�ʼ��
//���룺����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool initialQueue(lQP& Q)
{
	if (Q == nullptr)
	{
		Q = new linkQueue;
		Q->front = new queueNode;
		Q->rear = Q->front;
		Q->front->next = nullptr;
		Q->front->prior = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰָ����ռ�ã����г�ʼ��ʧ�ܣ�" << endl;

		return false;
	}
}


//�������������������
//���룺����ָ�룬���ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool enQueue(lQP Q, int data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear->next->prior = Q->rear;
		Q->rear = Q->rear->next;
		Q->rear->serial = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//�������������������
//���룺����ָ�룬���ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool enQueue(lQP Q, elementType data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear->next->prior = Q->rear;
		Q->rear = Q->rear->next;
		Q->rear->data = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//�������������������
//���룺����ָ�룬���ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool enQueue(lQP Q, BiTree data)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear->next->prior = Q->rear;
		Q->rear = Q->rear->next;
		Q->rear->point = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//�������������������
//���룺����ָ�룬���Ԫ��ֵ�����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool enQueue(lQP Q, int data, BiTree point)
{
	if (Q != nullptr)
	{
		Q->rear->next = new queueNode;
		Q->rear->next->prior = Q->rear;
		Q->rear = Q->rear->next;
		Q->rear->point = point;
		Q->rear->serial = data;
		Q->rear->next = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰ����δ��ʼ�������ʧ�ܣ�" << endl;

		return false;
	}
}


//���������������г���
//���룺����ָ�룬����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool outQueue(lQP Q, int& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			data = dp->serial;
			Q->front->next = dp->next;
			if (dp->next)
			{
				dp->next->prior = Q->front;
			}
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//���������������г���
//���룺����ָ�룬����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool outQueue(lQP Q, elementType& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			data = dp->data;
			Q->front->next = dp->next;
			if (dp->next)
			{
				dp->next->prior = Q->front;
			}
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//���������������г���
//���룺����ָ�룬����ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool outQueue(lQP Q, BiTree& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			data = dp->point;
			Q->front->next = dp->next;
			if (dp->next)
			{
				dp->next->prior = Q->front;
			}
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//���������������г���
//���룺����ָ�룬����Ԫ��ֵ������ָ��
//���أ��ɹ�����true��ʧ�ܷ���false
bool outQueue(lQP Q, int& data, BiTree& point)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front->next;
			point = dp->point;
			data = dp->serial;
			Q->front->next = dp->next;
			if (dp->next)
			{
				dp->next->prior = Q->front;
			}
			delete(dp);
			if (Q->front->next == nullptr)
			{
				Q->rear = Q->front;
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//�����������������������
//���룺����ͷָ�룬Ԫ�ش�ŵ�ַ
//���أ��ɹ�����true��ʧ�ܷ���false
bool reOutQueue(lQP Q, int& data)
{
	queueNode* dp = nullptr;

	if (Q != nullptr)
	{
		if (Q->front != Q->rear)
		{
			dp = Q->front;
			while (dp->next != Q->rear)
			{
				dp = dp->next;
			}
			Q->rear = dp;
			dp = Q->rear->next;
			data = dp->serial;
			delete(dp);
			Q->rear->next = nullptr;

			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		cout << "��ǰ����δ��ʼ��������ʧ�ܣ�" << endl;

		return false;
	}
}


//****************************************************������ͨ�ú�������****************************************************//

//���������������������½��
//���룺������ָ�룬˳���
//���أ��ɹ�����true��ʧ�ܷ���false
bool addTreeNode(BiTree* Tpp, elementType x)
{
	if (*Tpp == nullptr)
	{
		*Tpp = new BiNode;
		(*Tpp)->data = x;
		(*Tpp)->lChild = nullptr;
		(*Tpp)->rChild = nullptr;

		return true;
	}
	else
	{
		cout << "��ǰ�����ռ�ã�" << endl;

		return false;
	}
}


//������������������ĸ߶�
//���룺������ָ�� 
//���أ��������߶�
int getTreeHeight(BiTree T)
{
	int lh = 0, rh = 0;

	if (!T)
	{
		return 0;
	}
	else
	{
		lh = 1 + getTreeHeight(T->lChild);
		rh = 1 + getTreeHeight(T->rChild);

		return lh > rh ? lh : rh;
	}
}


//****************�������������****************
//�����������������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << '\t';
		preTraverse(T->lChild);
		preTraverse(T->rChild);
	}
}


//****************�������������****************
//�����������������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void inOrderTraverse(BiTree T)
{
	if (T)
	{
		inOrderTraverse(T->lChild);
		cout << T->data << '\t';
		inOrderTraverse(T->rChild);
	}
}


//****************�������������****************
//�����������������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lChild);
		postTraverse(T->rChild);
		cout << T->data << '\t';
	}
}


//������������ӡ����������
//���룺���ֲ�����ָ�룬˳���
void printBST(BiTree T)
{
	int i = 0;
	int nowHeight = 1, height = 0;
	BiTree nowT = nullptr;
	lQP SQF = nullptr, SQS = nullptr, SQC = nullptr;

	height = getTreeHeight(T);

	initialQueue(SQF);
	initialQueue(SQS);
	enQueue(SQF, T);
	if (T)
	{
		SQF->flag = true;
	}
	while (SQF->flag)
	{
		while (outQueue(SQF, nowT))
		{
			cout << " ";
			for (i = 0; i < (int)(pow(2, height - nowHeight) - 1); i++)
			{
				cout << " ";
			}
			if (nowT)
			{
				cout << nowT->data;
			}
			else
			{
				cout << "_";
			}
			for (i = 0; i < (int)(pow(2, height - nowHeight) - 1); i++)
			{
				cout << " ";
			}

			if (nowT)
			{
				enQueue(SQS, nowT->lChild);
				enQueue(SQS, nowT->rChild);
				if (nowT->lChild || nowT->rChild)
				{
					SQS->flag = true;
				}
			}
			else
			{
				enQueue(SQS, nullptr);
				enQueue(SQS, nullptr);
			}
		}
		cout << endl;
		nowHeight++;
		SQF->flag = false;
		SQC = SQF;
		SQF = SQS;
		SQS = SQC;
	}

	cout << endl;
}


//�������������ٶ�����
//���룺���������ڵ�
void destoryTreeNode(BiTree T)
{
	if (T)
	{
		destoryTreeNode(T->lChild);
		destoryTreeNode(T->rChild);
		delete(T);
	}
}


//�������������ٶ�����
//���룺���������ڵ�
bool destoryTree(BiTree& T)
{
	if (T)
	{
		destoryTreeNode(T);
		T = nullptr;
	}

	if (T == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//****************************************************�ڽӾ���ͼ��������****************************************************//

//����������ͼ�в���Ŀ�궥��
//���룺ͼ���ڽӾ���Ŀ��ֵ
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int LocateVertex(GraphM& G, elementType v)
{
	for (int i = 1; i <= G.VerNum; i++)
	{
		if (G.Data[i] == v)
			return i;
	}
	return -1;
}


//�������������һ���ڽӵ�
//���룺ͼ���ڽӾ��󣬶����±�
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int firstAdj(GraphM& G, int v)
{
	int w;
	for (w = 1; w <= G.VerNum; w++)
	{
		if ((G.AdjMatrix[v][w] >= 1) &&
			(G.AdjMatrix[v][w]) < INF)
			return w;    //���ص�һ���ڽӵ���
	}
	return -1;          //δ�ҵ��ڽӵ㣬����-1
}


//��������������һ���ڽӵ�
//���룺ͼ���ڽӾ��󣬶����±꣬�ֵܶ����±�
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int nextAdj(GraphM& G, int v, int w)
{
	int k;
	for (k = w + 1; k <= G.VerNum; k++)
	{
		if ((G.AdjMatrix[v][k] >= 1) &&
			(G.AdjMatrix[v][k]) < INF)
			return k;    //����v��λ��w֮�����һ���ڽӵ�k
	}
	return -1;           //��������һ���ڽӵ㣬����-1
}


//������������ӡͼ�������Ϣ
//���룺ͼ���ڽӾ���
void printGraph(GraphM& G)
{
	int i = 0, j = 0;
	//��ӡͼ������
	switch (G.gKind)
	{
	case UDG:
		cout << "ͼ���ͣ�����ͼ" << endl;
		break;
	case UDN:
		cout << "ͼ���ͣ�������" << endl;
		break;
	case DG:
		cout << "ͼ���ͣ�����ͼ" << endl;
		break;
	case DN:
		cout << "ͼ���ͣ�������" << endl;
		break;
	default:
		cout << "ͼ���ʹ���" << endl;
		break;
	}
	//��ӡͼ�Ķ�����
	cout << "��������" << G.VerNum << endl;
	//��ӡͼ�ı���
	cout << "��  ����" << G.ArcNum << endl;
	//��ӡ���㼰����
	cout << "��  �ţ�";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "��  �㣺";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.Data[i] << "\t";
	}
	cout << endl;

	//��ӡ�ڽӾ���
	cout << "ͼ���ڽӾ���" << endl;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << "\t";
		for (j = 1; j <= G.VerNum; j++)
		{
			if ((G.gKind == UDN || G.gKind == DN) && G.AdjMatrix[i][j] == INF)
				cout << "INF" << "\t";  //���������ʱ����ӡ��INF����ʾ
			else
				cout << G.AdjMatrix[i][j] << "\t";
		}
		cout << endl;
	}

}


//�������������ļ�����ͼ
//���룺�ļ�����ͼ���ڽӾ���
//���أ��ɹ�����true��ʧ�ܷ���false
bool CreateGrpFromFile(char fileName[], GraphM& G)
{
	FILE* pFile;      //����˳�����ļ�ָ��
	char str[1000];   //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

	cellType  eWeight;		//�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind GrpType;		//ͼ����ö�ٱ���

	pFile = fopen(fileName, "r");
	if (!pFile)
	{

		printf("�����ļ�%s��ʧ�ܡ�\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

	//ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if (strstr(str, "Graph") == NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡͼ�����ͣ���������
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;
		else  //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;
	}

	//����ͼ������
	if (strstr(str, "UDG"))
		GrpType = UDG;  //����ͼ
	else if (strstr(str, "UDN"))
		GrpType = UDN;  //������
	else if (strstr(str, "DG"))
		GrpType = DG;   //����ͼ
	else if (strstr(str, "DN"))
		GrpType = DN;   //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡ����Ԫ�أ���str����������
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

	//�������ݷ���ͼ�Ķ�������	
	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL)
	{
		G.Data[nNum] = *token; // atoi(token);	//��������ת��Ϊ��������Ϊ�ַ�����ת��		
		token = strtok(NULL, " ");
		nNum++;
	}
	nNum--;   //������

	//ͼ���ڽӾ����ʼ��
	int nRow = 1;  //�������±꣬��1��ʼ
	int nCol = 1;  //�������±꣬��1��ʼ
	if (GrpType == UDG || GrpType == DG)
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = 0;
	}
	else
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = INF;  //INF��ʾ�����
	}

	//ѭ����ȡ�ߵ����ݵ��ڽӾ���

	int edgeNum = 0;  //�ߵ�����
	elementType Nf, Ns; //�߻򻡵�2�����ڶ���
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;

		char* token = strtok(str, " ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���

		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf = *token;  //��ȡ�ߵĵ�һ������

		token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������ڶ�������
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns = *token;  //��ȡ�ߵĵڶ�������
			//�ӵ�һ�������ȡ�к�		
		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.Data[nRow] == Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
		//�ӵڶ��������ȡ�к�		
		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.Data[nCol] == Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		//���Ϊ������ȡȨֵ
		if (GrpType == UDN || GrpType == DN)
		{
			token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile); //�ر��ļ�
				return false;
			}
			eWeight = atoi(token);  //ȡ�ñߵĸ�����Ϣ
		}
		if (GrpType == UDN || GrpType == DN)  //���Ϊ�����ڽӾ����ж�Ӧ�ı�����Ȩֵ��������Ϊ1
			G.AdjMatrix[nRow][nCol] = eWeight;
		else
			G.AdjMatrix[nRow][nCol] = 1;  //atoi(token);	//�ַ���תΪ����

		edgeNum++;   //������1
	}

	G.VerNum = nNum;  //ͼ�Ķ�����
	if (GrpType == UDG || GrpType == UDN)
		G.ArcNum = edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum = edgeNum;

	G.gKind = GrpType;  //ͼ������

	fclose(pFile); //�ر��ļ�
	return true;
}


//����������������ȱ���ͼ
//���룺ͼ���ڽӾ��󣬿�ʼ�ڵ��±꣬�������
void DFS(GraphM& G, int verID, bool visited[])
{
	int i = 1;

	cout << G.Data[verID] << '\t';
	visited[verID] = true;

	for (i = 1; i <= G.VerNum; i++)
	{
		if ((G.AdjMatrix[verID][i] >= 1) && (G.AdjMatrix[verID][i] < INF) && (!visited[i]))
		{
			DFS(G, i, visited);
		}
	}
}


//ʵ���.ͼ.1��ͼ��������������ȱ�����
//���룺ͼ�ĵ�ַ����ʼ�����ţ�Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool DFS(GraphM& G, int verID)
{
	int i = verID;
	bool visited[MaxVerNum + 1] = { false };

	if (verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (visited[i] == false)
			{
				DFS(G, i, visited);
			}
			i = (i++) % G.VerNum;
		} while (i != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.1��ͼ�������Ĺ�����ȱ�����
//���룺ͼ���ڽӾ��󣬿�ʼ�ڵ��±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool BFS(GraphM& G, int verID)
{
	lQP Q = nullptr;
	int brother = 1, i = verID, node = verID;
	bool visited[MaxVerNum + 1] = { false };

	if (initialQueue(Q) && verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (!visited[node])
			{
				i = node;
				cout << G.Data[i] << '\t';

				visited[i] = true;
				enQueue(Q, i);
				while (outQueue(Q, i))
				{
					brother = 1;
					while (brother <= G.VerNum)
					{
						if ((G.AdjMatrix[i][brother] > 0) && (G.AdjMatrix[i][brother] < INF) && (!visited[brother]))
						{
							cout << G.Data[brother] << '\t';
							visited[brother] = true;
							enQueue(Q, brother);
						}
						brother++;
					}
				}
			}
			node = (node++) % G.VerNum;
		} while (node != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.2�������
//���룺ͼ���ڽӾ���
//���أ��ɹ����ر�����ʧ�ܷ���0
int getEdgeNum(GraphM& G)
{
	int i = 1, j = 1, res = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF)
			{
				res++;
			}
		}
	}

	if (G.gKind < 2)
	{
		res /= 2;
	}

	return res;
}


//����������������ȱ���������
//���룺���洢��ַ��ͼ���ڽӾ��󣬿�ʼ�ڵ��±꣬�������
void DFSMakeTree(BiTree& T, GraphM& G, int verID, bool visited[])
{
	int i = 1;
	BiTree* NTP = &T;

	cout << G.Data[verID] << '\t';
	visited[verID] = true;

	for (i = 1; i <= G.VerNum; i++)
	{
		if ((G.AdjMatrix[verID][i] >= 1) && (G.AdjMatrix[verID][i] < INF) && (!visited[i]))
		{
			addTreeNode(NTP, G.Data[i]);
			DFSMakeTree((*NTP)->lChild, G, i, visited);
		}
		if (*NTP)
		{
			NTP = &((*NTP)->rChild);
		}
	}
}


//ʵ���.ͼ.3��ͼ��������������ȱ���������
//���룺���洢��ַ��ͼ�ĵ�ַ����ʼ�����ţ�Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool DFSMakeTree(BiTree& T, GraphM& G, int verID)
{
	int i = verID;
	bool visited[MaxVerNum + 1] = { false };
	BiTree* NTP = &T;

	if (verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (visited[i] == false)
			{
				addTreeNode(NTP, G.Data[i]);
				DFSMakeTree((*NTP)->lChild, G, i, visited);
				NTP = &((*NTP)->rChild);
			}
			i = (i++) % G.VerNum;
		} while (i != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.4��ͼ�������Ĺ�����ȱ���������
//���룺���洢��ַ��ͼ���ڽӾ��󣬿�ʼ�ڵ��±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool BFSMakeTree(BiTree& T, GraphM& G, int verID)
{
	lQP Q = nullptr;
	int brother = 1, i = verID, node = verID;
	bool visited[MaxVerNum + 1] = { false };
	BiTree* NT = &T, temp = nullptr;

	if (initialQueue(Q) && verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (!visited[node])
			{
				i = node;
				cout << G.Data[i] << '\t';
				addTreeNode(NT, G.Data[i]);

				visited[i] = true;
				enQueue(Q, i, *NT);
				while (outQueue(Q, i, temp))
				{
					brother = 1;
					NT = &(temp->lChild);
					while (brother <= G.VerNum)
					{
						if ((G.AdjMatrix[i][brother] > 0) && (G.AdjMatrix[i][brother] < INF) && (!visited[brother]))
						{
							cout << G.Data[brother] << '\t';
							addTreeNode(NT, G.Data[brother]);
							visited[brother] = true;
							enQueue(Q, brother, *NT);
							NT = &((*NT)->rChild);
						}
						brother++;
					}
				}
			}
			node = (node++) % G.VerNum;
			NT = &T;
			while (*NT)
			{
				NT = &((*NT)->rChild);
			}
		} while (node != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//******************************************************�ڽӱ�ͼ��������******************************************************//

//����������ͼ�в���Ŀ�궥��
//���룺ͼ���ڽӱ�Ŀ��ֵ
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int LocateVertex(GraphL& G, elementType v)
{
	for (int i = 1; i <= G.VerNum; i++)
	{
		if (G.VerList[i].data == v)
			return i;
	}
	return -1;
}


//�������������һ���ڽӵ�
//���룺ͼ���ڽӱ������±�
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int firstAdj(GraphL& G, int v)
{
	EdgeNode* p;
	p = G.VerList[v].firstEdge;
	if (p)
		return p->adjVer;
	else
		return -1;
}


//��������������һ���ڽӵ�
//���룺ͼ���ڽӱ������±꣬�ֵܶ����±�
//���أ����ҳɹ������±꣬ʧ�ܷ���-1
int nextAdj(GraphL& G, int v, int w)
{
	EdgeNode* p;
	p = G.VerList[v].firstEdge;         //ȡ����v�ı�����ͷָ��
	while (p->next)
	{
		if (p->adjVer == w)
			return p->next->adjVer;  //����w֮����һ���ڽӵ���
		p = p->next;
	}

	return -1;                        //δ�ҵ���һ���ڽӵ㣬����-1
}


//������������ӡͼ�������Ϣ
//���룺ͼ���ڽӱ�
void printGraph(GraphL& G)
{
	int i = 0, j = 0;
	//��ӡͼ������
	switch (G.gKind)
	{
	case UDG:
		cout << "ͼ���ͣ�����ͼ" << endl;
		break;
	case UDN:
		cout << "ͼ���ͣ�������" << endl;
		break;
	case DG:
		cout << "ͼ���ͣ�����ͼ" << endl;
		break;
	case DN:
		cout << "ͼ���ͣ�������" << endl;
		break;
	default:
		cout << "ͼ���ʹ���" << endl;
		break;
	}
	//��ӡͼ�Ķ�����
	cout << "��������" << G.VerNum << endl;
	//��ӡͼ�ı���
	cout << "��  ����" << G.ArcNum << endl;
	//��ӡ���㼰����
	cout << "���\t����\t������" << endl;
	EdgeNode* p;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << i << "\t" << G.VerList[i].data << "\t";
		p = G.VerList[i].firstEdge;
		while (p != NULL)
		{
			cout << p->adjVer << "\t";
			p = p->next;
		}
		cout << endl;
	}
	cout << endl;
	//��ӡ�ڽӾ���
	cout << "�ڽӾ���" << endl;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << "\t";
		p = G.VerList[i].firstEdge;
		j = 1;
		while (p != NULL || j <= G.VerNum)
		{
			if ((j <= G.VerNum) && (p != NULL) && j == p->adjVer)  //�б�
			{
				cout << p->eInfo << "\t";
				j++;
				p = p->next;
			}
			else   //�ޱ�
			{
				if (G.gKind == UDN || G.gKind == DN)
					cout << "INF" << "\t";  //�����ޱ�ʱ��ӡȨֵΪ������á�INF����ʾ
				else
					cout << "0" << "\t";    //ͼ���ޱ�ʱ��0��ʾ
				j++;
			}

		}
		cout << endl;
	}
}


//�������������ļ�����ͼ
//���룺�ļ�����ͼ���ڽӾ���
//���أ��ɹ�����true��ʧ�ܷ���false
//��ע��������ʹ�õ������ļ����ڽӾ���Ϊ��������
bool CreateGrpFromFile1(char fileName[], GraphL& G)
{
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����
	char* ss;
	int i = 0, j = 0;
	int edgeNum = 0;  //�ߵ�����

	GraphKind graphType;  //ͼ����ö�ٱ���

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n", fileName);
		return false;
	}

	ss = fgets(str, 1000, pFile);
	strncpy(strTemp, str, 2);
	while ((ss != NULL) && (strstr(strTemp, "//") != NULL))  //����ע����
	{
		ss = fgets(str, 1000, pFile);
		strncpy(strTemp, str, 2);
		//cout<<strTemp<<endl;
	}
	//ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
//cout<<str<<endl;
	if (strstr(str, "Graph") == NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}
	//��ȡͼ������
	if (fgets(str, 1000, pFile) == NULL)
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}
	//����ͼ������
	if (strstr(str, "UDG"))
		graphType = UDG;  //����ͼ
	else if (strstr(str, "UDN"))
		graphType = UDN;  //������
	else if (strstr(str, "DG"))
		graphType = DG;   //����ͼ
	else if (strstr(str, "DN"))
		graphType = DN;   //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡ����Ԫ�أ���str
	if (fgets(str, 1000, pFile) == NULL)
	{
		printf("���󣺶�ȡͼ�Ķ���Ԫ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}


	//�������ݷ���ͼ�Ķ�������		
	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL)
	{
		G.VerList[nNum].data = *token;
		G.VerList[nNum].firstEdge = NULL;
		//p=NULL;
		//eR=G.VerList[i].firstEdge;
		token = strtok(NULL, " ");
		nNum++;
	}

	//ѭ����ȡ�ڽӾ�������
	int nRow = 1;  //�������±�
	int nCol = 1;  //�������±�
	EdgeNode* eR;  //������βָ��
	EdgeNode* p;

	while (fgets(str, 1000, pFile) != NULL)
	{
		eR = NULL;
		p = NULL;
		nCol = 1;  //�к���Ϊ0��һ�����¿�ʼ
		char* token = strtok(str, " ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���
		while (token != NULL)
		{
			if (atoi(token) >= 1 && atoi(token) < INF)  //���ǵ���
			{
				p = new EdgeNode;  //����һ����������
				p->adjVer = nCol;   //����ı�ţ���1��ʼ
				p->eInfo = atoi(token);  //��Ȩͼ����Ȩֵ����ȨͼΪ1
				p->next = NULL;
				if (G.VerList[nRow].firstEdge == NULL)
				{
					G.VerList[nRow].firstEdge = p;
					eR = p;
				}
				else
				{
					eR->next = p;
					eR = p;  //�µ�βָ��				
				}
				edgeNum++;   //������1
			}
			token = strtok(NULL, " ");  //��ȡ��һ���Ӵ�
			nCol++;
		}
		nRow++; //һ�����ݴ������
	}

	G.VerNum = nNum;  //ͼ�Ķ�����
	if (graphType == UDG || graphType == UDN)
		G.ArcNum = edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum = edgeNum;

	G.gKind = graphType;  //ͼ������

	fclose(pFile); //�ر��ļ�
	return true;
}


//�������������ļ�����ͼ
//���룺�ļ�����ͼ���ڽӾ���
//���أ��ɹ�����true��ʧ�ܷ���false
//��ע��������ʹ�õ������ļ���ʽ�Աߣ�����ԣ�Ϊ��������
bool CreateGraphFromFile(char fileName[], GraphL& G)
{
	FILE* pFile;     //����˳�����ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTemp[10]; //�ж��Ƿ�ע����

	int i = 0, j = 0;
	int edgeNum = 0;  //�ߵ�����

	eInfoType eWeight;  //�ߵ���Ϣ����Ϊ�ߵ�Ȩֵ
	GraphKind graphType;  //ͼ����ö�ٱ���

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		printf("�����ļ�%s��ʧ�ܡ�\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)  //�������к�ע����
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //����ע����
			continue;
		else  //��ע���С��ǿ��У�����ѭ��
			break;
	}

	//ѭ��������str��Ӧ���Ѿ����ļ���ʶ���ж��ļ���ʽ
	if (strstr(str, "Graph") == NULL)
	{
		printf("���󣺴򿪵��ļ���ʽ����\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}

	//��ȡͼ�����ͣ��������м�ע����
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;
		else  //�ǿ��У�Ҳ��ע���У���ͼ�����ͱ�ʶ
			break;

	}

	//����ͼ������
	if (strstr(str, "UDG"))
		graphType = UDG;  //����ͼ
	else if (strstr(str, "UDN"))
		graphType = UDN;  //������
	else if (strstr(str, "DG"))
		graphType = DG;   //����ͼ
	else if (strstr(str, "DN"))
		graphType = DN;   //������
	else
	{
		printf("���󣺶�ȡͼ�����ͱ��ʧ�ܣ�\n");
		fclose(pFile); //�ر��ļ�
		return false;
	}


	//��ȡ����Ԫ�أ���str����������
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;
		else  //�ǿ��У�Ҳ��ע���У���ͼ�Ķ���Ԫ����
			break;
	}

	//�������ݷ���ͼ�Ķ�������		
	char* token = strtok(str, " ");
	int nNum = 0;
	while (token != NULL)
	{
		G.VerList[nNum + 1].data = *token;
		G.VerList[nNum + 1].firstEdge = NULL;
		//p=NULL;
		//eR=G.VerList[i].firstEdge;
		token = strtok(NULL, " ");
		nNum++;
	}

	//ѭ����ȡ�ߣ�����ԣ�����
	int nRow = 1;  //�������±�
	int nCol = 1;  //�������±�
	EdgeNode* eR;  //������βָ��
	EdgeNode* p;

	elementType Nf, Ns; //�߻򻡵�2�����ڶ���
	while (fgets(str, 1000, pFile) != NULL)
	{
		//ɾ���ַ�����߿ո�
		strLTrim(str);
		if (str[0] == '\n')  //���У�������ȡ��һ��
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //ע���У�������������ȡ��һ��
			continue;

		//nCol=0;  //�к���Ϊ0��һ�����¿�ʼ
		char* token = strtok(str, " ");  //�Կո�Ϊ�ָ������ָ�һ�����ݣ�д���ڽӾ���

		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}
		Nf = *token;  //��ȡ�ߵĵ�һ������

		token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������ڶ�������
		if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
		{
			printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
			fclose(pFile); //�ر��ļ�
			return false;
		}

		Ns = *token;  //��ȡ�ߵĵڶ�������
			//�ӵ�һ�������ȡ�к�		
		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.VerList[nRow].data == Nf)  //�Ӷ����б��ҵ���һ������ı��
				break;
		}
		//�ӵڶ��������ȡ�к�		
		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.VerList[nCol].data == Ns)  //�Ӷ����б��ҵ��ڶ�������ı��
				break;
		}

		//���Ϊ������ȡȨֵ
		if (graphType == UDN || graphType == DN)
		{
			token = strtok(NULL, " ");  //��ȡ��һ���Ӵ������ߵĸ�����Ϣ����Ϊ�ߵ�Ȩ��
			if (token == NULL)  //�ָ�Ϊ�մ���ʧ���˳�
			{
				printf("���󣺶�ȡͼ�ı�����ʧ�ܣ�\n");
				fclose(pFile); //�ر��ļ�
				return false;
			}
			eWeight = atoi(token);  //ȡ�ñߵĸ�����Ϣ
		}


		eR = G.VerList[nRow].firstEdge;
		while (eR != NULL && eR->next != NULL)
		{
			eR = eR->next;  //���Ʊ�����ָ�룬ֱ��β�ڵ�
		}

		p = new EdgeNode;  //����һ����������
		p->adjVer = nCol;   //����ı�ţ���1��ʼ
		if (graphType == UDN || graphType == DN) //�ߵĸ�����Ϣ������Ȩͼ����Ȩֵ����ȨͼΪ1
			p->eInfo = eWeight;
		else
			p->eInfo = 1;
		p->next = NULL;

		if (G.VerList[nRow].firstEdge == NULL)
		{
			G.VerList[nRow].firstEdge = p;
			eR = p;
		}
		else
		{
			eR->next = p;
			eR = p;  //�µ�βָ��				
		}

		edgeNum++;   //������1
	}



	G.VerNum = nNum;  //ͼ�Ķ�����
	if (graphType == UDG || graphType == UDN)
		G.ArcNum = edgeNum / 2;  //����ͼ�����ı�������ͳ�Ƶ����ֳ�2  
	else
		G.ArcNum = edgeNum;

	G.gKind = graphType;  //ͼ������

	fclose(pFile); //�ر��ļ�
	return true;
}


//���������������ڽӱ�ͼ
//���룺ͼ���ڽӱ�
void DestroyGraph(GraphL& G)
{
	EdgeNode* p, * u;
	int vID;
	for (vID = 1; vID <= G.VerNum; vID++)  //ѭ��ɾ��ÿ������ı�����
	{
		p = G.VerList[vID].firstEdge;
		G.VerList[vID].firstEdge = NULL;
		while (p)  //ѭ��ɾ����ǰ�������еĹ����� 
		{
			u = p->next;  //uָ����һ���߽��
			delete(p);  //ɾ����ǰ�߽��
			p = u;
		}
	}
	p = NULL;
	u = NULL;
	G.VerNum = -1;  //�༭ͼ�Ѿ�����
}


//����������������ȱ���ͼ
//���룺ͼ���ڽӱ���ʼ�ڵ��±꣬�������
void DFS(GraphL& G, int verID, bool visited[])
{
	EdgeNode* p;

	cout << G.VerList[verID].data << '\t';

	visited[verID] = true;
	p = G.VerList[verID].firstEdge;
	while (p)
	{
		if (!visited[p->adjVer])
		{
			DFS(G, p->adjVer, visited);
		}
		p = p->next;
	}
}


//ʵ���.ͼ.1��ͼ��������������ȱ�����
//���룺ͼ�ĵ�ַ����ʼ�����ţ�Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool DFS(GraphL& G, int verID)
{
	int i = verID;
	bool visited[MaxVerNum + 1] = { false };

	if (verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (visited[i] == false)
			{
				DFS(G, i, visited);
			}
			i = (i++) % G.VerNum;
		} while (i != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.1��ͼ�������Ĺ�����ȱ�����
//���룺ͼ���ڽӾ��󣬿�ʼ�ڵ��±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool BFS(GraphL& G, int verID)
{
	lQP Q = nullptr;
	int i = verID, node = verID;
	bool visited[MaxVerNum + 1] = { false };
	EdgeNode* p = nullptr;

	if (initialQueue(Q) && verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (!visited[node])
			{
				i = node;
				cout << G.VerList[i].data << '\t';

				visited[i] = true;
				enQueue(Q, i);
				while (outQueue(Q, i))
				{
					p = G.VerList[i].firstEdge;
					while (p)
					{
						if (!visited[p->adjVer])
						{
							cout << G.VerList[p->adjVer].data << '\t';
							visited[p->adjVer] = true;
							enQueue(Q, p->adjVer);
						}
						p = p->next;
					}
				}
			}
			node = (node++) % G.VerNum;
		} while (node != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.2�������
//���룺ͼ���ڽӾ���
//���أ��ɹ����ر�����ʧ�ܷ���0
int getEdgeNum(GraphL& G)
{
	int res = 0, i = 1;
	EdgeNode* p = nullptr;

	for (i = 1; i <= G.VerNum; i++)
	{
		p = G.VerList[i].firstEdge;
		while (p)
		{
			res++;
			p = p->next;
		}
	}

	if (G.gKind < 2)
	{
		res /= 2;
	}

	return res;
}


//����������������ȱ���������
//���룺���Ĵ洢��ַ��ͼ���ڽӱ���ʼ�ڵ��±꣬�������
void DFSMakeTree(BiTree& T, GraphL& G, int verID, bool visited[])
{
	EdgeNode* p;
	BiTree* NTP = &T;

	cout << G.VerList[verID].data << '\t';

	visited[verID] = true;
	p = G.VerList[verID].firstEdge;
	while (p)
	{
		if (!visited[p->adjVer])
		{
			addTreeNode(NTP, G.VerList[p->adjVer].data);
			DFSMakeTree((*NTP)->lChild, G, p->adjVer, visited);
		}
		p = p->next;
		if (*NTP)
		{
			NTP = &((*NTP)->rChild);
		}
	}
}


//ʵ���.ͼ.3��ͼ��������������ȱ���������
//���룺���Ĵ洢��ַ��ͼ���ڽӱ���ʼ�����ţ�Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool DFSMakeTree(BiTree& T, GraphL& G, int verID)
{
	int i = verID;
	bool visited[MaxVerNum + 1] = { false };
	BiTree* NTP = &T;

	if (verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (visited[i] == false)
			{
				addTreeNode(NTP, G.VerList[i].data);
				DFSMakeTree((*NTP)->lChild, G, i, visited);
				NTP = &((*NTP)->rChild);
			}
			i = (i++) % G.VerNum;
		} while (i != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//ʵ���.ͼ.4��ͼ�������Ĺ�����ȱ���������
//���룺���洢��ַ��ͼ���ڽӱ���ʼ�ڵ��±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
bool BFSMakeTree(BiTree& T, GraphL& G, int verID)
{
	lQP Q = nullptr;
	int i = verID, node = verID;
	bool visited[MaxVerNum + 1] = { false };
	EdgeNode* p = nullptr;
	BiTree* NT = &T, temp = nullptr;

	if (initialQueue(Q) && verID <= G.VerNum && verID > 0)
	{
		do
		{
			if (!visited[node])
			{
				i = node;
				cout << G.VerList[i].data << '\t';
				addTreeNode(NT, G.VerList[i].data);

				visited[i] = true;
				enQueue(Q, i, *NT);
				while (outQueue(Q, i, temp))
				{
					p = G.VerList[i].firstEdge;
					NT = &(temp->lChild);
					while (p)
					{
						if (!visited[p->adjVer])
						{
							cout << G.VerList[p->adjVer].data << '\t';
							addTreeNode(NT, G.VerList[p->adjVer].data);
							visited[p->adjVer] = true;
							enQueue(Q, p->adjVer, *NT);
							NT = &((*NT)->rChild);
						}
						p = p->next;
					}
				}
			}
			node = (node++) % G.VerNum;
			NT = &T;
			while (*NT)
			{
				NT = &((*NT)->rChild);
			}
		} while (node != verID);
		cout << endl;

		return true;
	}
	else
	{
#ifdef DEBUG
		cout << "�����Ŵ���" << endl;
#endif // DEBUG

		return false;
	}
}


//******************************************************Prim�㷨��������******************************************************//

//�����������ж�������֮���Ƿ��б�
//���룺���洢��ַ����ʼ����±꣬��������±꣬Ȩ�ش洢��ַ
//���أ����ڷ���true��ȫְ���������У������ڷ���false������ֵΪINF
bool HasEdge(GraphM& G, int vBegin, int vEnd, eInfoType& eWeight)
{
	if (G.AdjMatrix[vBegin][vEnd] <= 0 || G.AdjMatrix[vBegin][vEnd] >= INF)
	{
		eWeight = INF;
		return false;
	}
	else
	{
		eWeight = G.AdjMatrix[vBegin][vEnd];
		return true;
	}
}


//������������ʼ��������
//���룺���洢��ַ���������ַ����ѡ����
void InitialTE(GraphM& G, MinEdgeType TE[], int verID)
{
	int i;
	eInfoType eWeight;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (HasEdge(G, verID, i, eWeight))
		{
			TE[i].v = verID;
			TE[i].eWeight = eWeight;
		}
		else
		{
			TE[i].eWeight = INF;
		}
	}
}


//������������ȡȨֵ��С��
//���룺���洢��ַ���������ַ���������
//���أ����ҳɹ�������ţ�ʧ�ܷ���0
int GetMinEdge(GraphM& G, MinEdgeType TE[], bool visited[])
{
	eInfoType eMin = INF;
	int i, res = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if ((visited[i] == false) && TE[i].eWeight < eMin)
		{
			res = i;
			eMin = TE[i].eWeight;
		}
	}

	return res;
}


//�������������±�����
//���룺���洢��ַ���������ַ��Ԫ����ţ��������
void UpdateTE(GraphM& G, MinEdgeType TE[], int verID, bool visited[])
{
	int i;
	eInfoType eWeight;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false)
		{
			if (HasEdge(G, verID, i, eWeight) && eWeight < TE[i].eWeight)
			{
				TE[i].v = verID;
				TE[i].eWeight = eWeight;
			}
		}
	}
}


//ʵ���.ͼ.5��Prim�㷨
//���룺ͼ���ڽӾ��󣬿�ʼ����±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
void Prim(BiTree& T, GraphM& G, int verID)
{
	MinEdgeType TE[MaxVerNum + 1];
	int i, curID;
	bool visited[MaxVerNum + 1] = { false };
	lQP Q = nullptr;
	BiTree* NT = &T, temp = nullptr;

	InitialTE(G, TE, verID);
	initialQueue(Q);
	visited[verID] = true;

	for (i = 1; i <= G.VerNum; i++)
	{
		curID = GetMinEdge(G, TE, visited);
		visited[curID] = true;
		UpdateTE(G, TE, curID, visited);
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		if (i != verID)
		{
			if (TE[i].eWeight < INF)
			{
				cout << G.Data[TE[i].v] << "--(" << TE[i].eWeight << ")->" << G.Data[i] << endl;
			}
			else
			{
				cout << "0--( �ϵ�)->" << G.Data[i] << endl;
			}
		}
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		if (TE[i].eWeight == INF)
		{
			while (*NT)
			{
				NT = &((*NT)->rChild);
			}
			addTreeNode(NT, G.Data[i]);
			enQueue(Q, i, *NT);
		}
	}

	while (outQueue(Q, curID, temp))
	{
		NT = &(temp->lChild);
		for (i = 1; i <= G.VerNum; i++)
		{
			if (TE[i].v == curID)
			{
				addTreeNode(NT, G.Data[i]);
				enQueue(Q, i, *NT);
				NT = &((*NT)->rChild);
			}
		}
	}
}


//�����������ж�������֮���Ƿ��б�
//���룺���洢��ַ����ʼ����±꣬��������±꣬Ȩ�ش洢��ַ
//���أ����ڷ���true��Ȩֵ���������У������ڷ���false������ֵΪINF
bool HasEdge(GraphL& G, int vBegin, int vEnd, eInfoType& eWeight)
{
	EdgeNode* p;

	eWeight = INF;
	if (vBegin > 0 && vEnd > 0)
	{
		p = G.VerList[vBegin].firstEdge;
		while (p)
		{
			if (p->adjVer == vEnd)
			{
				eWeight = p->eInfo;

				return true;
			}
			p = p->next;
		}
	}

	return false;
}


//������������ʼ��������
//���룺���洢��ַ���������ַ����ѡ����
void InitialTE(GraphL& G, MinEdgeType TE[], int verID)
{
	int i;
	eInfoType eWeight;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (HasEdge(G, verID, i, eWeight))
		{
			TE[i].v = verID;
			TE[i].eWeight = eWeight;
		}
		else
		{
			TE[i].eWeight = INF;
		}
	}
}


//������������ȡȨֵ��С��
//���룺���洢��ַ���������ַ���������
//���أ����ҳɹ�������ţ�ʧ�ܷ���0
int GetMinEdge(GraphL& G, MinEdgeType TE[], bool visited[])
{
	eInfoType eMin = INF;								//������С��Ȩֵ����ʼ��Ϊ�����
	int i, res = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false && TE[i].eWeight < eMin)
		{
			res = i;
			eMin = TE[i].eWeight;
		}
	}

	return res;											//��Ӧ�ıߣ�TE[j].v, j��Ϊѡ�еı�
}


//�������������±�����
//���룺���洢��ַ���������ַ��Ԫ����ţ��������
void UpdateTE(GraphL& G, MinEdgeType TE[], int vID, bool visited[])
{
	int i;
	eInfoType eWeight;
	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false)
		{
			if (HasEdge(G, vID, i, eWeight) && eWeight < TE[i].eWeight)
			{
				TE[i].v = vID;
				TE[i].eWeight = eWeight;
			}
		}
	}
}


//ʵ���.ͼ.5��Prim�㷨
//���룺���洢��ַ��ͼ���ڽӱ���ʼ����±꣨Ĭ��Ϊ1����Ŷ�Ӧ�±꣬0�±�λ�ò�ʹ�ã�
//���أ���ſɲ鷵��true�����򷵻�false
void Prim(BiTree& T, GraphL& G, int verID)
{
	MinEdgeType TE[MaxVerNum + 1];
	int i, curID;
	bool visited[MaxVerNum + 1] = { false };
	//��������������
	lQP Q = nullptr;
	BiTree* NT = &T, temp = nullptr;

	InitialTE(G, TE, verID);
	initialQueue(Q);
	visited[verID] = true;

	for (i = 1; i <= G.VerNum; i++)
	{
		curID = GetMinEdge(G, TE, visited);
		visited[curID] = true;
		UpdateTE(G, TE, curID, visited);
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		if (i != verID)
		{
			if (TE[i].eWeight < INF)
			{
				cout << G.VerList[TE[i].v].data << "--(" << TE[i].eWeight << ")->" << G.VerList[i].data << endl;
			}
			else
			{
				cout << "0--( �ϵ�)->" << G.VerList[i].data << endl;
			}
		}
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		if (TE[i].eWeight == INF)
		{
			while (*NT)
			{
				NT = &((*NT)->rChild);
			}
			addTreeNode(NT, G.VerList[i].data);
			enQueue(Q, i, *NT);
		}
	}

	while (outQueue(Q, curID, temp))
	{
		NT = &(temp->lChild);
		for (i = 1; i <= G.VerNum; i++)
		{
			if (TE[i].v == curID)
			{
				addTreeNode(NT, G.VerList[i].data);
				enQueue(Q, i, *NT);
				NT = &((*NT)->rChild);
			}
		}
	}
}


//******************************************************Kruskal�㷨��������******************************************************//

//������������ȡ�ߺ���
//���룺ͼ��ַ���ߴ洢�ṹ
void getEdges(GraphM& G, KEdges& edges)
{
	int i, j, k = 1;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			if (G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF)
			{
				edges.data[k].vBegin = i;
				edges.data[k].vEnd = j;
				edges.data[k].eWeight = G.AdjMatrix[i][j];
				k++;
			}
		}
	}
	edges.len = k - 1;
}


//������������ȡ��С�ߺ���
//���룺ͼ��ַ���ߴ洢�ṹ���߱�����飬���±��ŵ�ַ
//���أ��������ṹ
KruskalEdge getMinEdge(GraphM& G, KEdges& edges, bool edgeUsed[], int& edgeIndex)
{
	KruskalEdge minEdge;
	cellType eMin = INF;
	int i = 1;

	edgeIndex = 0;
	for (i = 1; i <= edges.len; i++)
	{
		if (edgeUsed[i] == false && edges.data[i].eWeight < eMin)
		{
			eMin = edges.data[i].eWeight;
			minEdge = edges.data[i];
			edgeIndex = i;
		}
	}

	return minEdge;
}


//ʵ���.ͼ.6��Kruskal�㷨
//���룺���洢��ַ��ͼ���ڽӱ�
void Kruskal(BiTree& T, GraphM& G)
{
	int conVerID[MaxVerNum + 1];				//�������ͨ�����������
	KEdges edges;								//���ͼ��������Ϣ
	KEdges treeEdges;							//����������е�n-1������Ϣ
	bool edgeUsed[MaxVerNum + 1] = { false };	//��Ǳ��Ƿ���������
	KruskalEdge minEdge;
	int i, j;
	int k = 1;
	int conID;									//�ߵ���ֹ����vEnd����ͨ�����ı��
	int edgeIndex;								//��С���±���
	////��������������
	//lQP Q = nullptr;
	//BiTree* NT = &T, temp = nullptr;

	getEdges(G, edges);
	for (i = 1; i <= G.VerNum; i++)				//��ʼ����ͨ����
	{
		conVerID[i] = i;						//��ͨ������ŵ��ڶ�����
	}

	for (i = 1; i < G.VerNum; i++)				//ע��ֻ��ȡ��n-1����
	{
		minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd])
		{										//������ɻ�·
			edgeUsed[edgeIndex] = true;
			minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		}
		treeEdges.data[i] = minEdge;
		treeEdges.len++;
		//enQueue(Q,)
		conID = conVerID[minEdge.vEnd];
		for (j = 1; j <= G.VerNum; j++)
		{
			if (conVerID[j] == conID)
			{
				conVerID[j] = conVerID[minEdge.vBegin];
			}
		}
		edgeUsed[edgeIndex] = true;
	}

	for (i = 1; i <= treeEdges.len; i++)
	{
		cout << G.Data[treeEdges.data[i].vBegin] << "--(" << treeEdges.data[i].eWeight << ")->" << G.Data[treeEdges.data[i].vEnd] << endl;
	}


}


//������������ȡ�ߺ���
//���룺ͼ��ַ���ߴ洢�ṹ
void getEdges(GraphL& G, KEdges& edges)
{
	int i, k = 1;
	EdgeNode* p = nullptr;

	for (i = 1; i <= G.VerNum; i++)
	{
		p = G.VerList[i].firstEdge;
		while (p)
		{
			edges.data[k].vBegin = i;
			edges.data[k].vEnd = p->adjVer;
			edges.data[k].eWeight = p->eInfo;
			p = p->next;
			k++;
		}
	}

	edges.len = k - 1;
}


//������������ȡ��С�ߺ���
//���룺ͼ��ַ���ߴ洢�ṹ���߱�����飬���±��ŵ�ַ
//���أ��������ṹ
KruskalEdge getMinEdge(GraphL& G, KEdges& edges, bool edgeUsed[], int& edgeIndex)
{
	KruskalEdge minEdge;
	cellType eMin = INF;
	int i = 1;

	edgeIndex = 0;
	for (i = 1; i <= edges.len; i++)
	{
		if (edgeUsed[i] == false && edges.data[i].eWeight < eMin)
		{
			eMin = edges.data[i].eWeight;
			minEdge = edges.data[i];
			edgeIndex = i;
		}
	}

	return minEdge;
}


//ʵ���.ͼ.6��Kruskal�㷨
//���룺���洢��ַ��ͼ���ڽӱ�
void Kruskal(BiTree& T, GraphL& G)
{
	int conVerID[MaxVerNum + 1];				//�������ͨ�����������
	KEdges edges;								//���ͼ��������Ϣ
	KEdges treeEdges;							//����������е�n-1������Ϣ
	bool edgeUsed[MaxVerNum + 1] = { false };	//��Ǳ��Ƿ���������
	KruskalEdge minEdge;
	int i, j;
	int k = 1;
	int conID;									//�ߵ���ֹ����vEnd����ͨ�����ı��
	int edgeIndex;								//��С���±���
	////��������������
	//lQP Q = nullptr;
	//BiTree* NT = &T, temp = nullptr;

	getEdges(G, edges);
	for (i = 1; i <= G.VerNum; i++)				//��ʼ����ͨ����
	{
		conVerID[i] = i;						//��ͨ������ŵ��ڶ�����
	}

	for (i = 1; i < G.VerNum; i++)				//ע��ֻ��ȡ��n-1����
	{
		minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd])
		{										//������ɻ�·
			edgeUsed[edgeIndex] = true;
			minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		}
		treeEdges.data[i] = minEdge;
		treeEdges.len++;
		//enQueue(Q,)
		conID = conVerID[minEdge.vEnd];
		for (j = 1; j <= G.VerNum; j++)
		{
			if (conVerID[j] == conID)
			{
				conVerID[j] = conVerID[minEdge.vBegin];
			}
		}
		edgeUsed[edgeIndex] = true;
	}

	for (i = 1; i <= treeEdges.len; i++)
	{
		cout << G.VerList[treeEdges.data[i].vBegin].data << "--(" << treeEdges.data[i].eWeight << ")->" << G.VerList[treeEdges.data[i].vEnd].data << endl;
	}
}


//******************************************************Dijkstra�㷨��������******************************************************//

//������������ӡDijkstra
//���룺ͼ���ڽӾ��󣬽����Žṹ��ָ�����
void printDijkstra(GraphM& G, DRes res, int verID)
{
	int sPath[MaxVerNum + 1];
	int vPre;
	int top = 0;
	int i, j;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.Data[verID] << "--";
		if (res.data[i].dist == INF)
		{
			cout << "(���ɴ�)";
		}
		else
		{
			cout << '(' << res.data[i].dist << ')';
		}
		cout << "--" << G.Data[i] << "\t·����\t";

		top++;
		sPath[top] = i;
		vPre = res.data[i].path;

		while (vPre != -1)
		{
			top++;
			sPath[top] = vPre;
			vPre = res.data[vPre].path;
		}
		if (res.data[i].dist != INF)
		{
			for (j = top; j > 0; j--)
			{
				cout << G.Data[sPath[j]] << '\t';
			}
		}

		top = 0;
		cout << endl;
	}
}


//������������ӡDijkstra
//���룺ͼ���ڽӾ��󣬽����Žṹ��ָ�����
void printDijkstra(GraphL& G, DRes res, int verID)
{
	int sPath[MaxVerNum + 1];
	int vPre;
	int top = 0;
	int i, j;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.VerList[verID].data << "--";
		if (res.data[i].dist == INF)
		{
			cout << "(���ɴ�)";
		}
		else
		{
			cout << '(' << res.data[i].dist << ')';
		}
		cout << "--" << G.VerList[i].data << "\t·����\t";

		top++;
		sPath[top] = i;
		vPre = res.data[i].path;

		while (vPre != -1)
		{
			top++;
			sPath[top] = vPre;
			vPre = res.data[vPre].path;
		}
		if (res.data[i].dist != INF)
		{
			for (j = top; j > 0; j--)
			{
				cout << G.VerList[sPath[j]].data << '\t';
			}
		}

		top = 0;
		cout << endl;
	}
}


//ʵ���.ͼ.7��Dijkstra�㷨
//���룺ͼ���ڽӾ���ָ����㣨Ĭ��Ϊ1��Ԫ���±������ţ�
void Dijkstra(GraphM& G, int verID)
{												//path�������·����Ϣ��dist�������·��ֵ��verIDΪָ�����
	bool solved[MaxVerNum + 1] = { false };		//����Ƿ������·��
	int i, j, v;
	cellType minDist;							//��̾���
	DRes res;

	for (i = 1; i <= G.VerNum; i++)
	{
		res.data[i].dist = G.AdjMatrix[verID][i];
		if (res.data[i].dist != INF)
		{
			res.data[i].path = verID;					//��i�������ǰ��ΪverID
		}
		else
		{
			res.data[i].path = -1;						//��ǰ��
		}
	}
	res.len = G.VerNum;
	solved[verID] = true;						//��ʼ�����
	res.data[verID].dist = 0;
	res.data[verID].path = -1;

	for (i = 1; i < G.VerNum; i++)
	{
		minDist = INF;

		for (j = 1; j <= G.VerNum; j++)
		{
			if (solved[j] == false && res.data[j].dist < minDist)
			{
				v = j;
				minDist = res.data[j].dist;
			}
		}

		if (minDist == INF)
		{
			return;
		}

		//cout << G.Data[v] << '\t' << minDist << endl;

		solved[v] = true;
		for (j = 1; j <= G.VerNum; j++)
		{
			if (solved[j] == false && (minDist + G.AdjMatrix[v][j]) < res.data[j].dist)
			{
				res.data[j].dist = minDist + G.AdjMatrix[v][j];
				res.data[j].path = v;
			}
		}
	}

	printDijkstra(G, res, verID);
}


//ʵ���.ͼ.7��Dijkstra�㷨
//���룺ͼ���ڽӾ���ָ����㣨Ĭ��Ϊ1��Ԫ���±������ţ�
void Dijkstra(GraphL& G, int verID)
{
	bool solved[MaxVerNum + 1] = { false };
	int i, j, v;
	eInfoType minDist;
	EdgeNode* p = nullptr;
	DRes res;

	for (i = 1; i <= G.VerNum; i++)
	{
		res.data[i].dist = INF;
		res.data[i].path = -1;
	}

	solved[verID] = true;
	res.data[verID].dist = 0;

	p = G.VerList[verID].firstEdge;
	while (p)
	{
		v = p->adjVer;
		res.data[v].dist = p->eInfo;
		res.data[v].path = verID;
		p = p->next;
	}

	for (i = 1; i < G.VerNum; i++)
	{
		minDist = INF;
		for (j = 1; j <= G.VerNum; j++)
		{
			if (solved[j] == false && res.data[j].dist < minDist)
			{
				v = j;
				minDist = res.data[j].dist;
			}
		}

		if (minDist == INF)
		{
			return;
		}

		//cout << G.VerList[v].data << '\t' << minDist << endl;

		solved[v] = true;

		p = G.VerList[v].firstEdge;
		while (p)
		{
			j = p->adjVer;
			if (solved[j] == false && (minDist + p->eInfo) < res.data[j].dist)
			{
				res.data[j].dist = minDist + p->eInfo;
				res.data[j].path = v;
			}
			p = p->next;
		}
	}

	printDijkstra(G, res, verID);
}


//******************************************************Floyd�㷨��������******************************************************//

//������������ӡFloyd
//���룺ͼ���ڽӾ��󣬽����Žṹ
void printFloyd(GraphM& G, FRes res)
{
	int sPath[MaxVerNum + 1];
	int vPre;
	int top = 0;
	int i, j, k;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			cout << G.Data[i] << "--";
			if (res.dist[i][j] == INF)
			{
				cout << "(���ɴ�)";
			}
			else
			{
				cout << '(' << res.dist[i][j] << ')';
			}
			cout << "--" << G.Data[j] << "\t·����\t";

			top++;
			sPath[top] = j;
			vPre = res.path[i][j];

			while (vPre != -1)
			{
				top++;
				sPath[top] = vPre;
				vPre = res.path[i][vPre];
			}
			if (res.dist[i][j] != INF)
			{
				for (k = top; k > 0; k--)
				{
					cout << G.Data[sPath[k]] << '\t';
				}
			}

			top = 0;
			cout << endl;
		}
	}
}


//������������ӡFloyd
//���룺ͼ���ڽӱ������Žṹ
void printFloyd(GraphL& G, FRes res)
{
	int sPath[MaxVerNum + 1];
	int vPre;
	int top = 0;
	int i, j, k;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			cout << G.VerList[i].data << "--";
			if (res.dist[i][j] == INF)
			{
				cout << "(���ɴ�)";
			}
			else
			{
				cout << '(' << res.dist[i][j] << ')';
			}
			cout << "--" << G.VerList[j].data << "\t·����\t";

			top++;
			sPath[top] = j;
			vPre = res.path[i][j];

			while (vPre != -1)
			{
				top++;
				sPath[top] = vPre;
				vPre = res.path[i][vPre];
			}
			if (res.dist[i][j] != INF)
			{
				for (k = top; k > 0; k--)
				{
					cout << G.VerList[sPath[k]].data << '\t';
				}
			}

			top = 0;
			cout << endl;
		}
	}
}


//ʵ���.ͼ.8��Floyd�㷨
//���룺ͼ���ڽӾ���
void Floyd(GraphM& G)
{
	FRes res;
	int i, j, m;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			res.dist[i][j] = G.AdjMatrix[i][j];
			if (i != j && G.AdjMatrix[i][j] > 0 && G.AdjMatrix[i][j] < INF)
			{
				res.path[i][j] = i;
			}
			else
			{
				res.path[i][j] = -1;
			}
		}
	}

	for (m = 1; m <= G.VerNum; m ++ )
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			for (j = 1; j <= G.VerNum; j++)
			{
				if (i != j && (res.dist[i][m] + res.dist[m][j]) < res.dist[i][j])
				{
					res.dist[i][j] = res.dist[i][m] + res.dist[m][j];
					res.path[i][j] = res.path[m][j];
				}
			}
		}
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		res.dist[i][i] = 0;
	}

	//for (i = 1; i <= G.VerNum; i++)
	//{
	//	for (j = 1; j <= G.VerNum; j++)
	//	{
	//		cout << res.dist[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	printFloyd(G, res);
}


//ʵ���.ͼ.8��Floyd�㷨
//���룺ͼ���ڽӾ���
void Floyd(GraphL& G)
{
	FRes res;
	int i, j, m;
	EdgeNode* p = nullptr;

	for (i = 1; i <= G.VerNum; i++)
	{
		for (j = 1; j <= G.VerNum; j++)
		{
			res.dist[i][j] = INF;
			res.path[i][j] = -1;
		}
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		p = G.VerList[i].firstEdge;
		while (p)
		{
			res.dist[i][p->adjVer] = p->eInfo;
			res.path[i][p->adjVer] = i;
			p = p->next;
		}
	}

	for (m = 1; m <= G.VerNum; m++)
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			for (j = 1; j <= G.VerNum; j++)
			{
				if (i != j && (res.dist[i][m] + res.dist[m][j]) < res.dist[i][j])
				{
					res.dist[i][j] = res.dist[i][m] + res.dist[m][j];
					res.path[i][j] = res.path[m][j];
				}
			}
		}
	}

	for (i = 1; i <= G.VerNum; i++)
	{
		res.dist[i][i] = 0;
	}

	//for (i = 1; i <= G.VerNum; i++)
	//{
	//	for (j = 1; j <= G.VerNum; j++)
	//	{
	//		cout << res.path[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	printFloyd(G, res);
}


//******************************************************��������������******************************************************//

//������������ȡ�������
//���룺ͼ���ڽӾ�����ʼ����
//���أ���ǰ�������
int getInDegree(GraphM& G, int v)
{
	int res = 0, i;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (G.AdjMatrix[i][v] > 0 && G.AdjMatrix[i][v] < INF)
		{
			res++;
		}
	}

	return res;
}


//������������ȡ�������
//���룺ͼ���ڽӱ���ʼ����
//���أ���ǰ�������
int getInDegree(GraphL& G, int v)
{
	int res = 0, i;
	EdgeNode* p = nullptr;

	for (i = 1; i <= G.VerNum; i++)
	{
		p = G.VerList[i].firstEdge;
		while (p)
		{
			if (p->adjVer == v)
			{
				res++;
			}
			p = p->next;
		}
	}

	return res;
}


//ʵ���.ͼ.9����������
//���룺ͼ���ڽӾ��󣬽���������
//���أ����Խ����������򷵻�true�����򷵻�false
bool TopologicalSort(GraphM& G, TRes& topoList)
{
	int inds[MaxVerNum + 1] = { 0 };					//�����������
	lQP Q = nullptr;
	int i, v, vCont = 0;

	initialQueue(Q);

	for (i = 1; i <= G.VerNum; i++)
	{
		topoList.serial[i] = -1;
		inds[i] = getInDegree(G, i);
		if (inds[i] == 0)
		{
			enQueue(Q, i);
		}
	}

	while (reOutQueue(Q, v))
	{
		vCont++;
		topoList.serial[vCont] = v;
		topoList.data[vCont] = G.Data[v];
		for (i = 1; i <= G.VerNum; i++)
		{
			if (G.AdjMatrix[v][i] > 0 && G.AdjMatrix[v][i] < INF && inds[i] > 0)
			{
				inds[i]--;
				if (inds[i] == 0)
				{
					enQueue(Q, i);
				}
			}
		}
	}

	topoList.len = vCont;

	if (vCont == G.VerNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//ʵ���.ͼ.9����������
//���룺ͼ���ڽӾ��󣬽���������
//���أ����Խ����������򷵻�true�����򷵻�false
bool TopologicalSort(GraphL& G, TRes& topoList)
{
	int inds[MaxVerNum + 1] = { 0 };					//�����������
	lQP Q = nullptr;
	int i, v, vCont = 0;
	EdgeNode* p = nullptr;

	initialQueue(Q);

	for (i = 1; i <= G.VerNum; i++)
	{
		topoList.serial[i] = -1;
		inds[i] = getInDegree(G, i);
		if (inds[i] == 0)
		{
			enQueue(Q, i);
		}
	}

	while (reOutQueue(Q, v))
	{
		vCont++;
		topoList.serial[vCont] = v;
		topoList.data[vCont] = G.VerList[v].data;
		p = G.VerList[v].firstEdge;
		while (p)
		{
			if (inds[p->adjVer] > 0)
			{
				inds[p->adjVer]--;
				if (inds[p->adjVer] == 0)
				{
					enQueue(Q, p->adjVer);
				}
			}
			p = p->next;
		}
	}

	topoList.len = vCont;

	if (vCont == G.VerNum)
	{
		return true;
	}
	else
	{
		return false;
	}

}


//������������ӡTopologicalSort
//���룺ͼ���ڽӾ��󣬽����Žṹ
void printTopologicalSort(GraphM& G, TRes& topoList)
{
	if (topoList.len == G.VerNum)
	{
		for (int i = 1; i <= topoList.len; i++)
		{
			cout << topoList.data[i]<<'(' << topoList.serial[i] << ")\t";
		}
	}
	else
	{
		cout << "���ɽ�����������";
	}
	cout << endl;
}


//������������ӡTopologicalSort
//���룺ͼ���ڽӱ������Žṹ
void printTopologicalSort(GraphL& G, TRes& topoList)
{
	if (topoList.len == G.VerNum)
	{
		for (int i = 1; i <= topoList.len; i++)
		{
			cout << topoList.data[i] << '(' << topoList.serial[i] << ")\t";
		}
	}
	else
	{
		cout << "���ɽ�����������";
	}
	cout << endl;
}


//******************************************************�ؼ�·����������******************************************************//

//������������ӡ��������
//���룺ͼ���ڽӾ���������������
void printKeyPath(GraphM& G, TRes topoList, int vet[], int vlt[])
{
	int i,j, v, w;
	int sum = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (vet[i] == 0)
		{
			cout << "�ؼ�·����\t";

			v = i;
			cout << G.Data[v] << '\t';

			for (j = 1; j <= G.VerNum; j++)
			{
				w = topoList.serial[j];
				if (G.AdjMatrix[v][w] > 0 && G.AdjMatrix[v][w] < INF)
				{
					if (vet[w] == vlt[w])
					{
						sum += G.AdjMatrix[v][w];
						cout << G.Data[w] << '\t';
						v = w;
					}
				}
			}

			cout << endl << "�ܳ��ȣ�" << sum << endl;
			sum = 0;
		}
	}
}


//ʵ���.ͼ.10����ؼ�·����
//���룺ͼ���ڽӾ���
//���أ��ɹ�����true��ʧ�ܷ���false
bool keyPath(GraphM& G)
{
	int i, j;
	int vPre, vSuc;								//���涥���ǰ�������š����涥��ĺ�̶�����
	TRes tLIn;
	int veTime[MaxVerNum + 1] = { 0 };			//���緢��ʱ��
	int vlTime[MaxVerNum + 1] = { 0 };			//������ʱ��
	int veTMax = 0;

	if (TopologicalSort(G, tLIn))
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			vPre = tLIn.serial[i];
			for (j = 1; j <= G.VerNum; j++)		//ȡ�����������еĵ�һ�����㣨��ţ�vPre
			{									//����vPre�����ڽӶ�������緢��ʱ��
				if (G.AdjMatrix[vPre][j] > 0 && G.AdjMatrix[vPre][j] < INF)
				{								//vPre��j ����
					if (veTime[j] < veTime[vPre] + G.AdjMatrix[vPre][j])
					{							//���¶���j�����緢��ʱ��
						veTime[j] = veTime[vPre] + G.AdjMatrix[vPre][j];
					}
				}
			}
		}

		for (i = 1; i <= G.VerNum; i++)			//��ʼ��ÿ���������ٷ���ʱ�䣬��ʼֵȫ����Ϊvet[G.VerNum] 
		{										//�����������л������緢��ʱ��
			vlTime[i] = veTime[tLIn.serial[G.VerNum]];
		}

		for (i = G.VerNum; i > 0; i--)
		{
			vSuc = tLIn.serial[i];
			for (j = G.VerNum; j > 0; j--)
			{
				if (G.AdjMatrix[j][vSuc] > 0 && G.AdjMatrix[j][vSuc] < INF)
				{
					if (vlTime[j] > vlTime[vSuc] - G.AdjMatrix[j][vSuc])
					{
						vlTime[j] = vlTime[vSuc] - G.AdjMatrix[j][vSuc];
					}
				}
			}
		}

		printKeyPath(G, tLIn, veTime, vlTime);

		return true;
	}
	else
	{
		cout << "��������ʧ�ܣ�" << endl;

		return false;
	}
}


//������������ȡ��������Ȩֵ
//���룺ͼ���ڽӱ���ʼ���㣬��������
//���أ��ɹ�����Ȩֵ��ʧ�ܷ��������INF��
int getWeight(GraphL& G, int vBegin, int vEnd)
{
	EdgeNode* p = nullptr;

	p = G.VerList[vBegin].firstEdge;
	while (p)
	{
		if (p->adjVer == vEnd)
		{
			return p->eInfo;
		}
		
		p = p->next;
	}

	return INF;
}


//������������ӡ��������
//���룺ͼ���ڽӱ�������������
void printKeyPath(GraphL& G, TRes topoList, int vet[], int vlt[])
{
	int i, j, v, w;
	int sum = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (vet[i] == 0)
		{
			cout << "�ؼ�·����\t";

			v = i;
			cout << G.VerList[v].data << '\t';

			for (j = 1; j <= G.VerNum; j++)
			{
				w = topoList.serial[j];
				if (getWeight(G, v, w) > 0 && getWeight(G, v, w) < INF)
				{
					if (vet[w] == vlt[w])
					{
						sum += getWeight(G, v, w);
						cout << G.VerList[w].data << '\t';
						v = w;
					}
				}
			}

			cout << endl << "�ܳ��ȣ�" << sum << endl;
			sum = 0;
		}
	}
}


//ʵ���.ͼ.10����ؼ�·����
//���룺ͼ���ڽӱ�
//���أ��ɹ�����true��ʧ�ܷ���false
bool keyPath(GraphL& G)
{
	int i, j;
	int vPre, vSuc;								//���涥���ǰ�������š����涥��ĺ�̶�����
	TRes tLIn;
	int veTime[MaxVerNum + 1] = { 0 };			//���緢��ʱ��
	int vlTime[MaxVerNum + 1] = { 0 };			//������ʱ��
	int veTMax = 0;

	if (TopologicalSort(G, tLIn))
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			vPre = tLIn.serial[i];
			for (j = 1; j <= G.VerNum; j++)		//ȡ�����������еĵ�һ�����㣨��ţ�vPre
			{									//����vPre�����ڽӶ�������緢��ʱ��
				if (getWeight(G, vPre, j) > 0 && getWeight(G, vPre, j) < INF)
				{								//vPre��j ����
					if (veTime[j] < veTime[vPre] + getWeight(G, vPre, j))
					{							//���¶���j�����緢��ʱ��
						veTime[j] = veTime[vPre] + getWeight(G, vPre, j);
					}
				}
			}
		}

		for (i = 1; i <= G.VerNum; i++)			//��ʼ��ÿ���������ٷ���ʱ�䣬��ʼֵȫ����Ϊvet[G.VerNum] 
		{										//�����������л������緢��ʱ��
			vlTime[i] = veTime[tLIn.serial[G.VerNum]];
		}

		for (i = G.VerNum; i > 0; i--)
		{
			vSuc = tLIn.serial[i];
			for (j = G.VerNum; j > 0; j--)
			{
				if (getWeight(G, j, vSuc) > 0 && getWeight(G, j, vSuc) < INF)
				{
					if (vlTime[j] > vlTime[vSuc] - getWeight(G, j, vSuc))
					{
						vlTime[j] = vlTime[vSuc] - getWeight(G, j, vSuc);
					}
				}
			}
		}

		printKeyPath(G, tLIn, veTime, vlTime);

		return true;
	}
	else
	{
		cout << "��������ʧ�ܣ�" << endl;

		return false;
	}
}