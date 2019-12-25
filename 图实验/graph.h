#pragma once
#ifndef GRAPH_H

#define GRAPH_H

#define DEBUG

#define INF 65535          //定义无穷大
#define MaxVerNum  100     //定义最大顶点个数

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<filesystem>

using namespace std;

typedef char elementType;									//定义图中顶点的数据类型
typedef int eInfoType;										//边链表中关于边的信息的数据类型，比如，带权图中可以表示边的权值  
typedef int cellType;										//邻接矩阵边值，无权图（1相邻，0不相邻）；有权图（为边的权值，无边是无穷大）
typedef enum { UDG, UDN, DG, DN } GraphKind;				//枚举图的类型--无向图，无向网，有向图，有向网

//***************************二叉树结构定义*****************************//
typedef struct lBNode													//
{																		//
	elementType data;													//
	struct lBNode* lChild, * rChild;									//
}BiNode, * BiTree;														//
//**********************************************************************//

//**************************改编数据链队列结构**************************//
//链队列结点结构														//
typedef struct LNode													//
{																		//
	BiTree point;								//结点地址存放			//
	int serial;									//存放元素序号			//
	elementType data;							//元素值存放			//
	struct LNode* next, * prior;				//下一个、上一个指针	//
}queueNode;																//
																		//
//链队列结构															//
typedef struct LNodes													//
{																		//
	queueNode* front;							//队头指针				//
	queueNode* rear;							//队尾指针				//
	bool flag = false;							//标记用于打印二叉树	//
}linkQueue, * lQP;														//
//**********************************************************************//

//***************************Prim算法边存储*****************************//
typedef struct minEdgeType												//
{																		//
	int v;										//边中已选一端顶点编号	//
	eInfoType eWeight;							//边的权值				//
} MinEdgeType;									//边数组的元素类型		//
//**********************************************************************//

//***************************Kruskal算法边存储**************************//
//边结点结构															//
typedef struct kEdgeType												//
{																		//
	int vBegin;									//边的起始顶点			//
	int vEnd;									//边的结束顶点			//
	eInfoType eWeight;							//边的权值				//
} KruskalEdge;									//边数组的元素类型		//
//边存储结构															//
typedef struct kEdges													//
{																		//
	KruskalEdge data[MaxVerNum + 1];									//
	int len = 0;														//
} KEdges;																//
//**********************************************************************//

//*************************Dijkstra算法结果存储*************************//
//结果结点结构															//
typedef struct DResNode													//
{																		//
	int path;									//保存最短路径信息		//
	int dist;									//保存最短路径值		//
} DijkstraResNode;														//
//结果存储结构															//
typedef struct DijkstraRes												//
{																		//
	DijkstraResNode data[MaxVerNum + 1];								//
	int len = 0;														//
} DRes;																	//
//**********************************************************************//

//***************************Floyd算法结果存储**************************//
//结果结构																//
typedef struct FResNode													//
{																		//
	int path[MaxVerNum + 1][MaxVerNum + 1];		//保存最短路径信息		//
	int dist[MaxVerNum + 1][MaxVerNum + 1];		//保存最短路径值		//
} FRes;																	//
//**********************************************************************//

//*********************TopologicalSort算法结果存储**********************//
//结果存储结构															//
typedef struct TopologicalSortRes										//
{																		//
	int serial[MaxVerNum + 1] = { -1 };									//
	elementType data[MaxVerNum + 1] = { '\0' };							//
	int len = 0;														//
} TRes;																	//
//**********************************************************************//

//*****************************************************图的邻接矩阵形式*****************************************************//
typedef struct GraphAdjMatrix																								//
{																															//
	elementType Data[MaxVerNum + 1];					//顶点数组，存放顶点元素的值，Data[0]单元不用						//
	cellType AdjMatrix[MaxVerNum + 1][MaxVerNum + 1];	//邻接矩阵，数组下标为0单元不用，从AdjMatrix[1][1]单元开始			//
	int VerNum;											//顶点数															//
	int ArcNum;											//弧（边）数														//
	GraphKind gKind;									//图的类型:0-无向图；1-无向网；2-有向图；3-有向网					//
} GraphM;												//图的类型名														//
//**************************************************************************************************************************//

//******************************************************图的邻接表形式******************************************************//
//边链表结点结构																											//
typedef struct eNode																										//
{																															//
	int adjVer;											//邻接顶点地址，此处为顶点在顶点表中序号，从1开始					//
	eInfoType eInfo;									//边链表中表示边的相关信息，比如表的权值							//
	struct eNode* next;									//指向边链表中的下一个结点											//
}EdgeNode;												//边链表结点类型													//
//顶点表中元素结构																											//
typedef struct vNode																										//
{																															//
	elementType data;									//存放图中顶点的数据												//
	EdgeNode* firstEdge;								//指向此顶点关联的第一条边的指针，即边链表的头指针					//
}VerNode;																													//
//图的邻接表结构																											//
typedef struct GraphAdjLinkList																								//
{																															//
	VerNode VerList[MaxVerNum + 1];						//存放顶点的顺序表，数组0单元不用									//
	int VerNum;											//顶点数															//
	int ArcNum;											//弧（边）数														//
	GraphKind gKind;									//图的类型:0-无向图；1-无向网；2-有向图；3-有向网					//
}GraphL;												//图的类型名														//
//**************************************************************************************************************************//


//******************************************************函数声明************************************************************//
//通用函数声明																												//
void strLTrim(char* str);																//删除字符串、字符数组左边空格		//
//队列函数声明																												//
bool initialQueue(lQP& Q);																//链队列初始化						//
bool enQueue(lQP Q, int data);															//链队列入队						//
bool enQueue(lQP Q, elementType data);													//链队列入队						//
bool enQueue(lQP Q, BiTree data);														//链队列入队						//
bool enQueue(lQP Q, int data, BiTree point);											//链队列入队						//
bool outQueue(lQP Q, int& data);														//链队列出队						//
bool outQueue(lQP Q, elementType& data);												//链队列出队						//
bool outQueue(lQP Q, BiTree& data);														//链队列出队						//
bool outQueue(lQP Q, int& data, BiTree& point);											//链队列出队						//
bool reOutQueue(lQP Q, int& data);														//链队列逆向出队（栈）				//
//二叉树通用函数声明																										//
bool addTreeNode(BiTree* Tpp, elementType x);											//二叉树创建新结点					//
void preTraverse(BiTree T);																//二叉树先序遍历					//
void inOrderTraverse(BiTree T);															//二叉树中序遍历					//
void postTraverse(BiTree T);															//二叉树后序遍历					//
void printBST(BiTree T);																//打印二叉树						//
void destoryTreeNode(BiTree T);															//销毁二叉树						//
bool destoryTree(BiTree& T);															//销毁二叉树						//
//邻接矩阵图函数声明																										//
int LocateVertex(GraphM& G, elementType v);												//图中查找目标顶点					//
int firstAdj(GraphM& G, int v);															//求第一个邻接点					//
int nextAdj(GraphM& G, int v, int w);													//求下一个邻接点					//
void printGraph(GraphM& G);																//打印图的相关信息					//
bool CreateGrpFromFile(char fileName[], GraphM& G);										//文件创建图						//
void DFS(GraphM& G, int verID, bool visited[]);											//深度优先遍历						//
bool DFS(GraphM& G, int verID = 1);														//深度优先遍历						//
bool BFS(GraphM& G, int verID = 1);														//广度优先遍历						//
int getEdgeNum(GraphM& G);																//求边数							//
void DFSMakeTree(BiTree& T, GraphM& G, int verID, bool visited[]);						//深度优先遍历创建树				//
bool DFSMakeTree(BiTree& T, GraphM& G, int verID = 1);									//深度优先遍历创建树				//
bool BFSMakeTree(BiTree& T, GraphM& G, int verID = 1);									//广度优先遍历创建树				//
//邻接表图函数声明																											//
int LocateVertex(GraphL& G, elementType v);												//图中查找目标顶点					//
int firstAdj(GraphL& G, int v);															//求第一个邻接点					//
int nextAdj(GraphL& G, int v, int w);													//求下一个邻接点					//
void printGraph(GraphL& G);																//打印图的相关信息					//
bool CreateGrpFromFile1(char fileName[], GraphL& G);									//文件创建图						//
bool CreateGraphFromFile(char fileName[], GraphL& G);									//文件创建图						//
void DestroyGraph(GraphL& G);															//销毁图							//
void DFS(GraphL& G, int verID, bool visited[]);											//深度优先遍历						//
bool DFS(GraphL& G, int verID = 1);														//深度优先遍历						//
bool BFS(GraphL& G, int verID = 1);														//广度优先遍历						//
int getEdgeNum(GraphL& G);																//求边数							//
void DFSMakeTree(BiTree& T, GraphL& G, int verID, bool visited[]);						//深度优先遍历						//
bool DFSMakeTree(BiTree& T, GraphL& G, int verID = 1);									//深度优先遍历						//
bool BFSMakeTree(BiTree& T, GraphL& G, int verID = 1);									//广度优先遍历创建树				//
//Prim算法																													//
bool HasEdge(GraphM& G, int vBegin, int vEnd, eInfoType& eWeight);						//判断是否有边						//
void InitialTE(GraphM& G, MinEdgeType TE[], int verID);									//初始化边数组						//
int GetMinEdge(GraphM& G, MinEdgeType TE[], bool visited[]);							//获取最小权值边					//
void UpdateTE(GraphM& G, MinEdgeType TE[], int vID, bool visited[]);					//更新侯选边数组					//
void Prim(BiTree& T, GraphM& G, int verID = 1);											//Prim算法							//
bool HasEdge(GraphL& G, int vBegin, int vEnd, eInfoType& eWeight);						//判断是否有边						//
void InitialTE(GraphL& G, MinEdgeType TE[], int verID);									//初始化边数组						//
int GetMinEdge(GraphL& G, MinEdgeType TE[], bool visited[]);							//获取最小权值边					//
void UpdateTE(GraphL& G, MinEdgeType TE[], int vID, bool visited[]);					//更新侯选边数组					//
void Prim(BiTree& T, GraphL& G, int verID = 1);											//Prim算法							//
//Kruskal算法																												//
void getEdges(GraphM& G, KEdges& edges);												//获取边							//
void getEdges(GraphL& G, KEdges& edges);												//获取边							//
KruskalEdge getMinEdge(GraphM& G, KEdges& edges, bool edgeUsed[], int& edgeIndex);		//获取最小边						//
KruskalEdge getMinEdge(GraphL& G, KEdges& edges, bool edgeUsed[], int& edgeIndex);		//获取最小边						//
void Kruskal(BiTree& T, GraphM& G);														//Kruskal算法						//
void Kruskal(BiTree& T, GraphL& G);														//Kruskal算法						//
//Dijkstra算法																												//
void printDijkstra(GraphM& G, DRes res, int verID);										//打印Dijkstra						//
void printDijkstra(GraphL& G, DRes res, int verID);										//打印Dijkstra						//
void Dijkstra(GraphM& G, int verID = 1);												//Dijkstra算法						//
void Dijkstra(GraphL& G, int verID = 1);												//Dijkstra算法						//
//Floyd算法																													//
void printFloyd(GraphM& G, FRes res);													//打印Floyd							//
void printFloyd(GraphL& G, FRes res);													//打印Floyd							//
void Floyd(GraphM& G);																	//Floyd算法							//
void Floyd(GraphL& G);																	//Floyd算法							//
//拓扑排序函数声明																											//
int getInDegree(GraphM& G, int v);														//获取初始入度						//
int getInDegree(GraphL& G, int v);														//获取初始入度						//
bool TopologicalSort(GraphM& G, TRes& topoList);										//拓扑排序							//
bool TopologicalSort(GraphL& G, TRes& topoList);										//拓扑排序							//
void printTopologicalSort(GraphM& G, TRes& topoList);									//打印Floyd							//
void printTopologicalSort(GraphL& G, TRes& topoList);									//打印Floyd							//
//关键路径函数声明																											//
int getWeight(GraphL& G, int vBegin, int vEnd);											//获取两顶点间的权值				//
void printKeyPath(GraphM& G, TRes topoList, int vet[], int vlt[]);						//打印关键路径						//
void printKeyPath(GraphL& G, TRes topoList, int vet[], int vlt[]);						//打印关键路径						//
bool keyPath(GraphM& G);																//求关键路径						//
bool keyPath(GraphL& G);																//求关键路径						//
//**************************************************************************************************************************//

#endif // !GRAPH_H

//*********************************************************函数定义*********************************************************//

//******************************************************通用函数定义******************************************************//

//辅助函数：删除字符串、字符数组左边空格
//输入：字符串指针
void strLTrim(char* str)
{
	int i, j;
	int n = 0;
	n = strlen(str) + 1;
	for (i = 0; i < n; i++)
	{
		if (str[i] != ' ')  //找到左起第一个非空格位置
			break;
	}
	//以第一个非空格字符为手字符移动字符串
	for (j = 0; j < n; j++)
	{
		str[j] = str[i];
		i++;
	}
}


//******************************************************链队列函数定义******************************************************//

//辅助函数：链队列初始化
//输入：队列指针
//返回：成功返回true，失败返回false
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
		cout << "当前指针已占用，队列初始化失败！" << endl;

		return false;
	}
}


//辅助函数：链队列入队
//输入：队列指针，入队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列入队
//输入：队列指针，入队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列入队
//输入：队列指针，入队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列入队
//输入：队列指针，入队元素值，入队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，入队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列出队
//输入：队列指针，出队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列出队
//输入：队列指针，出队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列出队
//输入：队列指针，出队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列出队
//输入：队列指针，出队元素值，出队指针
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//辅助函数：链队列逆向出队
//输入：队列头指针，元素存放地址
//返回：成功返回true，失败返回false
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
		cout << "当前队列未初始化，出队失败！" << endl;

		return false;
	}
}


//****************************************************二叉树通用函数声明****************************************************//

//辅助函数：二叉树创建新结点
//输入：二叉树指针，顺序表
//返回：成功返回true，失败返回false
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
		cout << "当前结点已占用！" << endl;

		return false;
	}
}


//辅助函数：求二叉树的高度
//输入：二叉树指针 
//返回：二叉树高度
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


//****************二叉树先序遍历****************
//辅助函数：二叉树先序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << '\t';
		preTraverse(T->lChild);
		preTraverse(T->rChild);
	}
}


//****************二叉树中序遍历****************
//辅助函数：二叉树中序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
void inOrderTraverse(BiTree T)
{
	if (T)
	{
		inOrderTraverse(T->lChild);
		cout << T->data << '\t';
		inOrderTraverse(T->rChild);
	}
}


//****************二叉树后序遍历****************
//辅助函数：二叉树后序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lChild);
		postTraverse(T->rChild);
		cout << T->data << '\t';
	}
}


//辅助函数：打印二叉排序树
//输入：二分查找树指针，顺序表
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


//辅助函数：销毁二叉树
//输入：二叉树根节点
void destoryTreeNode(BiTree T)
{
	if (T)
	{
		destoryTreeNode(T->lChild);
		destoryTreeNode(T->rChild);
		delete(T);
	}
}


//辅助函数：销毁二叉树
//输入：二叉树根节点
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


//****************************************************邻接矩阵图函数定义****************************************************//

//辅助函数：图中查找目标顶点
//输入：图的邻接矩阵，目标值
//返回：查找成功返回下标，失败返回-1
int LocateVertex(GraphM& G, elementType v)
{
	for (int i = 1; i <= G.VerNum; i++)
	{
		if (G.Data[i] == v)
			return i;
	}
	return -1;
}


//辅助函数：求第一个邻接点
//输入：图的邻接矩阵，顶点下标
//返回：查找成功返回下标，失败返回-1
int firstAdj(GraphM& G, int v)
{
	int w;
	for (w = 1; w <= G.VerNum; w++)
	{
		if ((G.AdjMatrix[v][w] >= 1) &&
			(G.AdjMatrix[v][w]) < INF)
			return w;    //返回第一个邻接点编号
	}
	return -1;          //未找到邻接点，返回-1
}


//辅助函数：求下一个邻接点
//输入：图的邻接矩阵，顶点下标，兄弟顶点下标
//返回：查找成功返回下标，失败返回-1
int nextAdj(GraphM& G, int v, int w)
{
	int k;
	for (k = w + 1; k <= G.VerNum; k++)
	{
		if ((G.AdjMatrix[v][k] >= 1) &&
			(G.AdjMatrix[v][k]) < INF)
			return k;    //返回v的位于w之后的下一个邻接点k
	}
	return -1;           //不存在下一个邻接点，返回-1
}


//辅助函数：打印图的相关信息
//输入：图的邻接矩阵
void printGraph(GraphM& G)
{
	int i = 0, j = 0;
	//打印图的类型
	switch (G.gKind)
	{
	case UDG:
		cout << "图类型：无向图" << endl;
		break;
	case UDN:
		cout << "图类型：无向网" << endl;
		break;
	case DG:
		cout << "图类型：有向图" << endl;
		break;
	case DN:
		cout << "图类型：有向网" << endl;
		break;
	default:
		cout << "图类型错误。" << endl;
		break;
	}
	//打印图的顶点数
	cout << "顶点数：" << G.VerNum << endl;
	//打印图的边数
	cout << "边  数：" << G.ArcNum << endl;
	//打印顶点及其编号
	cout << "编  号：";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << "顶  点：";
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << G.Data[i] << "\t";
	}
	cout << endl;

	//打印邻接矩阵
	cout << "图的邻接矩阵：" << endl;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << "\t";
		for (j = 1; j <= G.VerNum; j++)
		{
			if ((G.gKind == UDN || G.gKind == DN) && G.AdjMatrix[i][j] == INF)
				cout << "INF" << "\t";  //网，无穷大时，打印“INF”表示
			else
				cout << G.AdjMatrix[i][j] << "\t";
		}
		cout << endl;
	}

}


//辅助函数：从文件创建图
//输入：文件名，图的邻接矩阵
//返回：成功返回true，失败返回false
bool CreateGrpFromFile(char fileName[], GraphM& G)
{
	FILE* pFile;      //定义顺序表的文件指针
	char str[1000];   //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行

	cellType  eWeight;		//边的信息，常为边的权值
	GraphKind GrpType;		//图类型枚举变量

	pFile = fopen(fileName, "r");
	if (!pFile)
	{

		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //跳过注释行
			continue;
		else  //非注释行、非空行，跳出循环
			break;
	}

	//循环结束，str中应该已经是文件标识，判断文件格式
	if (strstr(str, "Graph") == NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取图的类型，跳过空行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的类型标识
			break;
	}

	//设置图的类型
	if (strstr(str, "UDG"))
		GrpType = UDG;  //无向图
	else if (strstr(str, "UDN"))
		GrpType = UDN;  //无向网
	else if (strstr(str, "DG"))
		GrpType = DG;   //有向图
	else if (strstr(str, "DN"))
		GrpType = DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取顶点元素，到str。跳过空行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

	//顶点数据放入图的顶点数组	
	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL)
	{
		G.Data[nNum] = *token; // atoi(token);	//顶点数据转换为整数，若为字符则不需转换		
		token = strtok(NULL, " ");
		nNum++;
	}
	nNum--;   //顶点数

	//图的邻接矩阵初始化
	int nRow = 1;  //矩阵行下标，从1开始
	int nCol = 1;  //矩阵列下标，从1开始
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
				G.AdjMatrix[nRow][nCol] = INF;  //INF表示无穷大
	}

	//循环读取边的数据到邻接矩阵

	int edgeNum = 0;  //边的数量
	elementType Nf, Ns; //边或弧的2个相邻顶点
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;

		char* token = strtok(str, " ");  //以空格为分隔符，分割一行数据，写入邻接矩阵

		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf = *token;  //获取边的第一个顶点

		token = strtok(NULL, " ");  //读取下一个子串，即第二个顶点
		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns = *token;  //获取边的第二个顶点
			//从第一个顶点获取行号		
		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.Data[nRow] == Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
		//从第二个顶点获取列号		
		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.Data[nCol] == Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		//如果为网，读取权值
		if (GrpType == UDN || GrpType == DN)
		{
			token = strtok(NULL, " ");  //读取下一个子串，即边的附加信息，常为边的权重
			if (token == NULL)  //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile); //关闭文件
				return false;
			}
			eWeight = atoi(token);  //取得边的附加信息
		}
		if (GrpType == UDN || GrpType == DN)  //如果为网，邻接矩阵中对应的边设置权值，否则置为1
			G.AdjMatrix[nRow][nCol] = eWeight;
		else
			G.AdjMatrix[nRow][nCol] = 1;  //atoi(token);	//字符串转为整数

		edgeNum++;   //边数加1
	}

	G.VerNum = nNum;  //图的顶点数
	if (GrpType == UDG || GrpType == UDN)
		G.ArcNum = edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum = edgeNum;

	G.gKind = GrpType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}


//辅助函数：深度优先遍历图
//输入：图的邻接矩阵，开始节点下标，标记数组
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


//实验八.图.1：图（网）的深度优先遍历序
//输入：图的地址，开始结点序号（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.1：图（网）的广度优先遍历序
//输入：图的邻接矩阵，开始节点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.2：求边数
//输入：图的邻接矩阵
//返回：成功返回边数，失败返回0
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


//辅助函数：深度优先遍历创建树
//输入：树存储地址，图的邻接矩阵，开始节点下标，标记数组
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


//实验八.图.3：图（网）的深度优先遍历创建树
//输入：树存储地址，图的地址，开始结点序号（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.4：图（网）的广度优先遍历创建树
//输入：树存储地址，图的邻接矩阵，开始节点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//******************************************************邻接表图函数定义******************************************************//

//辅助函数：图中查找目标顶点
//输入：图的邻接表，目标值
//返回：查找成功返回下标，失败返回-1
int LocateVertex(GraphL& G, elementType v)
{
	for (int i = 1; i <= G.VerNum; i++)
	{
		if (G.VerList[i].data == v)
			return i;
	}
	return -1;
}


//辅助函数：求第一个邻接点
//输入：图的邻接表，顶点下标
//返回：查找成功返回下标，失败返回-1
int firstAdj(GraphL& G, int v)
{
	EdgeNode* p;
	p = G.VerList[v].firstEdge;
	if (p)
		return p->adjVer;
	else
		return -1;
}


//辅助函数：求下一个邻接点
//输入：图的邻接表，顶点下标，兄弟顶点下标
//返回：查找成功返回下标，失败返回-1
int nextAdj(GraphL& G, int v, int w)
{
	EdgeNode* p;
	p = G.VerList[v].firstEdge;         //取顶点v的边链表头指针
	while (p->next)
	{
		if (p->adjVer == w)
			return p->next->adjVer;  //返回w之后下一个邻接点编号
		p = p->next;
	}

	return -1;                        //未找到下一个邻接点，返回-1
}


//辅助函数：打印图的相关信息
//输入：图的邻接表
void printGraph(GraphL& G)
{
	int i = 0, j = 0;
	//打印图的类型
	switch (G.gKind)
	{
	case UDG:
		cout << "图类型：无向图" << endl;
		break;
	case UDN:
		cout << "图类型：无向网" << endl;
		break;
	case DG:
		cout << "图类型：有向图" << endl;
		break;
	case DN:
		cout << "图类型：有向网" << endl;
		break;
	default:
		cout << "图类型错误。" << endl;
		break;
	}
	//打印图的顶点数
	cout << "顶点数：" << G.VerNum << endl;
	//打印图的边数
	cout << "边  数：" << G.ArcNum << endl;
	//打印顶点及其编号
	cout << "编号\t顶点\t边链表" << endl;
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
	//打印邻接矩阵
	cout << "邻接矩阵：" << endl;
	for (i = 1; i <= G.VerNum; i++)
	{
		cout << "\t";
		p = G.VerList[i].firstEdge;
		j = 1;
		while (p != NULL || j <= G.VerNum)
		{
			if ((j <= G.VerNum) && (p != NULL) && j == p->adjVer)  //有边
			{
				cout << p->eInfo << "\t";
				j++;
				p = p->next;
			}
			else   //无边
			{
				if (G.gKind == UDN || G.gKind == DN)
					cout << "INF" << "\t";  //网，无边时打印权值为无穷大，用“INF”表示
				else
					cout << "0" << "\t";    //图，无边时用0表示
				j++;
			}

		}
		cout << endl;
	}
}


//辅助函数：从文件创建图
//输入：文件名，图的邻接矩阵
//返回：成功返回true，失败返回false
//备注：本函数使用的数据文件以邻接矩阵为输入数据
bool CreateGrpFromFile1(char fileName[], GraphL& G)
{
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000];  //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行
	char* ss;
	int i = 0, j = 0;
	int edgeNum = 0;  //边的数量

	GraphKind graphType;  //图类型枚举变量

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}

	ss = fgets(str, 1000, pFile);
	strncpy(strTemp, str, 2);
	while ((ss != NULL) && (strstr(strTemp, "//") != NULL))  //跳过注释行
	{
		ss = fgets(str, 1000, pFile);
		strncpy(strTemp, str, 2);
		//cout<<strTemp<<endl;
	}
	//循环结束，str中应该已经是文件标识，判断文件格式
//cout<<str<<endl;
	if (strstr(str, "Graph") == NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}
	//读取图的类型
	if (fgets(str, 1000, pFile) == NULL)
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}
	//设置图的类型
	if (strstr(str, "UDG"))
		graphType = UDG;  //无向图
	else if (strstr(str, "UDN"))
		graphType = UDN;  //无向网
	else if (strstr(str, "DG"))
		graphType = DG;   //有向图
	else if (strstr(str, "DN"))
		graphType = DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取顶点元素，到str
	if (fgets(str, 1000, pFile) == NULL)
	{
		printf("错误：读取图的顶点元素失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}


	//顶点数据放入图的顶点数组		
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

	//循环读取邻接矩阵数据
	int nRow = 1;  //矩阵行下标
	int nCol = 1;  //矩阵列下标
	EdgeNode* eR;  //边链表尾指针
	EdgeNode* p;

	while (fgets(str, 1000, pFile) != NULL)
	{
		eR = NULL;
		p = NULL;
		nCol = 1;  //列号设为0，一行重新开始
		char* token = strtok(str, " ");  //以空格为分隔符，分割一行数据，写入邻接矩阵
		while (token != NULL)
		{
			if (atoi(token) >= 1 && atoi(token) < INF)  //考虑到网
			{
				p = new EdgeNode;  //申请一个边链表结点
				p->adjVer = nCol;   //顶点的编号，从1开始
				p->eInfo = atoi(token);  //有权图保存权值，无权图为1
				p->next = NULL;
				if (G.VerList[nRow].firstEdge == NULL)
				{
					G.VerList[nRow].firstEdge = p;
					eR = p;
				}
				else
				{
					eR->next = p;
					eR = p;  //新的尾指针				
				}
				edgeNum++;   //边数加1
			}
			token = strtok(NULL, " ");  //读取下一个子串
			nCol++;
		}
		nRow++; //一行数据处理完毕
	}

	G.VerNum = nNum;  //图的顶点数
	if (graphType == UDG || graphType == UDN)
		G.ArcNum = edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum = edgeNum;

	G.gKind = graphType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}


//辅助函数：从文件创建图
//输入：文件名，图的邻接矩阵
//返回：成功返回true，失败返回false
//备注：本函数使用的数据文件格式以边（顶点对）为基本数据
bool CreateGraphFromFile(char fileName[], GraphL& G)
{
	FILE* pFile;     //定义顺序表的文件指针
	char str[1000];  //存放读出一行文本的字符串
	char strTemp[10]; //判断是否注释行

	int i = 0, j = 0;
	int edgeNum = 0;  //边的数量

	eInfoType eWeight;  //边的信息，常为边的权值
	GraphKind graphType;  //图类型枚举变量

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)  //跳过空行和注释行
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //跳过注释行
			continue;
		else  //非注释行、非空行，跳出循环
			break;
	}

	//循环结束，str中应该已经是文件标识，判断文件格式
	if (strstr(str, "Graph") == NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile); //关闭文件
		return false;
	}

	//读取图的类型，跳过空行及注释行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的类型标识
			break;

	}

	//设置图的类型
	if (strstr(str, "UDG"))
		graphType = UDG;  //无向图
	else if (strstr(str, "UDN"))
		graphType = UDN;  //无向网
	else if (strstr(str, "DG"))
		graphType = DG;   //有向图
	else if (strstr(str, "DN"))
		graphType = DN;   //有向网
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile); //关闭文件
		return false;
	}


	//读取顶点元素，到str。跳过空行
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;
		else  //非空行，也非注释行，即图的顶点元素行
			break;
	}

	//顶点数据放入图的顶点数组		
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

	//循环读取边（顶点对）数据
	int nRow = 1;  //矩阵行下标
	int nCol = 1;  //矩阵列下标
	EdgeNode* eR;  //边链表尾指针
	EdgeNode* p;

	elementType Nf, Ns; //边或弧的2个相邻顶点
	while (fgets(str, 1000, pFile) != NULL)
	{
		//删除字符串左边空格
		strLTrim(str);
		if (str[0] == '\n')  //空行，继续读取下一行
			continue;

		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL)  //注释行，跳过，继续读取下一行
			continue;

		//nCol=0;  //列号设为0，一行重新开始
		char* token = strtok(str, " ");  //以空格为分隔符，分割一行数据，写入邻接矩阵

		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}
		Nf = *token;  //获取边的第一个顶点

		token = strtok(NULL, " ");  //读取下一个子串，即第二个顶点
		if (token == NULL)  //分割为空串，失败退出
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile); //关闭文件
			return false;
		}

		Ns = *token;  //获取边的第二个顶点
			//从第一个顶点获取行号		
		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.VerList[nRow].data == Nf)  //从顶点列表找到第一个顶点的编号
				break;
		}
		//从第二个顶点获取列号		
		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.VerList[nCol].data == Ns)  //从顶点列表找到第二个顶点的编号
				break;
		}

		//如果为网，读取权值
		if (graphType == UDN || graphType == DN)
		{
			token = strtok(NULL, " ");  //读取下一个子串，即边的附加信息，常为边的权重
			if (token == NULL)  //分割为空串，失败退出
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile); //关闭文件
				return false;
			}
			eWeight = atoi(token);  //取得边的附加信息
		}


		eR = G.VerList[nRow].firstEdge;
		while (eR != NULL && eR->next != NULL)
		{
			eR = eR->next;  //后移边链表指针，直至尾节点
		}

		p = new EdgeNode;  //申请一个边链表结点
		p->adjVer = nCol;   //顶点的编号，从1开始
		if (graphType == UDN || graphType == DN) //边的附加信息，对有权图保存权值，无权图为1
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
			eR = p;  //新的尾指针				
		}

		edgeNum++;   //边数加1
	}



	G.VerNum = nNum;  //图的顶点数
	if (graphType == UDG || graphType == UDN)
		G.ArcNum = edgeNum / 2;  //无向图或网的边数等于统计的数字除2  
	else
		G.ArcNum = edgeNum;

	G.gKind = graphType;  //图的类型

	fclose(pFile); //关闭文件
	return true;
}


//辅助函数：销毁邻接表图
//输入：图的邻接表
void DestroyGraph(GraphL& G)
{
	EdgeNode* p, * u;
	int vID;
	for (vID = 1; vID <= G.VerNum; vID++)  //循环删除每个顶点的边链表
	{
		p = G.VerList[vID].firstEdge;
		G.VerList[vID].firstEdge = NULL;
		while (p)  //循环删除当前顶点所有的关联边 
		{
			u = p->next;  //u指向下一个边结点
			delete(p);  //删除当前边结点
			p = u;
		}
	}
	p = NULL;
	u = NULL;
	G.VerNum = -1;  //编辑图已经销毁
}


//辅助函数：深度优先遍历图
//输入：图的邻接表，开始节点下标，标记数组
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


//实验八.图.1：图（网）的深度优先遍历序
//输入：图的地址，开始结点序号（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.1：图（网）的广度优先遍历序
//输入：图的邻接矩阵，开始节点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.2：求边数
//输入：图的邻接矩阵
//返回：成功返回边数，失败返回0
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


//辅助函数：深度优先遍历创建树
//输入：树的存储地址，图的邻接表，开始节点下标，标记数组
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


//实验八.图.3：图（网）的深度优先遍历创建树
//输入：树的存储地址，图的邻接表，开始结点序号（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//实验八.图.4：图（网）的广度优先遍历创建树
//输入：树存储地址，图的邻接表，开始节点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
		cout << "结点序号错误！" << endl;
#endif // DEBUG

		return false;
	}
}


//******************************************************Prim算法函数定义******************************************************//

//辅助函数：判断两顶点之间是否有边
//输入：树存储地址，开始结点下标，结束结点下标，权重存储地址
//返回：存在返回true，全职存在引用中；不存在返回false，引用值为INF
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


//辅助函数：初始化边数组
//输入：树存储地址，边数组地址，已选顶点
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


//辅助函数：获取权值最小边
//输入：树存储地址，边数组地址，标记数组
//返回：查找成功返回序号，失败返回0
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


//辅助函数：更新边数组
//输入：树存储地址，边数组地址，元素序号，标记数组
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


//实验八.图.5：Prim算法
//输入：图的邻接矩阵，开始结点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
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
				cout << "0--( 断点)->" << G.Data[i] << endl;
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


//辅助函数：判断两顶点之间是否有边
//输入：树存储地址，开始结点下标，结束结点下标，权重存储地址
//返回：存在返回true，权值存在引用中；不存在返回false，引用值为INF
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


//辅助函数：初始化边数组
//输入：树存储地址，边数组地址，已选顶点
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


//辅助函数：获取权值最小边
//输入：树存储地址，边数组地址，标记数组
//返回：查找成功返回序号，失败返回0
int GetMinEdge(GraphL& G, MinEdgeType TE[], bool visited[])
{
	eInfoType eMin = INF;								//保存最小的权值，初始化为无穷大
	int i, res = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (visited[i] == false && TE[i].eWeight < eMin)
		{
			res = i;
			eMin = TE[i].eWeight;
		}
	}

	return res;											//对应的边（TE[j].v, j）为选中的边
}


//辅助函数：更新边数组
//输入：树存储地址，边数组地址，元素序号，标记数组
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


//实验八.图.5：Prim算法
//输入：树存储地址，图的邻接表，开始结点下标（默认为1，序号对应下标，0下标位置不使用）
//返回：序号可查返回true，否则返回false
void Prim(BiTree& T, GraphL& G, int verID)
{
	MinEdgeType TE[MaxVerNum + 1];
	int i, curID;
	bool visited[MaxVerNum + 1] = { false };
	//创建树辅助声明
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
				cout << "0--( 断点)->" << G.VerList[i].data << endl;
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


//******************************************************Kruskal算法函数定义******************************************************//

//辅助函数：获取边函数
//输入：图地址，边存储结构
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


//辅助函数：获取最小边函数
//输入：图地址，边存储结构，边标记数组，边下标存放地址
//返回：边数结点结构
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


//实验八.图.6：Kruskal算法
//输入：树存储地址，图的邻接表
void Kruskal(BiTree& T, GraphM& G)
{
	int conVerID[MaxVerNum + 1];				//顶点的连通分量编号数组
	KEdges edges;								//存放图的所有信息
	KEdges treeEdges;							//存放生成树中的n-1条边信息
	bool edgeUsed[MaxVerNum + 1] = { false };	//标记边是否已用数组
	KruskalEdge minEdge;
	int i, j;
	int k = 1;
	int conID;									//边的终止顶点vEnd的连通分量的编号
	int edgeIndex;								//最小边下标存放
	////创建树辅助声明
	//lQP Q = nullptr;
	//BiTree* NT = &T, temp = nullptr;

	getEdges(G, edges);
	for (i = 1; i <= G.VerNum; i++)				//初始化连通分量
	{
		conVerID[i] = i;						//连通分量编号等于定点编号
	}

	for (i = 1; i < G.VerNum; i++)				//注意只需取出n-1条边
	{
		minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd])
		{										//如果构成回路
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


//辅助函数：获取边函数
//输入：图地址，边存储结构
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


//辅助函数：获取最小边函数
//输入：图地址，边存储结构，边标记数组，边下标存放地址
//返回：边数结点结构
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


//实验八.图.6：Kruskal算法
//输入：树存储地址，图的邻接表
void Kruskal(BiTree& T, GraphL& G)
{
	int conVerID[MaxVerNum + 1];				//顶点的连通分量编号数组
	KEdges edges;								//存放图的所有信息
	KEdges treeEdges;							//存放生成树中的n-1条边信息
	bool edgeUsed[MaxVerNum + 1] = { false };	//标记边是否已用数组
	KruskalEdge minEdge;
	int i, j;
	int k = 1;
	int conID;									//边的终止顶点vEnd的连通分量的编号
	int edgeIndex;								//最小边下标存放
	////创建树辅助声明
	//lQP Q = nullptr;
	//BiTree* NT = &T, temp = nullptr;

	getEdges(G, edges);
	for (i = 1; i <= G.VerNum; i++)				//初始化连通分量
	{
		conVerID[i] = i;						//连通分量编号等于定点编号
	}

	for (i = 1; i < G.VerNum; i++)				//注意只需取出n-1条边
	{
		minEdge = getMinEdge(G, edges, edgeUsed, edgeIndex);
		while (conVerID[minEdge.vBegin] == conVerID[minEdge.vEnd])
		{										//如果构成回路
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


//******************************************************Dijkstra算法函数定义******************************************************//

//辅助函数：打印Dijkstra
//输入：图的邻接矩阵，结果存放结构，指定起点
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
			cout << "(不可达)";
		}
		else
		{
			cout << '(' << res.data[i].dist << ')';
		}
		cout << "--" << G.Data[i] << "\t路径：\t";

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


//辅助函数：打印Dijkstra
//输入：图的邻接矩阵，结果存放结构，指定起点
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
			cout << "(不可达)";
		}
		else
		{
			cout << '(' << res.data[i].dist << ')';
		}
		cout << "--" << G.VerList[i].data << "\t路径：\t";

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


//实验八.图.7：Dijkstra算法
//输入：图的邻接矩阵，指定起点（默认为1，元素下标等于序号）
void Dijkstra(GraphM& G, int verID)
{												//path保存最短路径信息，dist保存最短路径值，verID为指定起点
	bool solved[MaxVerNum + 1] = { false };		//标记是否解出最短路径
	int i, j, v;
	cellType minDist;							//最短距离
	DRes res;

	for (i = 1; i <= G.VerNum; i++)
	{
		res.data[i].dist = G.AdjMatrix[verID][i];
		if (res.data[i].dist != INF)
		{
			res.data[i].path = verID;					//第i个顶点的前驱为verID
		}
		else
		{
			res.data[i].path = -1;						//无前驱
		}
	}
	res.len = G.VerNum;
	solved[verID] = true;						//初始化起点
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


//实验八.图.7：Dijkstra算法
//输入：图的邻接矩阵，指定起点（默认为1，元素下标等于序号）
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


//******************************************************Floyd算法函数定义******************************************************//

//辅助函数：打印Floyd
//输入：图的邻接矩阵，结果存放结构
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
				cout << "(不可达)";
			}
			else
			{
				cout << '(' << res.dist[i][j] << ')';
			}
			cout << "--" << G.Data[j] << "\t路径：\t";

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


//辅助函数：打印Floyd
//输入：图的邻接表，结果存放结构
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
				cout << "(不可达)";
			}
			else
			{
				cout << '(' << res.dist[i][j] << ')';
			}
			cout << "--" << G.VerList[j].data << "\t路径：\t";

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


//实验八.图.8：Floyd算法
//输入：图的邻接矩阵
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


//实验八.图.8：Floyd算法
//输入：图的邻接矩阵
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


//******************************************************拓扑排序函数定义******************************************************//

//辅助函数：获取顶点入度
//输入：图的邻接矩阵，起始顶点
//返回：当前结点的入度
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


//辅助函数：获取顶点入度
//输入：图的邻接表，起始顶点
//返回：当前结点的入度
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


//实验八.图.9：拓扑排序
//输入：图的邻接矩阵，结果存放数组
//返回：可以进行拓扑排序返回true，否则返回false
bool TopologicalSort(GraphM& G, TRes& topoList)
{
	int inds[MaxVerNum + 1] = { 0 };					//顶点入度数组
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


//实验八.图.9：拓扑排序
//输入：图的邻接矩阵，结果存放数组
//返回：可以进行拓扑排序返回true，否则返回false
bool TopologicalSort(GraphL& G, TRes& topoList)
{
	int inds[MaxVerNum + 1] = { 0 };					//顶点入度数组
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


//辅助函数：打印TopologicalSort
//输入：图的邻接矩阵，结果存放结构
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
		cout << "不可进行拓扑排序！";
	}
	cout << endl;
}


//辅助函数：打印TopologicalSort
//输入：图的邻接表，结果存放结构
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
		cout << "不可进行拓扑排序！";
	}
	cout << endl;
}


//******************************************************关键路径函数定义******************************************************//

//辅助函数：打印拓扑排序
//输入：图的邻接矩阵，拓扑排序数组
void printKeyPath(GraphM& G, TRes topoList, int vet[], int vlt[])
{
	int i,j, v, w;
	int sum = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (vet[i] == 0)
		{
			cout << "关键路径：\t";

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

			cout << endl << "总长度：" << sum << endl;
			sum = 0;
		}
	}
}


//实验八.图.10：求关键路径函
//输入：图的邻接矩阵
//返回：成功返回true，失败返回false
bool keyPath(GraphM& G)
{
	int i, j;
	int vPre, vSuc;								//保存顶点的前驱顶点编号、保存顶点的后继顶点编号
	TRes tLIn;
	int veTime[MaxVerNum + 1] = { 0 };			//最早发生时间
	int vlTime[MaxVerNum + 1] = { 0 };			//最晚发生时间
	int veTMax = 0;

	if (TopologicalSort(G, tLIn))
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			vPre = tLIn.serial[i];
			for (j = 1; j <= G.VerNum; j++)		//取出拓扑序列中的第一个顶点（编号）vPre
			{									//更新vPre所有邻接顶点的最早发生时间
				if (G.AdjMatrix[vPre][j] > 0 && G.AdjMatrix[vPre][j] < INF)
				{								//vPre与j 相邻
					if (veTime[j] < veTime[vPre] + G.AdjMatrix[vPre][j])
					{							//更新顶点j的最早发生时间
						veTime[j] = veTime[vPre] + G.AdjMatrix[vPre][j];
					}
				}
			}
		}

		for (i = 1; i <= G.VerNum; i++)			//初始化每个顶点的最迟发生时间，初始值全部置为vet[G.VerNum] 
		{										//即：拓扑序列汇点的最早发生时间
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
		cout << "拓扑排序失败！" << endl;

		return false;
	}
}


//辅助函数：获取两顶点间的权值
//输入：图的邻接表，起始顶点，结束顶点
//返回：成功返回权值，失败返回无穷大（INF）
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


//辅助函数：打印拓扑排序
//输入：图的邻接表，拓扑排序数组
void printKeyPath(GraphL& G, TRes topoList, int vet[], int vlt[])
{
	int i, j, v, w;
	int sum = 0;

	for (i = 1; i <= G.VerNum; i++)
	{
		if (vet[i] == 0)
		{
			cout << "关键路径：\t";

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

			cout << endl << "总长度：" << sum << endl;
			sum = 0;
		}
	}
}


//实验八.图.10：求关键路径函
//输入：图的邻接表
//返回：成功返回true，失败返回false
bool keyPath(GraphL& G)
{
	int i, j;
	int vPre, vSuc;								//保存顶点的前驱顶点编号、保存顶点的后继顶点编号
	TRes tLIn;
	int veTime[MaxVerNum + 1] = { 0 };			//最早发生时间
	int vlTime[MaxVerNum + 1] = { 0 };			//最晚发生时间
	int veTMax = 0;

	if (TopologicalSort(G, tLIn))
	{
		for (i = 1; i <= G.VerNum; i++)
		{
			vPre = tLIn.serial[i];
			for (j = 1; j <= G.VerNum; j++)		//取出拓扑序列中的第一个顶点（编号）vPre
			{									//更新vPre所有邻接顶点的最早发生时间
				if (getWeight(G, vPre, j) > 0 && getWeight(G, vPre, j) < INF)
				{								//vPre与j 相邻
					if (veTime[j] < veTime[vPre] + getWeight(G, vPre, j))
					{							//更新顶点j的最早发生时间
						veTime[j] = veTime[vPre] + getWeight(G, vPre, j);
					}
				}
			}
		}

		for (i = 1; i <= G.VerNum; i++)			//初始化每个顶点的最迟发生时间，初始值全部置为vet[G.VerNum] 
		{										//即：拓扑序列汇点的最早发生时间
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
		cout << "拓扑排序失败！" << endl;

		return false;
	}
}