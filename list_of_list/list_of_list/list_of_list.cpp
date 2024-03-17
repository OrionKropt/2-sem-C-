#include <iostream>
#include "list_of_list.h"
void add_back(list_of_list*& head_lists, Node*& head)  // add list in end
{
	
	if (head_lists->list == nullptr)
	{
		head_lists->list = head;
		head_lists->list_prev = nullptr;
		head_lists->list_next = nullptr;
	}
	else
	{
		list_of_list* current = head_lists;
		while (current->list_next != nullptr) current = current->list_next;
		current->list_next = new list_of_list;
		current->list_next->list = head;
		current->list_next->list_prev = head_lists;
		current->list_next->list_next = nullptr;
	}
	head = nullptr;
}

void View_lists(list_of_list* head_lists)
{
	int count = 1;
	while (head_lists != nullptr)
	{
		cout << "list " << count++ << endl;
		View(head_lists->list);
		head_lists = head_lists->list_next;
	}
}