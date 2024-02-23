#pragma once

#include <iostream>

#include "list.h"

using namespace std;

struct list_of_list
{
	list_of_list* list_next;
	list_of_list* list_prev;
	Node* list;
	list_of_list() { list = nullptr; list_next = nullptr; list_prev = nullptr; }
};



void add_back(list_of_list*& head_lists, Node*& head);  // add list in end
void add_front(list_of_list*& head_lists, Node* head); // add list in begin

void View_lists(list_of_list* head_lists); // print

Node* del_back(list_of_list* head_lists); // del end
Node* del_front(list_of_list* head_lists); // del begin

Node* erase(list_of_list head_lists, int num); // del element of "num"


//list_of_list clear(list_of_list head); // del all elements



