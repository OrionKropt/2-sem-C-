// main.cpp
//
//#include <iostream>
//
//using namespace std;
//
//
// Дан отрезок  (массив из n чисел, целых) рандомный 
// Нужно найти под отрезок размером m такой что макс число на этом подотрезке * на мин число этого отрезка будет минимально
// найти MIN и MAX посути
// НАйти индексы начала и конца
//
// Solution 
// Пишем Stack
// Пишем Stack с поддкржкой с минимума (Мы знаем Min и Max, за O(1))
// Напсиать очередь на двух стеках
// Структура очередь с Node и методами 
// 
// Как пистаь очередь на двух стеках
// Stack 1, Stack 2
// push всегда в 1 Stack
// pop Если второй стек не пусой то Stack2.pop, иначе Stack2.push(Stack1.pop)
// 
// ДЗ 
// 1. Сделать то что верху
// 
// 2. Создать очередь на закальцованном массиве
// закольцованный массив - Если массив полный то добавляем в начало, меняя что есть.
// 
// 3. Тимус "парламент" (Stack и бинарное дерево, ркурсивный заход
// начало
// struct Tree
// {
//		int info;
//		Tree* left;
//		Tree* right;
// };
// 
// Нужно прочитать это дерево, можно рекурсивно
// 
// Google: Обход бинарного древа
// 
// 
// 4. Хорошая задача Тимус "CVS" (Мжно делать можно не делать) на связанные спсики и классы
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

