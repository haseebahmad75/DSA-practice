#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

// class Stack
// {
//     private:
//     char A[50];
//     int top = -1;
//     public:
//     void Push(int x)
//     {
//         A[++top] = x;
//     }

//     void Pop()
//     {
//         top--;
//     }

//     int Top()
//     {
//         return A[top];
//     }

//     bool IsEmpty()
//     {
//         if(top == -1)
//         return true;
//         else
//         return false;
//     }
// };

void Reverse(char C[], int n)
{
    stack<char> S;
    // loop to enter string on stack
    for(int i=0; i < n; i++)
    {
        S.push(C[i]);
    }
    
    // loop to pop
    for(int i=0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }

}

int main()
{
    char C[50];
    cout<<"Enter a string: ";
    cin.getline(C,50); // reads a whole line of text

    Reverse(C, strlen(C));
    cout<<"Reversed string: " <<C;
}