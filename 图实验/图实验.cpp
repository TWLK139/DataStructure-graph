#include"graph.h"

int main(void)
{
	int order = 0;

	GraphM GM;
	GraphL GL;
	BiTree T = nullptr;
	char fileNames[][24] = { 
		"../grpData/udg8.grp" ,		//0
		"../grpData/udg115.grp",	//1
		"../grpData/dg6.grp",		//2
		"../grpData/f14.grp",		//3
		"../grpData/un8.grp",		//4
		"../grpData/dn10.grp",		//5
		"../grpData/udn6.grp" ,		//6
		"../grpData/dn8.grp",		//7
		"../grpData/top6dg1.grp",	//8
		"../grpData/top7dg1.grp"	//9
	};
	TRes topoList;

	while (1)
	{
		cout << "实验八：图实验" << endl;
		cout << "*****************************************" << endl;
		cout << "*1，打印出图（网）的两种遍历序。\t*" << endl;
		cout << "*2，求给定图中边（或弧）的数目。\t*" << endl;
		cout << "*3，深度优先序构造生成树或森林。\t*" << endl;
		cout << "*4，广度优先序构造生成树或森林。\t*" << endl;
		cout << "*5，Prim算法。\t\t\t\t*" << endl;
		cout << "*6，Kruskal算法。\t\t\t*" << endl;
		cout << "*7，Dijkstra算法。\t\t\t*" << endl;
		cout << "*8，Floyd算法。\t\t\t\t*" << endl;
		cout << "*9，求解给定图的拓扑序列。\t\t*" << endl;
		cout << "*10，求解给定AOE网的关键路径。\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			cout << "\t【八.1】\t打印出图（网）的两种遍历序" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udg8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "广度遍历（DFS）：";
			BFS(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "广度遍历（DFS）：";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：udg115.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[1], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "广度遍历（DFS）：";
			BFS(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[1], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "广度遍历（DFS）：";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：dg6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "广度遍历（DFS）：";
			BFS(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "广度遍历（DFS）：";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：f14.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[3], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "广度遍历（DFS）：";
			BFS(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[3], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "广度遍历（DFS）：";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "\t【八.2】\t求给定图中边（或弧）的数目" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udg8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "边数：" << getEdgeNum(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "边数：" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：udg115.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[1], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "边数：" << getEdgeNum(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[1], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "边数：" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：dg6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "边数：" << getEdgeNum(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "边数：" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：f14.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[3], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "边数：" << getEdgeNum(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[3], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "边数：" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "\t【八.3】\t深度优先序构造生成树或森林" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udg8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：dg6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "构造生成树：" << endl;
			DFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 4:
			system("cls");
			cout << "\t【八.4】\t广度优先序构造生成树或森林" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udg8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：dg6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "构造生成树：" << endl;
			BFSMakeTree(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 5:
			system("cls");
			cout << "\t【八.5】\tPrim算法" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udn6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "最小生成树：" << endl;
			Prim(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "最小生成树：" << endl;
			Prim(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "广度遍历（BFS）：";
			BFS(GM);
			cout << "最小生成树：" << endl;
			Prim(T, GM);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "广度遍历（BFS）：";
			BFS(GL);
			cout << "最小生成树：" << endl;
			Prim(T, GL);
			cout << "先序遍历：";
			preTraverse(T);
			cout << endl;
			cout << "中序遍历：";
			inOrderTraverse(T);
			cout << endl;
			cout << "后序遍历：";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			cout << "\t【八.6】\tKruskal算法" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udn6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最小生成树：" << endl;
			Kruskal(T, GM);
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最小生成树：" << endl;
			Kruskal(T, GL);
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最小生成树：" << endl;
			Kruskal(T, GM);
			printBST(T);
			destoryTree(T);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最小生成树：" << endl;
			Kruskal(T, GL);
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 7:
			system("cls");
			cout << "\t【八.7】\tDijkstra算法" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udn6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Dijkstra(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Dijkstra(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：dn8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Dijkstra(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Dijkstra(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 8:
			system("cls");
			cout << "\t【八.8】\tFloyd算法" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：udn6.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Floyd(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：un8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Floyd(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：dn8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Floyd(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "最短路径：" << endl;
			Floyd(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "最短路径：" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 9:
			system("cls");
			cout << "\t【八.9】\t求解给定图的拓扑序列" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：top6dg1.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[8], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[8], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：top7dg1.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[9], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[9], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第三组测试**********************************************************
			cout << "第三组实验（文件：dn8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第四组测试**********************************************************
			cout << "第四组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "拓扑序列：" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 10:
			system("cls");
			cout << "\t【八.10】\t求解给定AOE网的关键路径" << endl << endl;
			//第一组测试**********************************************************
			cout << "第一组实验（文件：dn8.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "关键路径：" << endl;
			keyPath(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "关键路径：" << endl;
			keyPath(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验（文件：dn10.grp）：" << endl;
			cout << endl << "（1）邻接矩阵：" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "深度遍历（DFS）：";
			DFS(GM);
			cout << "关键路径：" << endl;
			keyPath(GM);
			cout << endl << "（2）邻接表：" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "深度遍历（DFS）：";
			DFS(GL);
			cout << "关键路径：" << endl;
			keyPath(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 0:
			cout << "退出程序！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}