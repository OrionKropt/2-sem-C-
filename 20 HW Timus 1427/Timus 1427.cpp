#include <iostream>

#include <string>
using namespace std;



int N = 0, M = 0;
string str;


int main()
{

	


	cin >> N >> M;  // N < M
	cin.get();
	getline(cin, str);

	int size = str.length();

	//cout << str;

	int* arr = new int[size] {0};

	bool flag = true;
	if (!isalpha(str[0]))
		flag = false;

	int count = 0;
	int N_M = M;
	arr[0] = 1;

	for (int i = 1; i < size; ++i)
	{

		if (!isalpha(str[i]) && str[i] != ' ')
		{
			flag = false;
		}

		arr[i] = arr[i - 1] + 1;
		N_M = (flag) ? M : N;
		if (arr[i] > N_M)
		{
			if (isalpha(str[i]) || str[i] == ' ')
			{
				flag = true;
			}

			++count;
			arr[i] = 1;
		}

	}


	++count;
	cout << count;
	delete[] arr;
	
	return 0;
}