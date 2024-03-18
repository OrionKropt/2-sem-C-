#include <iostream>
#include <stack>
#include <queue>


using namespace std;

//
// Timus 1145
// 
// BFS еще DFS 
// Есть граф на матрице смежности
// Очередь
// Массив предков 
// Массив используемый
// Массив попереченых ребер
// 
// Сложность алгоритма поиска в глубину и в ширину (если спсисок спиков то O(n+m) если матрица смежнотис O(n^2)
// 
// Алгоритм применим:
// 1. Пройтись по вершинам
// 2. Наличие циклов в графе
// 3. Компонент связности
// 4. Связанный или нет
// 5. Является ли деревом
// 6. Можно найти растояние в графе с помощью BFS
// 7. Опрелделить является ли двудольный граф
// 8. Поиск кротчайшего пути между двумя вершинами
// 
// Как проверить двудольность графа?
// Если есть поперечное ребро на одной доле то не двудольный
// 
// Задача есть граф и матрица смежности
// Есть BFS которая говорит двудольный граф или нет
//
// 
// Раскзать из stl основыне методы у list, forwardlist stack (разница реализации на списке и на листе) queue это мне 
// 
// Паша - Паутина Ананси расскзать жоска
// 
// Числа Исимбаева 1837
// У каждой фамилии есть иномер строки
// создаем спсиок людец и граф из фамилий смежности 
// делаем bfs от isinbaev
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
	//int adj[r][n]; // матрица смежности
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
