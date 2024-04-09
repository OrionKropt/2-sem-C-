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
				groups[i].push_back(str);
				names.insert(str);
			}
		}
		int k = -1;
		for (auto a : names)
		{
			index.insert({ a, ++k });
			if (a == "Isenbaev") isen = k;
		}
		graph = new vector<int>[k+1]();
		dis = new int[k+1] {0};
		used = new bool[k+1] {0};
		for (int i = 0; i < size; ++i)
		{
			for (auto& a : groups[i])
			{
				for (auto& b : groups[i])
					if (a != b) graph[index[a]].push_back(index[b]);
			}
		}
	}

	void bfs()
	{
		if (isen == -1) return;
		queue<int> q;
		q.push(isen);
		dis[isen] = 0;
		used[isen] = true;
		while (!q.empty())
		{
			int temp = q.front();
			q.pop();
			for (auto a : graph[temp])
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
	unordered_map<string, int> index;
	vector<vector<string>> groups;
	set<string> names;
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