#include <iostream>

#include "list.h"

void push_back(Node* head, int data) // add end
{

	if (head == nullptr) head = Init(data);
	else
	{
		Node* current = head;
		while (current->next != nullptr) current = current->next;
		current->next = Init(data);
		current->next->prev = current;
	}
}

void push_front(Node*& head, int data) // add begin
{
	Node* ptr = new Node;
	ptr->next = head;
	head->prev = ptr;
	head = ptr;
	head->prev = nullptr;
	head->data = data;
}
void View(Node* head) // print
{
	if (head == nullptr) throw exception("Error Wiew: list is empty!");
	
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int pop_back(Node* head) // del end
{
	int data;
	while (head->next != nullptr)
	{
		head = head->next;
	}
	data = head->data;
	head->prev->next = nullptr;
	delete head;
	return data;
}
int pop_front(Node*& head) // del begin
{
	int data;
	if (head->next != nullptr)
	{
		data = head->data;
		Node* ptr = head;
		head = head->next;
		head->prev= nullptr;
		delete ptr;
		return data;
	}
	else throw exception("Error pop_back:list is already empty!");

		
}
int erase(Node* head, int num); // del element of "num"


void clear(Node*& head) // del all elements
{
	while (head->next != nullptr)
	{
		pop_front(head);
	}
	delete head;
	head = nullptr;
}

// create new list of "size" elements 
void assign(Node**& head, const int& size, const int& data);

bool IsEmpty(Node* head)
{
	return head == nullptr;
}