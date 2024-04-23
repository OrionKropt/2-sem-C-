// 1069. Код Прюфера

#include <iostream>
#include <vector>

#include <set>
using namespace std;

int main()
{
	vector<int> code;
	int temp;
//for (int i = 0; i < 5; ++i)
//	{
//		cin >> temp;
//		code.push_back(temp);
//	}
	
	while (cin >> temp)
	{
		code.push_back(temp);
	}
	int size = code.size() + 2; 
	vector<int> degree(size, 1);
	vector<set<int>> graph(size);
	for (auto a : code)
		++degree[a];
	
	int k = 1;
	while (degree[k] != 1)
		++k;
	int leaf = k;
	for (auto a : code)
	{
		graph[leaf].insert(a);
		graph[a].insert(leaf);
		--degree[a];
		if (degree[a] == 1 && a < k)
			leaf = a;
		else
		{
			++k;
			while (degree[k] != 1)
				++k;
			leaf = k;
		}
		
	}
	for (int i = 1; i < size; ++i)
	{
		cout << i << ": ";
		for (auto a : graph[i])
			cout << a << ' ';
		cout << endl;
	}

	return 0;
}