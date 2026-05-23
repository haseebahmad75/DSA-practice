#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

struct Node* top = NULL;

void Push(int x)
{
    struct Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp; // updates the top for new node
}

void Pop()
{
    struct Node* temp;
    if(top == NULL) return;
    temp = top;
    top = top->link;
    free(temp);
}

int Top()
{
    if(top == NULL)
    {
        cout<<"Stack is empty!";
    }
    return top->data;
}

bool isEmpty()
{
    if(top == NULL)
    return true;
    else
    return false;
}

int main()
{
    Push(5);
    Push(6);
    Push(7);
    Push(8);
    Pop();
    cout<<"Current top element: " <<Top() ;
    if(isEmpty())
    cout<<"\nStack is empty.";
    else
    cout<<"\nStack is not empty";
}

