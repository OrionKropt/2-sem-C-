#pragma once

//#include "Node.h"
#include <iostream>

using namespace std;

struct Node
{
	Node* next;
	int data;
};

Node* Init(int data);
//void DeleteNode(int k, Node* head);
Node* IncludeNode(Node* second, Node* head);
void Viewe(Node* head);


Node* Init(int k)
{
	Node* ptr = new Node;
	ptr->data = k;
	ptr->next = nullptr;
	return ptr;
}


Node* IncludeNode(Node* first, Node* head)
{
	first->next = head;
	return first;
}

void Viewe(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

// check
// 1. if k = 0
// 2. if k in midle
// 3. if k in end
//void DeleteNode(int k, Node* head)
//{
//	int i = 0;
//	while (head != nullptr)
//	{
//
//		if (i == k)
//		{
//
//		}
//		i++;
//	}
//}