#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

bool HasHigherPrecedence(char top, char op)
{
   // setting priority
   int pTop, pOp;
   if(top == '+' || top =='-') 
   pTop = 1;
   else if(top == '*' || top =='/')
   pTop = 2;

   if(op == '+' || op == '-')
   pOp = 1;
   else if(op == '*' || op == '/')
   pOp = 2;

   return pTop >= pOp;
}

string InfixToPostfix(char C[])
{
    stack<char> S;
    string exp;

    for(int i = 0; i < strlen(C); i++)
    {
        if(C[i] >= '0' && C[i] <= '9')
        {
            exp += C[i];
        }
        else if(C[i] == '+' || C[i] == '-' || C[i] == '*' || C[i] == '/')
        {
            while(!S.empty() && HasHigherPrecedence(S.top(), C[i])) // if the operator in stack has higher precedence than the current operator, then it is written into postfix before the current operator
            {
                exp += S.top();
                S.pop();
            }
            S.push(C[i]);
        }
    }
    while(!S.empty()) // for any leftover operators in the stack
    {
        exp += S.top();
        S.pop();
    }
    return exp;
}

int main()
{
    char C[30];
    cout<<"Enter an infix expression: ";
    cin.getline(C,30);

    cout<<"Postfix expression: " <<InfixToPostfix(C);


}