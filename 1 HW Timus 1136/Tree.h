#pragma once
#include <iostream>

class Tree
{
public:
	void Init(int data) { this->data = data; left = nullptr; right = nullptr; size++; }
	
	void add(int data);
	void PrintTree();
	void PrintTreeReverse();
	//int* GetTree_to_Array(int& OutSize);
	int GetData() { return data;}
	void PrintLeftTree();
	void PrintLeftTreeReverse();
	void PrintRightTree();
	void PrintRightTreeReverse();
	void PrintTreePostOrderReverse();
	
private:
	Tree* left;
	Tree* right;
	int data;
	int size = 0;
	
};


void Tree::add(int data)
{
	if (this->data >= data)
	{
		if (left != nullptr) left->add(data);
		
		else
		{
			left = new Tree;
			left->Init(data);
		}
	}
	else
	{
		if (right != nullptr) right->add(data);

		else
		{
			right = new Tree;
			right->Init(data);
		}
	}
}

void Tree::PrintTree() // Преордер
{
	if (left != nullptr) left->PrintTree();
	std::cout << data << std::endl;
	if (right != nullptr) right->PrintTree();
}

void Tree::PrintTreeReverse() // Постордер
{
	if (right != nullptr) right->PrintTreeReverse();
	std::cout << data << std::endl;
	if (left != nullptr) left->PrintTreeReverse();
}

void Tree::PrintLeftTree()
{
	left->PrintTree();
}
void Tree::PrintLeftTreeReverse()
{
	left->PrintTreeReverse();
}
void Tree::PrintRightTree()
{
	right->PrintTree();
}

void Tree::PrintRightTreeReverse()
{
	right->PrintTreeReverse();
}

void Tree::PrintTreePostOrderReverse()
{
	if (this)
	{
		right->PrintTreePostOrderReverse();
		left->PrintTreePostOrderReverse();
		std::cout << data << std::endl;
	}
}