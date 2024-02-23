#include <iostream>
#include "Tree.h"
using namespace std;
// 3. Тимус "парламент" (Stack и бинарное дерево, ркурсивный заход
// начало
// struct Tree
// {
//		int info;
//		Tree* left;
//		Tree* right;
// };
int main()
{
	Tree tree;
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k = 0;
	
	tree.Init(arr[n - 1]);

	for (int i = n - 2; i > -1; i--) tree.add(arr[i]);


	cout << endl;
	

	tree.PrintTreePostOrderReverse();


	return 0;
}