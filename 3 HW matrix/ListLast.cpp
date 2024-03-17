//ListL.cpp
//������� ��� ListLast
#include <fstream>
#include <iostream>
#include "Node.h"
using namespace std;


//  ��� ���, �� ������� ������ �������, � ��� ����� ������� ������ ���������
/// 
/// 1. �� ������ �������, ������ �� �� �����. ����� ������� ��������� � �������������
/// ������� ������� n+1 �� n+1 ��� ���������. ��������� ������.  � ������� ������� ���������
/// ����� �� ����� ������� ���������, ������ ������� ���... ������ ���������� ����� � ����� �� 2.
/// ������� ������� n �� m � ��������� (������ ����� ���������������� ���� � �� ������� ������� ��� ���� � �������� �������)

int** MatrixIns(int** arrS, int size, int& outSize);  
int** MatrixSm(NodeList* firstL, int size);
void PrintLists(NodeList* head);




int main()
{
	int i, m, n;
	Node *first, *current, *last;  // ����� ������
	first = current = last = nullptr;

	NodeList *firstL, *currentL, *lastL; // ����� ������ ������� 
	firstL = currentL = lastL = nullptr;

	ifstream inputf("f1.dat");
	n = 0;

	while (!inputf.eof() )
	{  
		n++;
	//������ ������ ������� ������ first
		first = nullptr;
	do{
       inputf>>m;
	   if (m != 0) {
		   if (first == NULL) {first = InitNode(m); current = first;}
		   else { last = InitNode(m); current -> next = last; current = last;}
	   }
	}while (m!=0);
	//���������� ������ ������� ������ � ������ �������
	if (firstL == NULL) {firstL = InitNodeL(first, n); currentL = firstL;}
	else { lastL = InitNodeL(first, n); currentL -> nextList = lastL; currentL = lastL;}  

	}



	// my code
	// ������� ����������
	int widthIns = 0; // ���������� �����
	int** arrS = MatrixSm(firstL, n+1); // n - ��������� ������, +1 ����� ������ � 1


	int** arrIns = MatrixIns(arrS, n + 1, widthIns);
	cout << "Lists:\n";
	PrintLists(firstL);
	cout << endl;
	cout << "MatrixS\n";
	for (int i = 0; i < n+1; i++)
	{
		for (int j = 0; j < n+1; j++)
			cout << arrS[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	cout << "MatrixIns\n";
	
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < widthIns; j++)
			cout << arrIns[i][j] << " ";
		cout << endl;
	}



	return 0;
}

int** MatrixSm(NodeList* firstL, int size)
{
	int** arrS = new int* [size];
	for (int i = 0; i < size; i++) arrS[i] = new int[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			arrS[i][j] = 0;
	int i = 1;
	

	while (firstL!= nullptr)
	{
		Node* cur = firstL->next;
		while (cur != nullptr)
		{
			arrS[i][cur->s] = 1;
			cur = cur->next;
		}
		firstL = firstL->nextList;
		i++;
	}
	return arrS;
}

int** MatrixIns(int** arrS, int size, int& outSize)
{
	int count = 0;
	//int Max = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (arrS[j][i] == 1) count++;
	}
	count /= 2;
	
	int** arrIns = new int* [size];
	for (int i = 0; i < size; i++) arrIns[i] = new int[count + 1];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < count + 1; j++) arrIns[i][j] = 0;
	outSize = count + 1;
	count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (arrS[j][i] == 1)
			{
				arrIns[i][count] = 1;
				arrIns[j][count++] = 1;
			}
		}
	}

	return arrIns;
}

void PrintLists(NodeList* head)
{
	while (head != nullptr)
	{
		Node* cur = head->next;
		while (cur != nullptr)
		{
			cout << cur->s << " ";
			cur = cur->next;
		}
		cout << endl;
		head = head->nextList;
	}
}