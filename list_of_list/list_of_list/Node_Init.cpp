#include <iostream>
#include "Node.h"

Node* Init(int data)
{
	Node* ptr = new Node;
	ptr->next = nullptr;
	ptr->prev = nullptr;
	ptr->data = data;
	return ptr;
}