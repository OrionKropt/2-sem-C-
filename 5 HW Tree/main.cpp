//
// 1. Тимус 1111 (класс точка, класс отрезок в нем две точки, класс line в ней А, B, C, уравнение прямой, клас square)
// 2. Написат класс матрица NxN на одномерном масиве
// методы взять эллемент по индексам, положить эллемент по индексам
// Напечать матрицу
// Перегрузка оператора + и cout << и cin >>
// добавить оператор писваивания и конструктор копирования
// Деструктор
// 
// 3. Есть файл и внем несколько пар слов (на English и перевод) как словарь
// Пишеи бинарное дерево поиска по английскому слову
// Написать метода писка (вводим англ и выводим русское)
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