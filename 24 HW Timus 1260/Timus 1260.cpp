#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[56]{ 0 };
	
	arr[1] = 1;

	arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i <= n; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 3] + 1;
	}
	
	cout << arr[n];
	return 0;
}