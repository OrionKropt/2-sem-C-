////// 2. ������� ������� �� �������������� �������
////	// �������������� ������ - ���� ������ ������ �� ��������� � ������, ����� ��� ����.
#include <iostream>
#include "ringArray.h"
#include "RingArrayQueue.h"
using namespace std;
//
int main()
{
	//RingArray<int> Arr(10);
	//for (int i = 0; i < 15; i++)
	//{
	//	Arr[i] = i;
	//	cout << i << " ";
	//}

	//cout << endl;
	//for (int i = 0; i < Arr.GetSize(); i++)
	//{
	//	cout << Arr[i] << " ";
	//}
	//cout << endl;



	RingArrayQueue<int> queue(3);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	cout << queue.pop() << " " << queue.pop() << " " << queue.pop() << endl;

	return 0;
}