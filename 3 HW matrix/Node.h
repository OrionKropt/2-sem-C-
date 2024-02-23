//Node.H

#ifndef Node_H
#define Node_H

// Это обычный list
// s = данные которые читают с файла
typedef struct tagNode{ 
	int s;
	tagNode *next;
} Node;

//
// Это list_of_list 
// s - номер узла (вершины графа), начиная с 1
// next - это голова обычного листа, этот лист ханит номер вершин с которыми связана текущая вершина
// nextList - следущий узел
//

typedef struct tagNodeList{
	int s; // номер вершины
	tagNodeList *nextList; // Следющий список списков
	Node *next; // сам список
} NodeList;

typedef Node *NodePointer;
typedef NodeList *NodeListPointer;

NodePointer InitNode( int );
NodeListPointer InitNodeL( NodePointer , int);
void IncludeNode( NodePointer , NodePointer );
void DeleteNode(int , NodePointer );
void PrintNodeList( NodePointer );

#endif