//
// 1. Тимус 1111 (класс точка, класс отрезок в нем две точки, класс line в ней А, B, C, уравнение прямой, клас square)
// 2. Написат класс матрица NxN на одномерном масиве
// методы взять эллемент по индексам, положить эллемент по индексам
// Напечать матрицу
// Перегрузка оператора + и cout << и cin >>
// добавить оператор писваивания и конструктор копирования
// Деструктор
// 
// 3. Есть файл и внем несколько пар слов (на English и перевод) как словарь   ^-^
// Пишеи бинарное дерево поиска по английскому слову
// Написать метода писка (вводим англ и выводим русское)
//



#include <iostream>
#include <vector>
#include <fstream>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	ifstream fin("a.txt");
	vector<Matrix> vec;
	int n = 0;
	fin >> n;
	int col = 0, row = 0;
	fin >> col >> row;
	Matrix matrix1(col, row), matrix2(col, row);
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			int a; 
			fin >> a;
			matrix1.Set_ellement(i, j, a);
		}
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
		{
			int a;
			fin >> a;
			matrix2.Set_ellement(i, j, a);
		}
	cout << "matrix1\n";
	matrix1.View();
	cout << "matrix2\n";
	matrix2.View();

	matrix1 = matrix2 + matrix1;
	cout << "matrix1 + matrix2\n";
	matrix1.View();
	
	//for (int i = 0; i < n; i++)
	//{
	//	int size;
	//	fin >> size;
	//	Matrix matrix(size);
	//	for (int j = 1; j <= size; j++)
	//		for (int k = 1; k <= size; k++)
	//		{
	//			int a;
	//			fin >> a;
	//			matrix.Set_ellement(j, k, a);
	//		}
	//	vec.push_back(matrix);
	//}
	//vec[0].View();

	/*cin >> matrix1;
	matrix1.View();
	cout << matrix1;*/

	return 0;
}