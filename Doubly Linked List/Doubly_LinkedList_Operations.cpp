#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *Next;
    Node *Prev;
};

// هنضيف قبل
void InsertAtBeginning(Node * &head , int value)
{
    Node * new_node = new Node();

    new_node->value = value;
    new_node->Next = head;
    new_node->Prev = NULL;

    if (head != NULL)
    {
        head->Prev = new_node;
    }

    head = new_node;
}

Node *Find(Node *Head , int value)
{
    while (Head != NULL)
    {
        if(Head->value == value)
            return Head;
        Head = Head->Next;
    }

    return NULL;
}

void InsertAfter(Node *Head , int prevNodeVal , int ValueOfNewNode)
{
    Node *test = Find(Head , prevNodeVal);

    if(test == NULL)
    {
        cout << "\nNode not found.." << endl;
        return;
    }

    Node *NewNode = new Node();

    NewNode->value = ValueOfNewNode;
    NewNode->Next = test->Next;
    NewNode->Prev = test->Prev;
    test->Next = NewNode;
}

void InsertAtEnd(Node * &Head , int value)
{
    Node *New_node = new Node();
    New_node->value = value;
    New_node->Next = NULL;

    if (Head == NULL)
    {
        New_node->Prev = NULL;
        Head = New_node;
        return;
    }

    Node *LastNode = Head;
    while (LastNode->Next != NULL)
    {
        LastNode = LastNode->Next;
    }

    LastNode->Next = New_node;
    New_node->Prev = LastNode;

}

void DeleteNode(Node * &Head , Node * &NodeToDelete)
{
    if (Head == NULL || NodeToDelete == NULL)
    {
        return;
    }

    if (Head == NodeToDelete)
    {
        Head = NodeToDelete->Next;
    }

    if (NodeToDelete->Next != NULL)
    {
        NodeToDelete->Next->Prev = NodeToDelete->Prev;
    }
    
    delete NodeToDelete;
}

void DeleteFirstNode(Node * &Head)
{
    Node *Current = Head;

    if (Current == NULL) return;

    Head = Current->Next;
    if (Head != NULL)
    {
        Head->Prev = NULL;
    }
    
    delete Current;
    return;
}

void DeleteLastNode(Node * &head) 
{
    if (head == NULL) {
        return;
    }

    if (head->Next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* current = head;
    while (current->Next->Next != NULL) {
        current = current->Next;
    }

    Node* temp = current->Next;
    current->Next = NULL;
    delete temp;
}

void PrintNodeDetails(Node* head)
{
    if (head->Prev != NULL)
        cout << head->Prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->Next != NULL)
        cout << head->Next->value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* head)
{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->Next;
    }
}

void PrintList(Node* head)
{
    cout << "\nNULL <--> ";
    while (head != NULL) {
        cout << head->value << " <--> ";
        head = head->Next;
    }
    cout << "NULL";
}

int main()
{
    Node* head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    PrintList(head);
    InsertAfter(head , 2 , 55);
    InsertAfter(head , 3 , 55);
    PrintList(head);

    InsertAtEnd(head, 66);

    PrintList(head);

    DeleteFirstNode(head);

    PrintList(head);
    DeleteLastNode(head);
    PrintList(head);
}