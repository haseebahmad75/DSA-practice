#include<iostream>
using namespace std;

const int n=5;
int A[n];
int front = -1;
int rear = -1;

bool IsEmpty()
{
    if(front == -1 && rear == -1)
    return true;
    else
    return false;
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

void Enqueue(int x) // insertion happens at the rear of queue
{
    if((rear+1)%n == front) // check whether the queue is full circularly
    {
        cout<<"Queue is full \n";
        return;
    }
    else if(IsEmpty())
    {
        front = rear = 0;
        A[rear] = x;
    }
    else
    {
        rear = (rear+1) % n;
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
        front = (front+1) % n;
    }
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Dequeue(); // pop from the front
    Dequeue();
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);
    cout<<Front();
    
}