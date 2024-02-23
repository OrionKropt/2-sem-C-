#pragma once

#include <iostream>

using namespace std;



struct Node
{
	Node* next;
	Node* prev;
	int data;
}; 

Node* Init(int data);
//void DeleteNode(int k, Node* head);
Node* IncludeNode(Node* second, Node* head);
void Viewe(Node* head);
