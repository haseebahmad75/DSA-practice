#include<iostream>
using namespace std;

int A[5];
int front = -1;
int rear = -1;

bool IsFull(int A[])
{
    if(rear == 4)
    return true;
    else
    return false;
}

bool IsEmpty()
{
    if(front == -1 && rear == -1)
    return true;
    else
    return false;
}

void Enqueue(int x) // insertion happens at the rear of queue
{
    if(IsFull(A))
    {
        cout<<"Queue is full";
        return;
    }
    else if(IsEmpty())
    {
        front = rear = 0;
        A[rear] = x;
    }
    else
    {
        rear++;
        A[rear] = x; 
    }
}

void Dequeue()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty";
        return;
    }
    else if(front == rear) // single element
    {
        front = rear = -1;
    }
    else // when you Dequeue(), you remove the front element, so the next element becomes the new front.
         // That next element is at the next index, so we do front++
    {
        front++; 
    }
}

int Front()
{
    if(IsEmpty())
    {
        cout<<"Queue is empty";
        return -1;
    }
    return A[front];
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Dequeue(); // pop from the front
    Dequeue();
    cout<<Front();
    
}