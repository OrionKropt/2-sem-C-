

#include <iostream>
#include "list_of_list.h"

using namespace std;
int main()
{
    cout << "Hello World!\n";
    Node* head = Init(1);
    push_back(head, 2);
    push_front(head, 0);
    list_of_list* list = new list_of_list;
    add_back(list, head);

   

    cout << "list_of_list ";
    View(list->list);
    try
    {
        clear(list->list);
    }
    catch (const exception ex)
    {
        cout << ex.what() << endl;
    }
   
    cout << "Node: ";
    if (!IsEmpty(head)) View(head);
    else cout << "empty\n";

    cout << "list_of_list ";
    if (!IsEmpty(list->list)) View(list->list);
    else cout << "empty\n";
    return 0;
    Node* head2 = Init(33);
    push_back(head2, 34);
    push_front(head2, 32);
    add_back(list, head2);
    push_back(list->list_next->list, 35);
    cout << "View lists\n";
    View_lists(list);

}

