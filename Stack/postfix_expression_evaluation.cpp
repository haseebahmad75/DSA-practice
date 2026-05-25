#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int Perform(int v1, int v2, char op)
{
    if(op == '+')
    return v1 + v2;
    if(op == '-')
    return v1 - v2;
    if(op == '*')
    return v1 * v2;
    if(op == '/')
    return v1 / v2;
}

int EvaluatePostfix(char C[])
{
    stack<int> S; // Operators(+, -, *, /) are never stored in the stack, they are only used to compute.

    for(int i = 0; i < strlen(C); i++)
    {
        if(C[i] >= '0' && C[i] <= '9')
        {
            S.push(C[i] - '0'); // this is to convert character digit into real integers. bcz C[i] stores characters that has ASCII values, so to convert it we minus '0'. '0' has 48 ASCII value
        }

        else if(C[i] == '+' || C[i] == '-' || C[i] == '*' || C[i] == '/')
        {
            // pop the previous two elements from stack to perform the operation
            // pop() does not return a value, it only removes the top element
            int v1 = S.top();
            S.pop(); 

            int v2 = S.top();
            S.pop();
            int res = Perform(v2, v1, C[i]);

            S.push(res);
        }
    }
    return S.top(); // returns the final result of expression
}

int main()
{
    /* In this implementation, we are assuming that input postfix expression will be correct
       and not handling any error condition */
    
    char C[30];
    cout<<"Enter a postfix expression: ";
    cin.getline(C,30);

    cout<<"Final Evaluation: " <<EvaluatePostfix(C);

}