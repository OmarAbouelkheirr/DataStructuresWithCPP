#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node * next;
};


// هنضيف قبل
void InsertAtBeginning(Node * &head , int value)
{
    Node * new_node = new Node();

    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

void PrintLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }

    cout << endl;
}

Node *Find(Node *Head , int value)
{
    while (Head != NULL)
    {
        if(Head->value == value)
            return Head;
        Head = Head->next;
    }

    return NULL;
}

// هنضيف بعد
void InsertAfter(Node *Head , int prevNodeVal , int ValueOfNewNode)
{
    Node *test = Find(Head , prevNodeVal);

    if(test == NULL)
    {
        cout << "PrevNode is Nulllllllllllllllllll" << endl;
        return;
    }

    Node *NewNode = new Node();

    NewNode->value = ValueOfNewNode;
    NewNode->next = test->next;
    test->next = NewNode;
}

void InsertAtEnd(Node * &Head , int value)
{
    Node *NewNode = new Node();

    NewNode->next = NULL;
    NewNode->value = value;

    if (Head == NULL)
    {
        Head = NewNode;
        return;
    }
    
    Node *LastNode = Head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = NewNode;
}

void DeleteNode(Node * &Head , int val)
{
    Node *Current =  Head , *Prev = Head;

    if (Head == NULL)
    {
        return;
    }

    if (Current->value == val)
    {
        Head = Current->next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->value != val)
    {
        Prev = Current;
        Current = Current->next;
    }


    if (Current == NULL)
        return;

    Prev->next = Current->next;
    delete Current;
}

void DeleteFirstNode(Node * &Head)
{
    // Head = Head->next;

    // طريقه تانيه علشان نحذفها من الذاكره
    Node *Current = Head;

    if (Current == NULL) return;

    Head = Current->next;
    delete Current;
    return;
}

void DeleteLastNode(Node * &Head)
{
    Node *Current = Head , *Prev = NULL;

    if (Head == NULL) return;

    if (Current->next == NULL)
    {
        Head = NULL;
        delete Current;
        return;
    }

    while (Current != NULL && Current->next != NULL)
    {
        Prev = Current;
        Current = Current->next;
    }

    Prev->next = NULL;
    delete Current;
}

int main()
{
    Node* head = NULL;

    // هنضيف قبل
    InsertAtBeginning(head , 5);
    InsertAtBeginning(head , 7);
    InsertAtBeginning(head , 8);
    InsertAtBeginning(head , 6);

    PrintLinkedList(head);

    // هنضيف بعد
    InsertAfter(head, 7, 400);

    PrintLinkedList(head);

    InsertAtEnd(head , 548500);

    PrintLinkedList(head);

    DeleteNode(head , 8);

    PrintLinkedList(head);

    DeleteFirstNode(head);

    PrintLinkedList(head);

    DeleteLastNode(head);

    PrintLinkedList(head);
} 