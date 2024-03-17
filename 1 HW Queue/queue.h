#pragma once

#include "Stack.h"

class Queue
{
public:
	Queue() { st1 = new Stack; st2 = new Stack; }
	void push(int data);
	int pop();
	int GetMin();
	int GetMax();
	int GetMaxOfMin();
	bool IsEmpty();
private:
	Stack* st1;
	Stack* st2;
};

void Queue::push(int data)
{
	st1->push(data);
}

int Queue::pop()
{
	if (st2->IsEmpty()) while (!st1->IsEmpty()) st2->push(st1->pop());
	return st2->pop();
}

int Queue::GetMin()
{
	if (st2->IsEmpty()) return st1->GetMin();
	else return (st1->GetMin() < st2->GetMin()) ? st1->GetMin() : st2->GetMin();
}

int Queue::GetMax()
{
	if (st2->IsEmpty()) return st1->GetMax();
	else return (st1->GetMax() > st2->GetMax()) ? st1->GetMax() : st2->GetMax();
}

int Queue::GetMaxOfMin()
{
	if (st2->IsEmpty())return st1->GetMin();
	else return (st1->GetMin() > st2->GetMin()) ? st1->GetMin() : st2->GetMin();
}

bool Queue::IsEmpty()
{
	return st1->IsEmpty() && st2->IsEmpty();
}