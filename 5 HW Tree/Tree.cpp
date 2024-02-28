#include "Tree.h"

void Tree::Add(Node* node)
{
	if (this->Dic == nullptr)
	{
		this->Dic = node;
		return;
	}
	if (this->Dic->En < node->En)
	{
		if (this->right != nullptr) this->right->Add(node);
		else this->right = new Tree(node);
	}
	else
	{
		if (this->left != nullptr) this->left->Add(node);
		else this->left = new Tree(node);
	}
}

void Tree::View()
{
	if (this->right != nullptr) this->right->View();
	std::cout << Dic->En << " - " << Dic->Ru << std::endl;
	if (this->left != nullptr) this->left->View();
	
}
std::string Tree::Find(std::string En)
{
	if (Dic == nullptr) return "-1";
	if (this->Dic->En == En) return this->Dic->Ru;
	if (this->Dic->En < En)
	{
		if (this->right != nullptr) return this->right->Find(En);
		if (this->left != nullptr) return this->left->Find(En);
	}
	else
	{
		return "-1";
	}
	
}

