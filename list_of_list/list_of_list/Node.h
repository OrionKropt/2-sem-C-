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
