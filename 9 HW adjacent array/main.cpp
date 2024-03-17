// 2. Тимус Гиппер каналы
// 3. Есть класс граф заданные на матрице инцидетности
// В файле есть кол вершин и кол ребер и матрица инцидентности 
// Нужно написать функцию которая переводит эту конструкцию в массив смежности это одномерный массив
// в начале котором адрессная чать а в конце список вершин
// Печать массива смежности 
//
//


#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
public:
	Graph() : i_matrix(nullptr), a_array(nullptr), a_size(0),
	i_col(0), i_row(0) {}
	void read_i_matrix_form_file(const string& file_name);
	void print_i_matrix();
	void print_a_array();
	~Graph()
	{
		for (int i = 0; i < i_col; ++i)
			delete[] i_matrix[i];
		delete[] i_matrix;
		delete[]a_array;
	}
private:
	void create_a_array();
	int count_adjacent_vertexes(const int& num_vertex);
	//int* adjacent_vertexes(const int& num_vertex, int& size);
	int** i_matrix;
	int* a_array;
	int a_size;
	int i_col;
	int i_row;
};


int main()
{
	Graph graph;
	graph.read_i_matrix_form_file("i_martix.txt");
	graph.print_i_matrix();
	graph.print_a_array();
	return 0;
}

void Graph::read_i_matrix_form_file(const string& file_name)
{
	ifstream fin(file_name);
	fin >> i_col >> i_row;
	i_matrix = new int* [i_col];
	for (int i = 0; i < i_col; ++i)
		i_matrix[i] = new int[i_row];

	for (int i = 0; i < i_col; ++i)
	{
		for (int j = 0; j < i_row; ++j)
		{
			fin >> i_matrix[i][j];
			
		}
		a_size += count_adjacent_vertexes(i);
	}
	a_size += i_col;                    // starting values
	++a_size;                           // to count form one instead of zero
	create_a_array();

	fin.close();
}

void Graph::print_i_matrix()
{
	if (i_col == 0) return;

	cout << "Incident matrix\n";
	cout << " | ";
	for (int i = 1; i <= i_row; ++i)
		cout << i << ' ';
	cout  << endl <<  " | ";
	for (int i = 1; i <= i_row*2; ++i)
		cout << "-";
	cout << endl;
	for (int i = 0; i < i_col; ++i)
	{
		cout << i+1 << "| ";
		for (int j = 0; j < i_row; ++j)
			cout << i_matrix[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void Graph::print_a_array()
{
	cout << "Adjacency array\n";

	for (int i = 1; i < a_size; ++i)
		cout << a_array[i] << ' ';
	cout << endl;
}


	
	// 1. fill in adjacent array:
	// 
	// Graph:
	//                                  1-----4
	//                                  |\
	//									| \
	// 	                                |  \
	//									2---3
	// 
	// Incidence matrix:
	// 1 1 1 0
	// 1 0 0 1
	// 0 1 0 1
	// 0 0 1 0
	// 
	// 
	// 
	// 
	// Index: 0 1 2 3  4  5 6 7 8 9 10 11 12
	// Array: 0 5 8 10 12 2 3 4 1 3 1  2  1
	//          | |	|   | ^     ^   ^     ^
	//          | |	|	| |     |   |     |
	//          ----------      |   |     |
	//            | |   |       |   |     |
	//            ---------------   |     |
	//				|   |           |     |
	//              -----------------     |
	//                  |                 |
	//                  -------------------
	// 
	// first index is unused
	// 
	// 
	//

void Graph::create_a_array()
{
	a_array = new int[a_size] {0};


	int cur_idx = i_col + 1;
	int idx = 0;
	for (int i = 0; i < i_col; ++i)
	{
		a_array[i + 1] = cur_idx;
		for (int j = 0; j < i_row; ++j)
		{
			if (i_matrix[i][j])
			{
				for (int k = 0; k < i_col; ++k)
				{
					if (i_matrix[k][j] && k != i)
					{
						a_array[cur_idx++] = k + 1;
					}
				}
			}
		}
	}


}

int Graph::count_adjacent_vertexes(const int& num_vertex)
{
	int out = 0;
	for (int i = 0; i < i_row; ++i)
		out += i_matrix[num_vertex][i];
	return out;
}

