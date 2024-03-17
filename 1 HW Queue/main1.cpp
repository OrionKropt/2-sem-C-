// main.cpp
//
//#include <iostream>
//
//using namespace std;
//
//
// ��� �������  (������ �� n �����, �����) ��������� 
// ����� ����� ��� ������� �������� m ����� ��� ���� ����� �� ���� ���������� * �� ��� ����� ����� ������� ����� ����������
// ����� MIN � MAX ������
// ����� ������� ������ � �����
//
// Solution 
// ����� Stack
// ����� Stack � ���������� � �������� (�� ����� Min � Max, �� O(1))
// �������� ������� �� ���� ������
// ��������� ������� � Node � �������� 
// 
// ��� ������ ������� �� ���� ������
// Stack 1, Stack 2
// push ������ � 1 Stack
// pop ���� ������ ���� �� ����� �� Stack2.pop, ����� Stack2.push(Stack1.pop)
// 
// �� 
// 1. ������� �� ��� �����
// 
// 2. ������� ������� �� �������������� �������
// �������������� ������ - ���� ������ ������ �� ��������� � ������, ����� ��� ����.
// 
// 3. ����� "���������" (Stack � �������� ������, ���������� �����
// ������
// struct Tree
// {
//		int info;
//		Tree* left;
//		Tree* right;
// };
// 
// ����� ��������� ��� ������, ����� ����������
// 
// Google: ����� ��������� �����
// 
// 
// 4. ������� ������ ����� "CVS" (���� ������ ����� �� ������) �� ��������� ������ � ������
//


#include "Queue.h"



int main()
{
	Queue* queue = new Queue;
	const int N = 10;
	int arr[N] = { 5, 1, 3, 7, 2, 9, 8, 4, 6, 0 };
	int m;
	int begin=NULL, end=NULL, currenEnd = NULL;
	cin >> m;
	if (m > N) cout << "NULL\n";
	else
	{
		
		int Max=1, Min=INT_MAX, countQ = 0, countAns = 0;
		for (int i = 0; i < N; i++)
		{
			currenEnd = arr[i];
			if (countQ < m) { queue->push(arr[i]); countQ++;  }
			else
			{
				if ((Max * Min) > (queue->GetMax() * queue->GetMaxOfMin()))
				{
					Max = queue->GetMax();
					Min = queue->GetMaxOfMin();
					begin = queue->pop();
					end = currenEnd;
				}
				else
				{
					queue->pop();
				}
				
				queue->push(arr[i]);
				/*if (Max < queue->GetMax() && ) Max = queue->GetMax();
				if (Min < queue->GetMaxOfMin()) Min = queue->GetMaxOfMin();*/
			}
		}
	}
	
	while (!queue->IsEmpty())
	{
		cout << queue->pop() << " ";
	}
	cout << endl;
	cout << "Begin = " << begin << " End = " << end << endl;

	return 0;
}

