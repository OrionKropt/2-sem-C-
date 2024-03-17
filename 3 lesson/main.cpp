#include <iostream>
#include <fstream>
using namespace std;



// Пирамида на Тимусе, очередь с приоретами


// 1987  и это ваще на СРЕДУ
// Задача на струкутры данных
// Отрезок
// Список отрезков (общее кол отрезков, уазтель на струкутру отрезка)
// функция сортировка по длине
// если отезки одинковой длины то смотрим их границы
// Считываем точку и выводим номер самого маленького отрезка которому она принадлежит


// ДЗ
// 1. Построение обратной польской записи (ОПЗ) для задачи 1101 РОбот в поле
// 2. Рассказать про очередь с приоритетом болемение подробно
// 3. Сортировка списка (одно/двух) как хош Эрик
// 
// 
//

class Sigment
{
	Sigment(int size)
	{
		arr = new int[size];
		this->size = size;
	}
	void SetData(int num, int data)
	{
		arr[num] = data;
	}
private:
	int size;
	int* arr;
};


struct Node
{
	
	Node(int key)
	{
		left = nullptr;
		right = nullptr;
		this->key = key;
	}




	int key;
	Node* left;
	Node* right;
};


void Enter(int k, Node* head)
{
	if (head == nullptr) head = new Node(k);
	else
	{
		Enter(k, head->left);
		Enter(k, head->right);
	}


}

// Написать рекурсивный обход
class Tree
{
public:
	Node* root;
	Tree(string str)
	{
		ifstream fin(str);
		int n;
		while (fin >> n)
			Enter(n, root);
	}
	Tree(Node* node)
	{
		root = node;
	}

	void Add(Node* head)
	{
		if (head->key >= root->key)
		{
			if (root->right != nullptr) Add(head);
			else root->right = head;
				
			
		}
		else
		{
			if (root->left != nullptr) Add(head);
			else root->left = head;
		}
	}


};

void Trevers(Node* root)
{
	Trevers(root->right);
	cout << root->key << " ";
	Trevers(root->left);
}




int main()
{
	//int a = 1241;
	//// Это Сишка йоу
	//scanf_s("%d",&a);
	//printf("HEX\n");
	//printf("0x");
	//printf("%d", a);
	//printf("C");
	Node* head = new Node(10);
	Tree root(head);
	Node* node1 = new Node(9);
	root.Add(node1);
	Trevers(root.root);
	return 0;
}