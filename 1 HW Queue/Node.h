#pragma once

using namespace std;

struct Node
{
	int data;
	int Min;
	int Max;
	Node* next;
	Node(int data);
	

};

Node::Node(int data)
{
	Min = data;
	Max = data;
	this->data = data;
	next = nullptr;
}