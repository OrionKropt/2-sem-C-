#include <iostream>
#include <stack>
#include <queue>


using namespace std;

//
// Timus 1145
// 
// BFS ��� DFS 
// ���� ���� �� ������� ���������
// �������
// ������ ������� 
// ������ ������������
// ������ ����������� �����
// 
// ��������� ��������� ������ � ������� � � ������ (���� ������� ������ �� O(n+m) ���� ������� ��������� O(n^2)
// 
// �������� ��������:
// 1. �������� �� ��������
// 2. ������� ������ � �����
// 3. ��������� ���������
// 4. ��������� ��� ���
// 5. �������� �� �������
// 6. ����� ����� ��������� � ����� � ������� BFS
// 7. ����������� �������� �� ���������� ����
// 8. ����� ����������� ���� ����� ����� ���������
// 
// ��� ��������� ������������ �����?
// ���� ���� ���������� ����� �� ����� ���� �� �� ����������
// 
// ������ ���� ���� � ������� ���������
// ���� BFS ������� ������� ���������� ���� ��� ���
//
// 
// �������� �� stl �������� ������ � list, forwardlist stack (������� ���������� �� ������ � �� �����) queue ��� ��� 
// 
// ���� - ������� ������ ��������� �����
// 
// ����� ��������� 1837
// � ������ ������� ���� ������ ������
// ������� ������ ����� � ���� �� ������� ��������� 
// ������ bfs �� isinbaev
// 
// 
//




class Graph
{
public:
	Graph(int** arr, int r, int n)
	{
		this->r = r;
		this->n = n;
		adj = new int*[r];
		for (int i = 0; i < r; ++i)
			adj[i] = new int[n];
		for (int i =0; i < r; ++i)
			for (int j = 0; j < n; ++j)
			{
				adj[i][j] = arr[i][j];
			}
	}
	bool bfs();
	int** adj;
	int r;
	int n;
};

int main()
{
	//int adj[r][n]; // ������� ���������
	//int parent[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	//int used[8] = {0};
	//queue<int> q;
	//q.push(1);
	//while (q.empty())
	//{
	//	auto v = q.front();
	//	q.pop();
	//	for (int i = 0; i < 8; ++i)
	//	{
	//		if (adj[v][i] == 1 && used[i] == 0)
	//		{
	//			q.push(i);
	//			parent[i] = v;
	//			used[i] = 1;
	//		}
	//	}
	// }

	
	return 0;
}



bool Graph::bfs()
{
	queue<int> Q;
	int* used = new int[n + 1] {0};
	Q.push(1);

	int d = 1;
	used[1] = d;
	while (!Q.empty())
	{
		auto v = Q.back();
		Q.pop();
		if (d == 1) d = 2;
		else d = 1;
		for (int i = 0; i < n; ++i)
		{
			if (used[i] != 0 && (used[i] % 2 + 1) == d)
			{
				return false;
			}
			else if (used[i] == 0)
			{
				Q.push(i);
				used[i] = d;
			}

		}
	}
	return true;
}
