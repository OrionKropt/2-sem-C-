#include <iostream>
#include <string>
#include <vector> 
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

class Graph
{
public:
	Graph()
	{
		cin >> size;
		isen = -1;
		string str;
		for (int i = 0; i < size; ++i)
		{
			groups.push_back(vector<string>());
			for (int j = 0; j < 3; ++j)
			{
				cin >> str;
				groups[i].push_back(str);   // Сохраняем группы
				names.insert(str);          // Добавляем все возможыне имена и set сортирует их
			}
		}
		int k = -1;
		for (auto a : names)
		{
			index.insert({ a, ++k });		// даем индекс каждому имени 
			if (a == "Isenbaev") isen = k;  // Запоминаем index Исенбаева
		}
		graph = new vector<int>[k+1]();     // Создаем масси векторов
		dis = new int[k+1] {0};             // k+1 так как считаем с 1
		used = new bool[k+1] {0};
		for (int i = 0; i < size; ++i)
		{
			for (auto& a : groups[i])      // Для каждого члена группы отмечаем в графе что они связаны
			{                              // в а и b харнятся имена
				for (auto& b : groups[i])
					// Условие которе исключает путь в самого себя
					// Превращаем имя в идекс и добавляем связь
					if (a != b) graph[index[a]].push_back(index[b]);
			}
		}
	}

	void bfs()                  //O(n+m)
	{
		if (isen == -1) return; // Если Исенбаева нету Test 3
		queue<int> q;
		q.push(isen);
		dis[isen] = 0;
		used[isen] = true;
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			for (auto a : graph[temp])  // Бежим по граффу 
			{
				if (!used[a])
				{
					q.push(a);
					used[a] = true;
					dis[a] = dis[temp] + 1;
				}
			}
		}
	}

	void print()
	{
		for (auto a : names)
		{
			cout << a << ' ';
			if (a == "Isenbaev") cout << 0;
			else if (dis[index[a]] == 0) cout << "undefined";
			else cout << dis[index[a]];
			cout << endl;
		}
	}
private:
	vector<int>* graph;
	int* dis;
	bool* used;
	unordered_map<string, int> index; // key - имя из names, value - индекс в векторе graph и массииве dis и used
	vector<vector<string>> groups;    // Группы то есть тройки имен которые получаем на входе
	set<string> names;                // Все возможные имена
	int size;
	int isen;
};

int main()
{
	Graph gr;
	gr.bfs();
	gr.print();
	return 0;
}