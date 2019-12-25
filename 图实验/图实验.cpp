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
		cout << "ʵ��ˣ�ͼʵ��" << endl;
		cout << "*****************************************" << endl;
		cout << "*1����ӡ��ͼ�����������ֱ�����\t*" << endl;
		cout << "*2�������ͼ�бߣ��򻡣�����Ŀ��\t*" << endl;
		cout << "*3���������������������ɭ�֡�\t*" << endl;
		cout << "*4���������������������ɭ�֡�\t*" << endl;
		cout << "*5��Prim�㷨��\t\t\t\t*" << endl;
		cout << "*6��Kruskal�㷨��\t\t\t*" << endl;
		cout << "*7��Dijkstra�㷨��\t\t\t*" << endl;
		cout << "*8��Floyd�㷨��\t\t\t\t*" << endl;
		cout << "*9��������ͼ���������С�\t\t*" << endl;
		cout << "*10��������AOE���Ĺؼ�·����\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			cout << "\t����.1��\t��ӡ��ͼ�����������ֱ�����" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udg8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��ȱ�����DFS����";
			BFS(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��ȱ�����DFS����";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���udg115.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[1], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��ȱ�����DFS����";
			BFS(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[1], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��ȱ�����DFS����";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dg6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��ȱ�����DFS����";
			BFS(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��ȱ�����DFS����";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���f14.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[3], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��ȱ�����DFS����";
			BFS(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[3], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��ȱ�����DFS����";
			BFS(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 2:
			system("cls");
			cout << "\t����.2��\t�����ͼ�бߣ��򻡣�����Ŀ" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udg8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������" << getEdgeNum(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���udg115.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[1], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������" << getEdgeNum(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[1], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dg6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������" << getEdgeNum(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���f14.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[3], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������" << getEdgeNum(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[3], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������" << getEdgeNum(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "\t����.3��\t�������������������ɭ��" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udg8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������������" << endl;
			DFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������������" << endl;
			DFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���dg6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������������" << endl;
			DFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������������" << endl;
			DFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������������" << endl;
			DFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������������" << endl;
			DFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "������������" << endl;
			DFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "������������" << endl;
			DFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
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
			cout << "\t����.4��\t�������������������ɭ��" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udg8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[0], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "������������" << endl;
			BFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[0], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "������������" << endl;
			BFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���dg6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[2], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "������������" << endl;
			BFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[2], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "������������" << endl;
			BFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "������������" << endl;
			BFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "������������" << endl;
			BFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "������������" << endl;
			BFSMakeTree(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "������������" << endl;
			BFSMakeTree(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
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
			cout << "\t����.5��\tPrim�㷨" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udn6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "��С��������" << endl;
			Prim(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "��С��������" << endl;
			Prim(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����BFS����";
			BFS(GM);
			cout << "��С��������" << endl;
			Prim(T, GM);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
			postTraverse(T);
			cout << endl;
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����BFS����";
			BFS(GL);
			cout << "��С��������" << endl;
			Prim(T, GL);
			cout << "���������";
			preTraverse(T);
			cout << endl;
			cout << "���������";
			inOrderTraverse(T);
			cout << endl;
			cout << "���������";
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
			cout << "\t����.6��\tKruskal�㷨" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udn6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��С��������" << endl;
			Kruskal(T, GM);
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��С��������" << endl;
			Kruskal(T, GL);
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "��С��������" << endl;
			Kruskal(T, GM);
			printBST(T);
			destoryTree(T);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "��С��������" << endl;
			Kruskal(T, GL);
			printBST(T);
			destoryTree(T);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 7:
			system("cls");
			cout << "\t����.7��\tDijkstra�㷨" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udn6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Dijkstra(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Dijkstra(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Dijkstra(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Dijkstra(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Dijkstra(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 8:
			system("cls");
			cout << "\t����.8��\tFloyd�㷨" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���udn6.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[6], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Floyd(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[6], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���un8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[4], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Floyd(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[4], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Floyd(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "���·����" << endl;
			Floyd(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "���·����" << endl;
			Floyd(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 9:
			system("cls");
			cout << "\t����.9��\t������ͼ����������" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���top6dg1.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[8], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�������У�" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[8], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�������У�" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���top7dg1.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[9], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�������У�" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[9], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�������У�" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�������У�" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�������У�" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//���������**********************************************************
			cout << "������ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�������У�" << endl;
			TopologicalSort(GM, topoList);
			printTopologicalSort(GM, topoList);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�������У�" << endl;
			TopologicalSort(GL, topoList);
			printTopologicalSort(GL, topoList);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 10:
			system("cls");
			cout << "\t����.10��\t������AOE���Ĺؼ�·��" << endl << endl;
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���dn8.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[7], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�ؼ�·����" << endl;
			keyPath(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[7], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�ؼ�·����" << endl;
			keyPath(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���dn10.grp����" << endl;
			cout << endl << "��1���ڽӾ���" << endl;
			CreateGrpFromFile(fileNames[5], GM);
			cout << "��ȱ�����DFS����";
			DFS(GM);
			cout << "�ؼ�·����" << endl;
			keyPath(GM);
			cout << endl << "��2���ڽӱ�" << endl;
			CreateGraphFromFile(fileNames[5], GL);
			cout << "��ȱ�����DFS����";
			DFS(GL);
			cout << "�ؼ�·����" << endl;
			keyPath(GL);
			DestroyGraph(GL);
			//********************************************************************
			cout << endl;
			break;
		case 0:
			cout << "�˳�����" << endl;
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}