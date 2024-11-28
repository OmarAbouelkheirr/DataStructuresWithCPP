#include <iostream>
#define maxSize 5

using namespace std;

int queue[maxSize];
int front = -1;
int rear = -1;

bool isFull()
{
    if(rear == maxSize-1)
        return 1; 
    else
        return 0;
}

bool isEmpty()
{
    if(front == -1 && rear == -1)
        return 1; 
    else
        return 0;
}

void enQueue(int val)
{
    if (!isFull())
    {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = val;
        cout << "[+] Enqueue -> " << val << endl;
    }
    else {
        cout << "Queue is full!!!" << endl;
    }
}

void deQueue()
{
    if ((!isEmpty()) && front <= rear)
    {
        int val;
        val = queue[front];
        front++;
        cout << "[-] Dequeue -> " << val << endl;
    }
    else 
    {
        cout << "Queue is empty!!!" << endl;
    }
}

int peek()
{
    if((!isEmpty()) && front <= rear)
        return queue[front];
    else 
        cout << "Queue is empty!!!" << endl;
        return 0;
}

void desplay()
{
    if((!isEmpty()) && front <= rear)
    {
        // cout << endl << endl;
        // for (int i = front; i <= rear; i++)
        // {
        //     cout << "[ " << i+1 << " ]";
        // }
        // cout << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << "[ " << queue[i] << " ]";
            // cout << queue[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Can't display! queue is empty" << endl;
}


int main()
{
    enQueue(10);
    enQueue(6);
    enQueue(5);
    enQueue(9);

    desplay();

    deQueue();

    desplay();
}
