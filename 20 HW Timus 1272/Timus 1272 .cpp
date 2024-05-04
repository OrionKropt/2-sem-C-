//Timus 1272

#include <iostream>

using namespace std;

int N;
int* p;
int* h;
int ans = 0;
int leader(int v)
{
	return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unit(int a, int b)
{
	a = leader(a), b = leader(b);
	
	if (h[a] > h[b])
		swap(a, b);
	h[b] = max(h[b], h[a] + 1);
	p[a] = b;
}

int main()
{
	int M = 0, K = 0;
	cin >> N >> K >> M;
	++N;
	p = new int[N];
	int first = 0;
	for (int i = 0; i < N; ++i)
		p[i] = i;
	h = new int[N] {0};

	
	for (int i = 0; i < K; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		unit(a, b);
		first = a;
	
	}
	
	for (int i = 0; i < M; ++i)
	{
		int a = 0, b = 0;
		bool flag = false;
		cin >> a >> b;
		if (leader(a) != leader(b))
		{
			++ans;
			unit(a, b);
		}
		
	}
	
	cout << ans;

	return 0;
}