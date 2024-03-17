// Stack.h 

#pragma once
#include "Node.h"
using namespace std;


class Stack
{
public:

	Stack() { head = nullptr; }
	Stack(Node* first) { head = first; }
	Stack(int data) { head = new Node(data); }

	void push(int data);
	int pop();
	bool IsEmpty() { return head == nullptr; }
	int Min() { return head->Min; }
	int Top() { return head->data; }
	void View();
	
	int GetMin() { return head->Min; }
	int GetMax() { return head->Max; }



private:
	Node* head;
};

void Stack::push(int data)
{
	if (nullptr == head)
	{
		head = new Node(data);
	}
	else
	{
		Node* ptr = new Node(data);
		ptr->next = head;
		ptr->Min = (data < head->Min) ? data : head->Min;
		ptr->Min = (data > head->Max) ? data : head->Max;
		head = ptr;
		
	}

}

int Stack::pop()
{
	int out = head->data;
	Node* ptr = head->next;
	delete head;
	head = ptr;
	return out;
}

void Stack::View()
{
	Node* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}

