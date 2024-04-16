//
// Дз 
// 1. С примерами наследование в классах, расмотеррть вопрос про создание наследников, спецификаторы доступа Эрик
// 2. LCA алгоритм как работает йоу мне, как найти наименьшего общего предка
// 3. Наивынй алгоритм Маша
// На входе текст этот текст скалдывается в дерево
// В дереве есть  map
// В улзле дерева хранитсся номер узла, и map на следующие узлы
// есть массив таких узлов
// Источник: Юрий Лившиц самый первый алгоритм в pdf 
// https://docs.yandex.ru/docs/view?tm=1713172913&tld=ru&lang=ru&name=01ianote.pdf&text=%D0%BD%D0%B0%D0%B8%D0%B2%D0%BD%D1%8B%D0%B9%20%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC%20%D0%BF%D0%BE%D1%81%D1%82%D1%80%D0%BE%D0%B5%D0%BD%D0%B8%D1%8F%20%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%B0&url=https%3A%2F%2Flogic.pdmi.ras.ru%2F~yura%2Finternet%2F01ianote.pdf&lr=20720&mime=pdf&l10n=ru&sign=0b59e6965c0b104b50fb413fad0cb0cf&keyno=0&serpParams=tm%3D1713172913%26tld%3Dru%26lang%3Dru%26name%3D01ianote.pdf%26text%3D%25D0%25BD%25D0%25B0%25D0%25B8%25D0%25B2%25D0%25BD%25D1%258B%25D0%25B9%2B%25D0%25B0%25D0%25BB%25D0%25B3%25D0%25BE%25D1%2580%25D0%25B8%25D1%2582%25D0%25BC%2B%25D0%25BF%25D0%25BE%25D1%2581%25D1%2582%25D1%2580%25D0%25BE%25D0%25B5%25D0%25BD%25D0%25B8%25D1%258F%2B%25D0%25B4%25D0%25B5%25D1%2580%25D0%25B5%25D0%25B2%25D0%25B0%26url%3Dhttps%253A%2F%2Flogic.pdmi.ras.ru%2F~yura%2Finternet%2F01ianote.pdf%26lr%3D20720%26mime%3Dpdf%26l10n%3Dru%26sign%3D0b59e6965c0b104b50fb413fad0cb0cf%26keyno%3D0
// 
// Источник: алгоритм Укконина за линию строит дерево с линейной памятью (Сложно)
// 
//



#include<iostream>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <vector>
using namespace std;

// Хорошая задача на map 
// Структура папок 




// алгоритм Дейкстры

class Graph
{

};

// Решение задачи Российские газопроводы
list<int> DeiPath(int start, int end)
{
	set<int> unvisited;
	// total - кол вершин в графе
	for (int i = 0; i < total; ++i) unvisited.insert(i);
	int* distances = new int[total] {-1};
	distance[start] = 0;
	int current = start;
	while (current != -1)
	{
		list<int> unvisitedNeighbors;
		for (auto i : getNeghbors(current))
		{
			if (unvisited.find(i) == unvisited.end()) continue;
			// edges из класса Graph
			distances[i] = distances[i] == -1 ? edges[current][i] : min(distances[i], edges[current][i]);
		}
		unvisited.erase(current);
		--current;
		for (auto i : unvisited)
		{
			if (distances[i] == -1) continue;
			if (current == -1 || distances[i] < distances[current]) current = i;
		}
	}

	set<int> visited;
	for (int i = 0; i < total; ++i)
	{
		if (unvisited.find(i) == unvisited.end())
			visited.insert(i);
	}
	return // list который еще нада создать 
		// можно было создать массив предков и по нему пределить путь
}

//
// Топологическая сортировка для графов без циклов
//  Есть две реализации 1. Через DFS O(N+M) 2. через Кана O(N^2)
//  Суть в том что мы любая стрелк ана графе после сортирвки идет из меньшего номера в бльший
// 
//

// we have a graph

class Graph
{
public:
	Graph()
	{
		int N;
		cin >> N;
		graph = vector(vector<int>(), N);
		for (int i = 0; i < N; ++i)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}
	}


	void DFS(vector<vector<int>>& graph, int node, vector<bool>& used, stack<int>& res)
	{
		used[node] = true; // node это такая вершина в которую нието не приходит
		for (int neighbor : graph[node])
		{
			if (!used[neighbor])
				DFS(graph, neighbor, used, res);
		}
		res.push(node);

	}

	// DFS вызывается из класса graph
	void DFS(const int& node)
	{
		DFS(graph, node, used, res);
	}

	vector<int> Topolojical_sort()
	{
		Topolojical_sort(graph);
	}
	

private:
	vector<vector<int>> graph;

	void DFS(vector<vector<int>>& graph, int node, vector<bool>& used, stack<int>& res)
	{
		used[node] = true; // node это такая вершина в которую нието не приходит
		for (int neighbor : graph[node])
		{
			if (!used[neighbor])
				DFS(graph, neighbor, used, res);
		}
		res.push(node);

	}

	vector<int> Topolojical_sort(vector<vector<int>>& graph)
	{
		int n = graph.size();
		vector<bool> used(n, false);
		stack<int> res;
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
				DFS(graph, i, used, res);
		}
		vector<int> Sorted_nodes;
		while (!res.empty())
		{
			Sorted_nodes.push_back(res.top());
			res.pop();
		}
		return Sorted_nodes;
	}

};

// Этот тоже в классе


int main()
{
	map<int, int> m;
	m.insert({ 1, 1 });
	m.insert({ 1, 2 });
	for (auto& a : m)
		cout << a.second << endl;


	return 0;
}