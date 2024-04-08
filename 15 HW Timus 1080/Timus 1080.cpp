// 1. Тимус 1080 
// Граф оренитрованный йоу


#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Graph
{
public:
	Graph()
	{
		cin >> size;
		adj = new bool* [size + 1];
		rights = new int[size + 1];
		memset(rights, -1, sizeof(int) * (size + 1));
		for (int i = 1; i <= size; ++i)
			adj[i] = new bool[size+1] {0};
		for (int i = 1; i <= size; ++i)
		{
			int temp;
			cin >> temp;
			while (temp != 0)
			{
				adj[i][temp] = 1;
				adj[temp][i] = 1;
				cin >> temp;
			}
		}

	}
	bool dfs()
	{
		stack<int> st;
		bool* used = new bool[size + 1] {0};
		
		
		for (int j = 1; j <= size; ++j)
			if (used[j] == 0)
			{
				st.push(j);
				used[j] = 1;
				rights[j] = 0;

				while (!st.empty())
				{
					int temp = st.top();
					bool f = false;
					for (int i = 1; i <= size; ++i)
					{		
						if (adj[temp][i])
						{
							if (rights[i] != rights[temp])
							{
								if (!used[i])
								{
									rights[i] = (rights[temp] + 1) % 2;
									used[i] = 1;
									st.push(i);
									f = true;
									break;
								}
							}
							else return false;
						}
						
					}
					if (!f) st.pop();
				}
			}
		
		return true;
	}

	void print_ans()
	{
	
		for (int i = 1; i <= size; ++i)
		{
			cout << rights[i];
		}
	}
private:
	bool** adj;
	int* rights;
	int size;
};

int main()
{
	Graph graph;
	if (graph.dfs())
	{
		graph.print_ans();
	}
	else cout << "-1";
	return 0;
}




