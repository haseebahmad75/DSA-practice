// Stack - Array-based implementation
#include<iostream>
using namespace std;

#define MAX_SIZE 20
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if(top == MAX_SIZE-1)
    {
        cout<<"Error: Stack overflow!";
    }
    top++;
    A[top] = x;
}

void Pop()
{
    if(top == -1)
    {
        cout<<"Error: No element to pop \n";
    }
    top--;
}

int Top()
{
    return A[top];
}

bool isEmpty()
{
    if(top == -1)
    return true;
    else
    return false;
}

int main()
{
    Push(5);
    Push(3);
    Push(4);
    Push(6);
    Push(7);
    Pop();
    Pop();
    cout<<Top();
}