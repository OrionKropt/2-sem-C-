// Timus 1450

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


struct Edge
{
	Edge() : a(0), b(0), cost(0) {}
	Edge(const int& A, const int& B, const double& Cost) :
		a(A), b(B), cost(Cost)
	{}
	int a;
	int b;
	double cost;
};

class Graph
{
public:
	Graph()
	{

		// for   BellmanFord()

		int m, n;
		cin >> n >> m;
		size = m;
		tops_size = n + 1;
		graph = new Edge[m];
	
		
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			graph[i] = Edge(a, b, c * (-1));
		}
		cin >> start >> finish;



		// for BellmanFord_optimaize()
		/*int m, n;
		cin >> n >> m;
		tops_size = n + 1;
		adj_list = new vector<pair<int, double>> [tops_size];
		
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj_list[a].push_back(make_pair(b, c * (-1)));
		}
		cin >> start >> finish;*/

	}




	void BellmanFord()
	{
		const int INF = 1e9;
		int* costs = new int[tops_size];


		for (int i = 1; i < tops_size; ++i)
			costs[i] = INF;
		costs[start] = 0;

		for (int k = 0; k < tops_size - 1; ++k)
		{
			bool updated = false;
			for (int i = 0; i < size; ++i)
			{
				int a = graph[i].a;
				int b = graph[i].b;
				int cost = graph[i].cost;
				if (costs[a] != INF && costs[b] > costs[a] + cost)
				{
					costs[b] = costs[a] + cost;
					updated = true;
				}
			}
			if (!updated) break;
		}
		if (costs[finish] == INF)
			cout << "No solution";
		else cout << costs[finish] * (-1);
	}

	void BellmanFord_optimaize() // Actually it's slowly -(
	{
		const int INF = 1e9;
		int* costs = new int [tops_size];
		queue<int> q;
		bool* in_queue = new bool[tops_size] {0};

		for (int i = 1; i < tops_size; ++i)
			costs[i] = INF;
	
		costs[start] = 0;
		q.push(start);
		in_queue[start] = true;

		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			in_queue[v] = false;
			for (auto& [to, cost] : adj_list[v])
			{
				if (costs[to] > costs[v] + cost)
				{
					costs[to] = costs[v] + cost;
					if (!in_queue[to])
					{
						q.push(to);
						in_queue[to] = true;
					}
				}
			}
		}
		if (costs[finish] == INF)
			cout << "No solution";
		else cout << costs[finish] * (-1);
	}
private:
	int size;
	int tops_size;
	Edge* graph;
	vector<pair<int, double>>* adj_list;
	int start;
	int finish;
};

int main()
{
	Graph gr;
	gr.BellmanFord();
	//gr.BellmanFord_optimaize();
	return 0;
}