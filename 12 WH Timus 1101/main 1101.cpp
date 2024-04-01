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
#include <unordered_map>
#include <map>

#include <string>
using namespace std;

//void replace(string& str, const string& old_str, const string& new_str);
void Replace(string&, map<char, bool>&);
string create_opz(const string&, const map<char, int>&);
bool calculate(const string&);
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
	T top()
	{
		if (head != nullptr) return head->data;
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
	bool is_empty() { return head == nullptr; }
	int get_size() { return size; }

private:
	Node<T>* head;
	int size;
};


struct Point
{
	Point() : x(0), y(0) {}
	int x; 
	int y;
};

int main()
{
	string str;
	int N, K, M;
	//unordered_map<Point, char> invert_regs;
	

	map<char, bool> reg;
	const map<char, int> operations
	{
		{'(', 0},
		{'|', 1},
		{'&', 2},
		{'!', 3}
	};
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
	//Point temp;
	//char ch;

	int** Map = new int* [N * N];
	for (int i = 0; i < N * N; ++i)
		Map[i] = new int[N * N];

	for (int i = 0; i < K; ++i)
	{
		//cin >> temp.x >> temp.y >> ch;
		//invert_regs.emplace(temp, ch);
		cin >> invert_p[i].x >> invert_p[i].y >> reg[i];
	}

	//string bit_operations[]{ "NOT", "!", "AND", "&", "OR", "|", "FALSE", "0", "TRUE", "1" };
	/*for (int i = 0; i < size(bit_operations) - 1; i+=2)
	{
		replace(str, bit_operations[i], bit_operations[i + 1]);
		cout << str << endl;
	}*/
	Replace(str, reg);
	cout << str << endl;
	string opz = create_opz(str, operations);
	cout << opz;
	cout << calculate(opz);

	Point bot;
	/*while (bot.x > -N && bot.y > -N && bot.x < N && bot.y < N)
	{
		
	}
	*/

	




	return 0;
}


bool calculate(const string& opz)
{
	Stack<bool> s;
	int length = opz.length();
	for (int i = 0; i < length; ++i)
	{
		bool a;
		switch (opz[i])
		{
		case'!':
			cout << " !" << s.top() << " = ";
			s.push(!s.pop());
			cout << s.top() << endl;
			break;
		case'|':
			a = s.pop();
			cout << a << " || " << s.top() << " = "; /*<< a || s.top() << ' '*/;
			s.push(a || s.pop());
			cout << s.top() << endl;
			//s.push(s.pop() || s.pop());
			break;
		case'&':
			a = s.pop();
			cout << a << " & " << s.top() << " = " /*<< a || s.top() << ' ' */ ;
			s.push(a && s.pop());
			cout << s.top() << endl;
			//s.push(s.pop() && s.pop());
			break;
		default:
			if (opz[i] == '1') s.push(1);
			else s.push(0);
			//cout << s.top() << ' ';
			break;
		}
	}
	cout << endl;
	return s.pop();
}

string create_opz(const string& str, const map<char, int>& operations)
{
	int length = str.length();
	Stack<char> s;
	string opz = "";
	
	for (int i = 0; i < length; ++i)
	{
		
		bool is_op = false;
		switch (str[i])
		{
		case'1':
			opz += str[i];
			break;
		case'0':
			opz += str[i];
			break;
		case'!':
			is_op = true;
			break;
		case '&':
			is_op = true;
			break;
		case'|':
			is_op = true;
			break;
		case'(':
			s.push(str[i]);
			break;
		case')':
			while (!s.is_empty())
			{
				if (s.top() == '(')
				{
					s.pop();
					break;
				}
				else opz += s.pop();
			}
			break;
		default:
			break;
		}
		if (is_op)
		{
			while (!s.is_empty())
			{
				if (operations.at(s.top()) > operations.at(str[i]))
					opz += s.pop();
				else break;
			}
			s.push(str[i]);
		}
	}
	return opz;
}

void Replace(string& str, map<char, bool>& reg)
{
	string new_str = "";
	int length = str.length();
	int i = 0;
	while (i < length)
	{
		switch (str[i])
		{
		case 'T':
			if (i + 1 < length && str[i + 1] == 'R')
			{
				new_str += '1';
				i += 4;
			}
			else
			{
				new_str += to_string(reg[str[i]]);
				++i;
			}
			break;
		case 'F':
			if (i + 1 < length && str[i + 1] == 'A')
			{
				new_str += '0';
				i += 5;
			}
			else
			{
				new_str += to_string(reg[str[i]]);
				++i;
			}
			break;
		case 'N':
			if (i + 3 < length && str[i + 3] != 'N')
			{
				if (i + 1 < length && str[i + 1] == 'O')
				{
					new_str += '!';
					i += 3;
				}
				else
				{
					new_str += to_string(reg[str[i]]);
					++i;
				}
			}
			break;
		case 'O': 
			if (i + 1 < length && str[i + 1] == 'R')
			{
				new_str += '|';
				i += 2;
			}
			else
			{
				new_str += to_string(reg[str[i]]);
				++i;
			}
			break;
		case 'A':
			if (i + 1 < length && str[i + 1] == 'N')
			{
				new_str += '&';
				i += 3;
			}
			else
			{
				new_str += to_string(reg[str[i]]);
				++i;
			}
			break;
		case ' ':
			++i;
			break;
		case'(':
			new_str += str[i];
			++i;
			break;
		case')':
			new_str += str[i];
			++i;
			break;
		default:
			new_str += to_string(reg[str[i]]);
			++i;
			break;
		}
		
	}
	str = new_str;
}


//void replace(string& str, const string& old_str, const string& new_str)
//{
//
//	int start = 0;
//	int end = 0;
//	do
//	{
//		start = str.find(old_str);
//		end = old_str.length();
//		if (start != -1)
//			str.replace(start, end, new_str);
//	} while (start != -1);
//
//	
//
//
//}