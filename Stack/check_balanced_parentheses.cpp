#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

bool isBalanced(char C[], int n)
{
    stack<char> S;

    for(int i = 0; i < n; i++)
    {
        if(C[i] == '[' || C[i] == '{' || C[i] =='(')
        {
            S.push(C[i]);
        }
        else if(C[i] == ']' || C[i] == '}' || C[i] == ')')
        {
            if(S.empty())
            {
                return false;
            }

            if(S.top() == '[' && C[i] == ']' || S.top() == '{' && C[i] == '}' || S.top() == '(' && C[i] == ')')
            {
                S.pop();
            }
            else 
            {
                return false;
            }
            
        }
    }
    return S.empty()? true: false;
}

int main()
{
    char C[20];
    cout<<"Enter an expression of parentheses: ";
    cin.getline(C,20);

    if(isBalanced(C, strlen(C)))
       cout<<"Parentheses are balanced";
    else
       cout<<"Not balanced";
}