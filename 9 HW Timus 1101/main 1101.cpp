//
// 1. Есть строка string и в ней скобочки { [ ( < > ) ] }
// Проверить правильност скобок
// 
// Эту задачу замнили на Тимус 1101 
// 1 часть
// Есть строка логическая и замням одним символом все символы в строке
// заводим массив 
// 
// 
// 


#include <iostream>
#include <map>
#include <string>
using namespace std;

void replace(string& str, const string& old_str, const string& new_str);


template<typename T>
struct Node
{
	Node() {}
	Node(T Data) : data(Data), next(nullptr) {}
	T data;
	Node* next;
};

template<typename T>
class Stack
{
public:
	Stack() : head(nullptr), size(0) {}
	Stack(T data)
	{
		size = 1;
		head = new Node<T>(data);
	}

	void push(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			head->next = nullptr;
			++size;
		}
		else
		{
			Node<T>* p_node = new Node<T>(data);
			p_node->next = head;
			head = p_node;
			++size;
		}
	}

	T pop()
	{
		if (head != nullptr)
		{
			T temp = head->data;
			Node<T>* p_node = head->next;
			delete head;
			head = p_node;
			--size;
			return temp;
		}
	}

	int get_size() { return size; }

private:
	Node<T>* head;
	int size;
};


struct Point
{
	int x; 
	int y;
};

int main()
{
	string str;
	int N, K, M;
	/*map<char, bool> reg;
	char letter = 'A';
	for (char i = 'A'; i < 'Z'; ++i)
		reg[i] = 0;
	N = K = M = 0;
	bool* arr = new bool[M];
	getline(cin, str);
	cin >> N >> M >> K;
	Point* forks= new Point[M];
	for (int i = 0; i < M; ++i)
		cin >> forks[i].x >> forks[i].y;
	Point* invert_p = new Point[K];
	for (int i = 0; i < K; ++i)
		cin >> invert_p[i].x >> invert_p[i].y >> reg[i];

	string bit_operations[]{ "NOT", "!", "AND", "&", "OR", "|", "FALSE", "0", "TRUE", "1" };
	for (int i = 0; i < size(bit_operations) - 1; i+=2)
	{
		replace(str, bit_operations[i], bit_operations[i + 1]);
		cout << str << endl;
	}*/
	Stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.pop();
	stack.pop();
	
	//cout << str;



	return 0;
}


void replace(string& str, const string& old_str, const string& new_str)
{

	int start = 0;
	int end = 0;
	do
	{
		start = str.find(old_str);
		end = old_str.length();
		if (start != -1)
			str.replace(start, end, new_str);
	} while (start != -1);

	


}