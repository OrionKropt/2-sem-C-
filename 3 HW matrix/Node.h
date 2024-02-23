//Node.H

#ifndef Node_H
#define Node_H

// ��� ������� list
// s = ������ ������� ������ � �����
typedef struct tagNode{ 
	int s;
	tagNode *next;
} Node;

//
// ��� list_of_list 
// s - ����� ���� (������� �����), ������� � 1
// next - ��� ������ �������� �����, ���� ���� ����� ����� ������ � �������� ������� ������� �������
// nextList - �������� ����
//

typedef struct tagNodeList{
	int s; // ����� �������
	tagNodeList *nextList; // �������� ������ �������
	Node *next; // ��� ������
} NodeList;

typedef Node *NodePointer;
typedef NodeList *NodeListPointer;

NodePointer InitNode( int );
NodeListPointer InitNodeL( NodePointer , int);
void IncludeNode( NodePointer , NodePointer );
void DeleteNode(int , NodePointer );
void PrintNodeList( NodePointer );

#endif