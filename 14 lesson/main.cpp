

// 
// next lab
// 
// Timus 1069 
// 
// Код Прюфера по дереву
// 
// ищем лист с наименьшим номером (лист это карйняя вершина, у которой нет детей), записываем родителя
// и убираем лист и повторяем
// 

//
// Подсказка 
// Код прюфера в гугле
//

//
// Timus 1106
// 
// Задча на двудольный граф либо BFS либо DFS определяем
// 
// 
// 
// ДЗ Пингвин Ария расскзать задчачу Урусов йоу
// 
// Конструкцию pair и set Шипицин шшшшшш
// 
// Топологическая сортрровка на ореитировнном графе Маша
//


#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>

using namespace std;

//
//   DFS
//

	// dfs() немного не правильный
	//stack<int> st;
	//st.push(node);
	//
	//while (!st.empty())
	//{
	//	Node cur = st.top();
	//	if (!vised[cur])
	//	{
	//		vised[cur] = true;
	//		for (int i = 0; i < num_nodes; ++i)
	//		{
	//			if (adj_matrix[cur][i] && !vised[i]) st.push(i); // не так нада делать dfs
	//		}else st.pop()
	//	}
	//}


class Graph
{
public:
	Graph()
	{
		cin >> tops;
		gr = new vector<int>[tops + 1];
		for (int i = 0; i < tops; ++i)
		{
			int a = 0;
			cin >> a;
			while (a != 0)
			{
				gr[i].push_back(a);
				cin >> a;
			}
		}
	}

	list<int> DFS()
	{
		stack<int> st;
		list<int> List;
		vector<int> used(tops + 1, 0);
		st.push(1);
		used[1] = 1;
		while (!st.empty()) {
			int t = st.top();
			bool flag = false;
			for (int it : gr[t]) {
				if (!used[it]) {
					st.push(it);
					used[it] = (used[t] % 2) + 1;
					flag = true;
					break;
				}
				else if (used[it] == used[t]) {
					List.push_front(-1);
					return List;
				}
			} if (!flag) {
				st.pop();
			}
			for (int i = 1; i <= tops; i++) {
				if (used[i] == 1) {
					List.push_back(i);
				}
			}
			return List;
		}
	}
	void print(list<int>& List)
	{
		cout << List.size();
		for (int a : List) cout << a << ' ';
	}

private:
	int tops;
	vector<int>* gr;
};

int main()
{
	// Timus 1106

	Graph graph;
	list<int> List = graph.DFS();
	if (List.front() == -1) cout << 0;
	else graph.print(List);
	return 0;
}
