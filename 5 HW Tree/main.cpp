//
// 1. ����� 1111 (����� �����, ����� ������� � ��� ��� �����, ����� line � ��� �, B, C, ��������� ������, ���� square)
// 2. ������� ����� ������� NxN �� ���������� ������
// ������ ����� �������� �� ��������, �������� �������� �� ��������
// �������� �������
// ���������� ��������� + � cout << � cin >>
// �������� �������� ����������� � ����������� �����������
// ����������
// 
// 3. ���� ���� � ���� ��������� ��� ���� (�� English � �������) ��� �������
// ����� �������� ������ ������ �� ����������� �����
// �������� ������ ����� (������ ���� � ������� �������)
//



#include <iostream>
#include <fstream>
#include "Tree.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	ifstream fin("src.txt");
	Tree tree;
	int size = 0;
	fin >> size;
	for (int i = 0; i < size; i++)
	{
		Node* pNode = new Node();
		fin >> pNode->En >> pNode->Ru;
		tree.Add(pNode);
	}


	
		


	tree.View();

	cout << tree.Find("tree");
	return 0;
}