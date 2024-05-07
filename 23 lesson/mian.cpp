/*

������ �������
 
 ����� ������� ������ ������
 ������ ������ ������ � ������ ������

 ��� ������� ������ ������� ����� ����� � ��������� ���� ����� � ����� �� ��� �������� �����

 ���� ������ ��� ���� � ������ �� �� �� ������� ����� �����


 1. ����� ������� ����� ������ � ����� ����� ���������� �������
 
 2. ������ �������� - �������� EMAX ����

 3. �������� ���������� ������ ������
  map, Node
  ���� ��������� 

  ������� ���� �� ����� 


*/


/*

���� ���� � ������ �����

����� ������� �����

��� bfs



*/



#include <iostream>
#include <queue>
using namespace std;


struct Edge
{
	Edge() : a(0), b(0) {}
	Edge(int a_, int b_) : a(a_), b(b_) {}
	int a;
	int b;
};

Edge* graph;

int bfs(int v, int size, int& ver)
{
	int d = 0;
	bool* used = new bool[size] {0};
	used[v] = 1;
	queue<int> q;
	q.emplace(v);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (int i = 0; i < size; ++i)
		{
			if (graph[i].a == temp && !used[temp])
			{
				used[temp] = true;
				used[graph[i].b] = true;
				q.push(graph[i].b);
			}
		}
	}
}


int main()
{
	int M;
	cin >> M;

	graph = new Edge[M];

	for (int i = 0; i < M; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		graph[i] = Edge(a, b);
	}




	return 0;
}
