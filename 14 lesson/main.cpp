

// 
// next lab
// 
// Timus 1069 
// 
// ��� ������� �� ������
// 
// ���� ���� � ���������� ������� (���� ��� ������� �������, � ������� ��� �����), ���������� ��������
// � ������� ���� � ���������
// 

//
// ��������� 
// ��� ������� � �����
//

//
// Timus 1106
// 
// ����� �� ���������� ���� ���� BFS ���� DFS ����������
// 
// 
// 
// �� ������� ���� ��������� ������� ������ ���
// 
// ����������� pair � set ������� ������
// 
// �������������� ���������� �� ������������� ����� ����
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

	// dfs() ������� �� ����������
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
	//			if (adj_matrix[cur][i] && !vised[i]) st.push(i); // �� ��� ���� ������ dfs
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
