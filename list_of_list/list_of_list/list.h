#pragma once
#include "Node.h"
#include<iostream>





void push_back(Node* head, int data); // add end

void push_front(Node*& head, int data); // add begin
void View(Node* head); // print
int pop_back(Node* head); // del end
int pop_front(Node*& head); // del begin

int erase(Node* head,int num); // del element of "num"

void clear(Node*& head); // del all elements

// create new list of "size" elements 
void assign(Node*& head, const int& size, const int& data);

bool IsEmpty(Node* head);