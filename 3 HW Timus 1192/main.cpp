//
//
//
//
/////
///// ДЗ
///// 
///// Дан код, он создает список списков, и еще могут скинуть лекцию последнюю
///// 
///// 1. По списку списков, читаем их из файла. деать матрицу смежности и инцидентности
///// Создаем матрицу n+1 на n+1 для нумерации. Заполнили нулями.  и создаем матрицу смежности
///// Потом на входе матрица смежности, строим матрицу инц... Счиаем колчинсвто ребер и делим на 2.
///// Создаем матрицу n на m и заполняем (сверху номер рассмтариваемого узла а по строкам смотрим все узлы с которыми связаны) ГОТОВО
/////
///// 2. Создать класс дробь(fraction) должен быть числитель и знаменатель, перегрузить операторы + - * / и cin >> cout << ГОТОВО
///// 
///// 3. 1992 Тимус 
///// есть класс с двумя односвязаным спискам
///// один помнит программы обучения а второй что то ам
///// есть метод который клонирует дронов
///// 
/////    
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//struct Node
//{
//	Node* next;
//	Node* prev;
//	int data;
//};
//
//Node* Init(int data);
//
//
//void push_back(Node* head, int data); // add end
//
//void push_front(Node*& head, int data); // add begin
//void View(Node* head); // print
//int pop_back(Node* head); // del end
//int pop_front(Node*& head); // del begin
//
////int erase(Node* head, int num); // del element of "num"
//
//void clear(Node*& head); // del all elements
//
//// create new list of "size" elements 
////void assign(Node*& head, const int& size, const int& data);
//
//bool IsEmpty(Node* head);
//
//
//class Clone
//{
//public:
//	int num;
//	Clone(int num)
//	{
//		this->num = num;
//		prog = nullptr;
//		history = nullptr;
//	}
//	
//	Clone(const Clone& other)
//	{
//		Node* cur = other.prog;
//		if (cur == nullptr) this->prog = nullptr;
//		else
//		{
//			this->prog = Init(cur->data);
//			cur = cur->next;
//			while (cur != nullptr)
//			{
//				push_back(this->prog, cur->data);
//				cur = cur->next;
//			}
//		}
//		cur = other.history;
//		if (cur == nullptr) this->history = nullptr;
//		else 
//		{
//			this->history = Init(cur->data);
//			cur = cur->next;
//			while (cur != nullptr)
//			{
//				push_back(this->history, cur->data);
//				cur = cur->next;
//			}
//		}
//		this->num = other.num;
//	}
//	void Learn(int n)
//	{
//		if (prog != nullptr) push_front(prog, n);
//
//		else prog = Init(n);
//
//		clear(history);
//	}
//	void Roll_back()
//	{
//		if (history != nullptr) push_front(history, pop_front(prog));
//		else history = Init(pop_front(prog));
//	}
//	void Relearn()
//	{
//		if (prog != nullptr) push_front(prog, pop_front(history));
//		else prog = Init(pop_front(history));
//	}
//	void Check()
//	{
//		if (prog == nullptr) cout << "basic\n";
//		else cout << prog->data << endl;
//	}
//private:
//	Node* prog;
//	Node* history;
//	
//};
//
////bool IsExist(vector<Clone>& vec, const int& find)
////{
////	int size = vec.size();
////	if (size == 0 || find > size+1) return 0;
////}
//
//int main()
//{
//	vector<Clone> vec;
//	int n = 0, m = 0;
//	int num = 0, p = 0;
//	
//	cin >> n >> m;
//
//	string str;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> str;
//		if (str == "learn")
//		{
//			cin >> num >> p;
//			
//			if (vec.size() != 0)
//			{
//				vec[num-1].Learn(p);
//			}
//			else
//			{
//				vec.push_back(Clone(num));
//				vec[num-1].Learn(p);
//			}
//		}
//		else if (str == "rollback")
//		{
//			cin >> num;
//			vec[num-1].Roll_back();
//		}
//		else if (str == "relearn")
//		{
//			cin >> num;
//			vec[num-1].Relearn();
//		}
//		else if (str == "clone")
//		{
//			cin >> num;
//			vec.push_back(vec[num - 1]);
//			vec[vec.size() - 1].num = vec.size() + 1;
//			//Clone temp = vec[num - 1];
//			//temp.num = vec.size() + 1;
//			//vec.push_back(temp);
//		}
//		else if (str == "check")
//		{
//			cin >> num;
//			vec[num - 1].Check();
//		}
//		if (!str.empty()) str.clear();
//		
//	}
//}
//
//
//Node* Init(int data)
//{
//	Node* ptr = new Node;
//	ptr->next = nullptr;
//	ptr->prev = nullptr;
//	ptr->data = data;
//	return ptr;
//}
//
//void push_back(Node* head, int data) // add end
//{
//
//	if (head == nullptr) head = Init(data);
//	else
//	{
//		while (head->next != nullptr) head = head->next;
//		head->next = Init(data);
//		head->next->prev = head;
//	}
//}
//
//void push_front(Node*& head, int data) // add begin
//{
//	Node* ptr = Init(data);
//	ptr->next = head;
//	head->prev = ptr;
//	head = ptr;
//	//head->prev = nullptr;
//	//head->data = data;
//}
//void View(Node* head) // print
//{
//	if (head == nullptr) throw exception("Error Wiew: list is empty!");
//
//	while (head != nullptr)
//	{
//		cout << head->data << " ";
//		head = head->next;
//	}
//	cout << endl;
//}
//int pop_back(Node*& head) // del end
//{
//	int data;
//	if (head->next == nullptr)
//	{
//		data = head->data;
//		delete head;
//		head = nullptr;
//		return data;
//	}
//	Node* cur = head;
//	while (cur->next != nullptr)
//	{
//		cur = cur->next;
//	}
//	data = cur->data;
//	cur->prev->next = nullptr;
//	delete cur;
//	return data;
//}
//int pop_front(Node*& head) // del begin
//{
//	int data;
//	if (head->next != nullptr)
//	{
//		data = head->data;
//		Node* ptr = head;
//		head = head->next;
//		head->prev = nullptr;
//		delete ptr;
//		return data;
//	}
//	else
//	{
//		data = head->data;
//		delete head;
//		head = nullptr;
//		return data;
//	}
//	
//
//
//}
////int erase(Node* head, int num); // del element of "num"
//
//
//void clear(Node*& head) // del all elements
//{
//	//if (head != nullptr)
//	//{
//		while (head != nullptr)
//		{
//			pop_front(head);
//		}
//		//delete head;
//		//head = nullptr;
//	//}
//	
//}
//
//// create new list of "size" elements 
////void assign(Node**& head, const int& size, const int& data);
//
//bool IsEmpty(Node* head)
//{
//	return head == nullptr;
//}