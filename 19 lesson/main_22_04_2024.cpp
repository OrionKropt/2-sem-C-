//
// НОВАЯ ТЕМА 
// Динамическое програмированние
// 
// Тимус флаги
//
// ДЗ Тимус 1353 милиардная функция Васи Маша
// Дз Книга Динамическое програмировние Окулов Бестов from Киров в самом конце задача о рюкзаке Урусов Никита
// 
// Замечание к среде Российские газопроводы два способа 
// 1. Делаем все ребра отрицательными и Форт Белман 
// 2. Форт Белман что  то с ним ахахах...
// 
// 
// Задачи которые будут на экзе
// 
// 1. В файле матрица инцидентности  получить от сюда массив списков (написаь класс граф)
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

