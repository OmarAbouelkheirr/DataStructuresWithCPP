#include <iostream>
using namespace std;

int isEmpty(int top)
{
    return top == -1;
}

int isFull(int top)
{
    return top == 4;
}

void push(int val, int &top, int arr[])
{
    if (isFull(top))
    {
        cout << "Can't push, arr is full." << endl;
    }
    else
    {
        top++;
        arr[top] = val;

        cout << "Done add " << arr[top] << endl;
    }
}

void pop(int &top, int arr[]) 
{
    if (isEmpty(top))
    {
        cout << "Can't pop, Stack is empty!" << endl;
    }
    else
    {
        cout << "Done remove " << arr[top] << endl;
        arr[top] = 0;
        top--;
    }
}

void peek(int arr[], int top)
{
    if(isEmpty(top))
        cout << "Can't get top element , Stack is empty." << endl;
    else
        cout << "Top element is : " << arr[top] << endl;
}

void display(int arr[] , int lenth)
{
    if(isEmpty(lenth))
    {
        cout << "Can't display , Stack is empty!" << endl;
    }
    else
    {
        cout << "Stack elements : \n";
        for (int i = lenth; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
}

void count(int top)
{
    if(isEmpty(top))
        cout << "Stack is empty we have 0 element!" << endl;
    else
        cout << "We have " << top + 1 << " element in stack" << endl;
}

int main()
{
    int top = -1;
    int arr[5] = {0};
    // int arr[5];

    push(1 , top , arr);
    push(2 , top , arr);
    push(3 , top , arr);

    display(arr , top);

    pop(top , arr);
    pop(top , arr);

    display(arr , top);
    
    pop(top , arr);
    pop(top , arr);

    display(arr , top);

}