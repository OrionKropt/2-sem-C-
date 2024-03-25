#include <iostream>
#include <stack>
#include <queue>


using namespace std;


// Timus каналы

class Graph
{
public:
	Graph()
	{
		cin >> size;
		cin >> begin;
		G = new bool* [size + 1];
		for (int i = 0; i < size + 1; ++i)
		{
			G[i] = new bool[size + 1] {0};
			for (int j = 1; j < size + 1; ++j)
				if (i) cin >> G[i][j];
		}
		/*cout << endl;
		for (int i = 0; i < size + 1; ++i)
		{
			for (int j = 0; j < size + 1; ++j)
			{
				cout << G[i][j] << ' ';
			}
			cout << endl;
		}*/
		W.push(begin);
	}
	void Way()
	{
		while (!W.empty())
		{
			int v = W.top();
			bool Flag = true;
			for (int i = 1; i < size + 1; ++i)
				if (!G[v][i] && v != i)
				{
					W.push(i);
					G[v][i] = 1;
					Flag = false;
					break;
				}
			if (Flag)
			{
				R.push(W.top());
				W.pop();
			}
		}
	}

	void PrintPath()
	{

		int u = R.top();
		while (!R.empty())
		{
			R.pop();
			if (!R.empty())
			{
				cout << u << ' ';
				u = R.top();
				cout << u << endl;
			}
		}
	}

private:
	bool** G;
	int size;   // кол вершин
	int begin;  // точка отсчета
	stack<int> W;
	stack<int> R;
};


int main()
{
	Graph graph;
	graph.Way();
	graph.PrintPath();

	stack<int> st;


	return 0;
}