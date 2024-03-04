#include <iostream>

#include <vector>

using namespace std;


struct Node
{
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
	Node* next;
	int data;
};


class List
{
public:
	List(int data)
	{
		head = new Node(data);
	}
	
	List(const List& other)
	{
		if (other.head == nullptr) this->head = nullptr;
		else
		{
			Node* cur = other.head;
			this->head = new Node(cur->data);
			cur = cur->next;
			while (cur != nullptr)
			{
				push_back(cur->data);
				cur = cur->next;
			}
		}
	}

	int GetData()
	{
		return head->data;
	}

	void push_front(int data)
	{
		Node* ptr = new Node(data);
		ptr->next = head;
		head = ptr;
	}

	int pop_front()
	{
		if (head != nullptr)
		{
			int data = this->head->data;
			Node* temp = head->next;
			delete head;
			head = temp;
			return data;
		}
	}

	void push_back(int data)
	{
		Node* cur = this->head;
		while (cur->next != nullptr)
			cur = cur->next;
		cur->next = new Node(data);
	}

	void clear()
	{
		while (head != nullptr)
			pop_front();
	}

	bool IsEmpty()
	{
		return head == nullptr;
	}

private:
	Node* head;
};

class Clone
{

public:
	Clone(int num)
	{
		this->num = num;
		prog = nullptr;
		history = nullptr;
	}

	Clone(const Clone& other)
	{
		if (other.prog == nullptr) this->prog = nullptr;
		else
		{
			//this->prog = new List(*other.prog);
			this->prog = other.prog;
		}
		if (other.history == nullptr) this->history = nullptr;
		else
		{
			//this->history = new List(*other.history);
			this->history = other.history;
		}
		this->num = other.num;
		
	}

	void Learn(int data)
	{
		if (prog == nullptr) prog = new List(data);
		else prog->push_front(data);

		if (history != nullptr) history->clear();
	}
	
	void Roll_back()
	{
		if (history == nullptr) history = new List(prog->pop_front());
		else history->push_front(prog->pop_front());
	}

	void Relearn()
	{
		if (prog == nullptr) prog = new List(history->pop_front());
		else prog->push_front(history->pop_front());
	}

	void Check()
	{
		if (prog->IsEmpty()) cout << "basic\n";
		else cout << prog->GetData() << endl;
	}

	void SetNum(int num)
	{
		this->num = num;
	}

private:
	int num;
	List* prog;
	List* history;
};

int main()
{
	vector<Clone> vec{ Clone(0) };
	int n = 0, m = 0;
	int num = 0, p = 0;

	cin >> n >> m;

	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "learn")
		{
			cin >> num >> p;

			if (vec.size() != 1)
			{
				vec[num].Learn(p);
			}
			else
			{
				vec.push_back(Clone(num));
				vec[num].Learn(p);
			}
		}
		else if (str == "rollback")
		{
			cin >> num;
			vec[num].Roll_back();
		}
		else if (str == "relearn")
		{
			cin >> num;
			vec[num].Relearn();
		}
		else if (str == "clone")
		{
			cin >> num;
			vec.push_back(Clone(vec[num]));
			vec[vec.size() - 1].SetNum(vec.size()-1);
		}
		else if (str == "check")
		{
			cin >> num;
			vec[num].Check();
		}
		if (!str.empty()) str.clear();

	}
}