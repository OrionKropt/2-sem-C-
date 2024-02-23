//Node.cpp
#include <iostream>
#include "Node.h"
using namespace std;

NodePointer InitNode(int qq)
{NodePointer newNode;
newNode = new Node;
newNode -> s = qq;
newNode -> next = NULL;
return newNode;
}
NodeListPointer InitNodeL( NodePointer qq, int i )
{
	NodeListPointer newNode;
	newNode = new NodeList;
	newNode -> s = i;
	newNode -> next = qq;
	newNode -> nextList = nullptr;
	return newNode;
}
void IncludeNode( NodePointer newNode, NodePointer first )
{
	first->next = newNode;
	first=newNode;
}

void DeleteNode( int k, NodePointer first )
{
	NodePointer previous = nullptr, current = nullptr;
	int i;
	i=0;
	current = first;

while (current != NULL )
{
	i++;
	if ( i == k ){
		if( first == current ) first = current -> next;
		else previous-> next = current -> next;
		delete current;
		break;}
	previous = current;
	current = current -> next;
}
}

void PrintNodeList( NodePointer first)
{
	NodePointer p;
	p = first;
	while(p != NULL)
	{
		cout<< p -> s << endl;
		p = p -> next;
	}
}