#include <iostream>
#include <stack>
using namespace std;





int *p, *h;
int n, m, k;
bool* del;

stack<int> s;
stack<int> del_str;
int leader(int v)
{
	return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unit(int a, int b)
{
	a = leader(a);
	b = leader(b);
	if (a == b) return;
	--k;

	if (h[a] < h[b]) p[a] = b;
	else
	{
		p[b] = a;
		if (h[a] == h[b]) ++h[a];
	}
}




int main()
{
	int N, M, Q;
	cin >> N >> M;
	k = N;
	++N;
	++M;
	p = new int [N];
	h = new int [N];
	del = new bool[M] {0};
	
	int** str = new int* [M];
	for (int i = 0; i < M; ++i)
		str[i] = new int[2];

	for (int i = 0; i < N; ++i)
	{
		p[i] = i;
		h[i] = 1;
	}
	for (int i = 1; i < M; ++i)
	{
		cin >> str[i][0] >> str[i][1];
	}
	cin >> Q;
	int* ans = new int [Q];
	int d = 0;
	for (int i = 0; i < Q; ++i)
	{
		int temp = 1;
		cin >> temp;
		del_str.push(str[temp][1]);
		del_str.push(str[temp][0]);
		del[temp] = 1;	
	}


	for (int i = 1; i < M; ++i)
	{
		if (del[i] == 0)
			unit(str[i][0], str[i][1]);
	}
	s.push(k);
	while(!del_str.empty())
	{
		int a = del_str.top();
		del_str.pop();
		int b = del_str.top();
		del_str.pop();
		unit(a, b);
		s.push(k);
	}
	s.pop();
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}



	


	


	return 0;
}