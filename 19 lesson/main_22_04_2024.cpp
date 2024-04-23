//
// ����� ���� 
// ������������ ����������������
// 
// ����� �����
//
// �� ����� 1353 ���������� ������� ���� ����
// �� ����� ������������ �������������� ������ ������ from ����� � ����� ����� ������ � ������� ������ ������
// 
// ��������� � ����� ���������� ����������� ��� ������� 
// 1. ������ ��� ����� �������������� � ���� ������ 
// 2. ���� ������ ���  �� � ��� ������...
// 
// 
// ������ ������� ����� �� ����
// 
// 1. � ����� ������� �������������  �������� �� ���� ������ ������� (������� ����� ����)
//  
// 
#include <iostream>
#include <list>
#include <fstream>

using namespace std;

class Graph
{
	Graph()
	{
		ifstream fin("input.txt");
		fin >> n >> m;
		inc = new bool*[n];
		
		for (int i = 0; i < n; ++i)
			inc[i] = new bool[m];
		gr = new list<int>[n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				fin >> inc[i][j];

		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (inc[i][j])
					gr[j].push_back(i);
		
			}
		}
	}


	

private:
	bool** inc;
	int n;
	int m;
	list<int>* gr;
};

