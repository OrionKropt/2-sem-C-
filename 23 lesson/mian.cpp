/*

Дерево предков
 
 Слево направо строим доолга
 Справа налево быстро и дерево сжатое

 Для каждого имвола создаем новую ветку и добавляем этот сивол в конец во все остльные ветки

 Если символ уже есть в дереве то мы не создаем новую ветку


 1. Класс студент класс группа и класс умных указателей Юркевич
 
 2. Дерево отрезков - алгоритм EMAX Маша

 3. седелать суффкисное дерево Никита
  map, Node
  ищем подстроку 

  Укконин Урфу на ютубе 


*/


/*

Есть граф в масиве ребер

Найти диаметр графа

два bfs



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
