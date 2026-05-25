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

bool IsOpeningParentheses(char op)
{
    if(op == '[' || op == '{' || op == '(')
    return true;
    else 
    return false;
}

bool IsClosingParentheses(char op)
{
    if(op == ')' || op == '}' || op == ']')
    return true;
    else
    return false;
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
            while(!S.empty() && !IsOpeningParentheses(S.top()) && HasHigherPrecedence(S.top(), C[i])) // if the operator in stack has higher precedence than the current operator, then it is written into postfix before the current operator
                                // pop and store into postfix until we get an opening parentheses
            {
                exp += S.top();
                S.pop();
            }
            S.push(C[i]);
        }
        else if(IsOpeningParentheses(C[i]))
        {
            S.push(C[i]);
        }
        else if(IsClosingParentheses(C[i]))
        {
            while(!S.empty() && !IsOpeningParentheses(S.top()))
            {
                exp += S.top();
                S.pop();
            }
            S.pop(); // to pop the corresponding opening parentheses
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