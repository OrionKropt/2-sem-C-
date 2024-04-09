// 3. Тимус 1982 
// DSU  план электрофикации

#include <iostream>

using namespace std;

struct rib
{
	rib(const int& I, const int& J, const int& Weight) : i(I), j(J), weight(Weight) {}
	rib() : i(0), j(0), weight(0) {}
	int i;
	int j;
	int weight;
};


int n = 0, k = 0, ans = 0;
int* el_city;
int** prices;
rib* ribs;

int* p;
int* h;

int find(const int& v)
{
	return (p[v] == v) ? p[v] : find(p[v]);
}

void unit(int a,  int b, bool is_el)
{
	int r_a = find(a), r_b = find(b);
	if (!is_el && r_a != r_b) ans += prices[a][b];
	if (h[r_a] > h[r_b])
		swap(r_a, r_b);
	h[r_b] = max(h[r_b], h[r_a] + 1);
	p[r_a] = r_b;

	
}	

void selection_sort(const int& size);

int main()
{
	cin >> n >> k;
	el_city = new int[k+1];
	prices = new int*[n+1];
	ribs = new rib[(n*n - n)/2];
	for (int i = 0; i <= n; ++i)
		prices[i] = new int[n+1];
	for (int i = 1; i <= k; ++i)
		cin >> el_city[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> prices[i][j];
	int t = 0;
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j < n + 1; ++j)
			ribs[t++] = rib(i, j, prices[i][j]);

	selection_sort((n*n - n)/2);

	p = new int[n+1];
	h = new int[n+1];
	memset(h, 1, sizeof(int) * (n+1));
	for (int i = 0; i <= n; ++i)
		p[i] = i;

	for (int i = 1; i < k; ++i)
		unit(el_city[i], el_city[i + 1], true);
	int size = (n * n - n) / 2;
	for (int i = 0; i < size; ++i)
		unit(ribs[i].i, ribs[i].j, false);
	cout << ans;




	delete[] p;
	delete[] h;
	delete[] el_city;
	delete[] ribs;
	for (int i = 0; i < n; ++i)
		delete[] prices[i];
	delete[] prices;
	return 0;
}

void selection_sort(const int& size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int Min = i;
		for (int j = i + 1; j < size; ++j)
			if (ribs[j].weight < ribs[Min].weight) Min = j;
		swap(ribs[i], ribs[Min]);
	}
}