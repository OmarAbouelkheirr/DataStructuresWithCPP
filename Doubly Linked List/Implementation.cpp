#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node *Prev;
};

int main()
{
    Node* Head;

    Node * Node1 = NULL;
    Node * Node2 = NULL;
    Node * Node3 = NULL;

    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    Node1->Next = Node2;
    Node1->Prev = NULL;

    Node2->Next = Node3;
    Node2->Prev = Node1;

    Node3->Next = NULL;
    Node3->Prev = Node2;


    Head = Node1;

    while (Head != NULL)
    {
        cout << Head->value;
        Head = Head->Next;
    }
}
