// 1. Timus 1033
// Снова лабиринт, есть лабиринт
// граф bfs 



#include <iostream>
#include <queue>
using namespace std;

struct Top
{
	Top(const bool& Data, const int& Id) :
		data(Data), id(Id) {}
	Top() : data(0), id(0) {}
	bool data;
	int id;
};

class Graph
{
public:
	Graph(Top** maze, const int& size, const int& num_tops) : _size(num_tops + 1)
	{
		_adj = new bool* [_size];
		for (int i = 0; i < _size; ++i)
			_adj[i] = new bool[_size] {0};
		_adj_ver = new int[_size] {0};


		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size; ++j)
			{
				if (maze[i][j].data == true)
				{
					if (j + 1 < size && maze[i][j + 1].data == true)
					{
						int I = maze[i][j].id;
						int J = maze[i][j + 1].id;
						_adj[I][J] = true;
						_adj[J][I] = true;
						++_adj_ver[I];
						++_adj_ver[J];
					}
					if (i + 1 < size && maze[i + 1][j].data == true)
					{
						int I = maze[i][j].id;
						int J = maze[i + 1][j].id;
						_adj[I][J] = true;
						_adj[J][I] = true;
						++_adj_ver[I];
						++_adj_ver[J];
					}
				}
			}
	}
	int calculate_square()
	{
		bool* used = new bool[_size] {0};

		
		int ans = 0;
		/*
		*	test
		*  5
		*  ..###
		*  .####
		*  #####
		*  ####.
		*  ###..
		* ans: 108
		*/
		

		for (auto a : { 1, _size - 1 })  // Сначала с начала а потом с конца, см test
		{
			queue<int> q;
			q.push(a);
			used[a] = true;
			ans += 2 - _adj_ver[a];
			while (!q.empty())
			{
				int p = q.front();
				q.pop();
				for (int i = 1; i < _size - 1; ++i)
				{
					if (!used[i] && _adj[p][i])
					{
						used[i] = true;
						q.push(i);
					
						ans += (4 - _adj_ver[i]);
						
					}
				}
			}
		}
		
		//ans -= 2; 
		delete[] used;
		return ans * _magic * _magic;
	}
	void print_adj()
	{
		for (int i = 1; i < _size; ++i)
		{
			for (int j = 1; j < _size; ++j)
				cout << _adj[i][j] << ' ';
			cout << endl;
		}

		cout << "adj_ver\n";

		for (int i = 1; i < _size; ++i)
			cout << i << ' ' <<  _adj_ver[i] << endl;
	}

private:
	bool** _adj;
	int* _adj_ver; // Хранит количество смежных вершин
	int _size;
	int _magic = 3;
};



int main()
{
	Top** maze;
	int N;
	cin >> N;
	maze = new Top* [N];
	for (int i = 0; i < N; ++i)
		maze[i] = new Top[N];
	int tops = 0;
	for (int i  = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			char ch;
			cin >> ch;
			maze[i][j] = (ch == '.') ? Top(true, ++tops) : Top(false, 0);
		}
	Graph graph(maze, N, tops);
	cout << graph.calculate_square();
	return 0;
}