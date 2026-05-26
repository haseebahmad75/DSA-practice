#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void Enqueue(int x)
{
    // create a node of the passed data
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }

    // if queue not empty
    rear->next = temp;
    rear = temp;
}

void Dequeue()
{
    if(front == NULL)
    {
        cout<<"Queue is empty";
        return;
    }
    if(front ==  rear)
    {
        front = rear = NULL;
    }
    
    Node* temp = front;
    {
        front = temp->next;
    }
    delete temp; // delete is used for nodes created with new
}

int Front()
{
    return front->data;
}

int Rear()
{
    return rear->data;
}

int main()
{
    Enqueue(2);
    Enqueue(4);
    Enqueue(6);
    Dequeue();
    cout<<Front() <<endl;
    cout<<Rear();

}

