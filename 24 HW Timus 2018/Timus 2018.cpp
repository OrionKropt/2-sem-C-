#include <iostream>

using namespace std;

int main()
{
	int n, a, b;
	int mod = (int) 1e9 + 7;
	cin >> n >> a >> b;

	int** arr = new int*[n + 1];
	for (int i = 0; i <= n; ++i)
		arr[i] = new int[2] {0};





	arr[0][0] = arr[0][1] = 1;
	for(int i = 0; i < n; ++i) 
	{
		for (int j = 1; j <= a && i + j <= n; ++j)
			arr[i + j][0] = (arr[i + j][0] + arr[i][1]) % mod;
		for (int j = 1; j <= b && i + j <= n; ++j)
			arr[i + j][1] = (arr[i + j][1] + arr[i][0]) % mod;
	}
	cout << (arr[n][0] + arr[n][1]) % mod << endl;


	return 0;
}