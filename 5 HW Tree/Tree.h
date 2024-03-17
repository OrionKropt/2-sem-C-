#pragma once
#include <string>
#include <iostream>
struct Node
{
	Node(std::string En, std::string Ru)
	{
		next = nullptr;
		this->En = En;
		this->Ru = Ru;
	}
	Node() {}
	Node(const Node& other)
	{
		this->next = other.next;
		this->En = other.En;
		this->Ru = other.Ru;
	}
	Node* next;
	std::string En;
	std::string Ru;
};

class Tree
{
public:
	Tree(Node* node)
	{
		right = nullptr;
		left = nullptr;
		Dic = node;
	}
	Tree(const Node& node)
	{
		right = nullptr;
		left = nullptr;
		Dic = new Node(node);
	}
	Tree() 
	{
		Dic = nullptr;
		right = left = nullptr;
	}
	
	void Add(Node* node);
	void View();
	std::string Find(std::string En);
private:
	Node* Dic;
	Tree* right;
	Tree* left;
	
};