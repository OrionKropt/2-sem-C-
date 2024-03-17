#include <iostream>
#include"PriorityQueue.h"
#include <stack>
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
		
		W.push(begin);
	}
	void Way()
	{
		while (!W.empty())
		{
			int v = W.top();
			bool Flag = true;
			for (int i = 1; i < size + 1; ++i)
				if (!G[v][i])
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
			cout << u << ' ';
			R.pop();
			u = R.top();
			cout << u << endl;
		}
	}

private:
	bool** G;
	int size;    // кол вершин
	int begin;  // точка отсчета
	stack<int> W;
	stack<int> R;
};



int main()
{              
	                      //                                    _____
						  //                                  _/     \_       \
	PriorityQueue Pqueue; // Не работает она плак плак плак -/  ^ & ^  \_/--/- - >
	//Pqueue.enqueue(2, 10);                                 \ ------- /\__/-\/
	//Pqueue.enqueue(1, 11);
	//Pqueue.enqueue(3, 12);
	//Pqueue.enqueue(4, 100);
	// 4 3 1 2
	  

	// Timus Паутина Ананси решат с пмощью пересекающихся множеств
	// Решение есть множество щаписали его
	
	// стек сильно поможет
	
	// Timus каналы
	Graph graph;
	graph.Way();
	graph.PrintPath();

	return 0;
}