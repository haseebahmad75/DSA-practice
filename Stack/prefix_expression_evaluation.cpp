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

    return 0;
}

int EvaluatePrefix(char C[])
{
    stack<int> S;
    for(int i = strlen(C)-1; i >= 0; i--)
    {
        if(C[i] >= '0' && C[i] <= '9')
        {
            S.push(C[i] - '0');
        }

        else if(C[i] == '+' || C[i] == '-' || C[i] == '*' || C[i] == '/')
        {
            int v1 = S.top(); // In prefix, 1st top = left operand
            S.pop();

            int v2 = S.top(); // 2nd top element = right operand and correct answer is <left> <operator> <right>
            S.pop();

            int res = Perform(v1, v2, C[i]);
            S.push(res);
        }
    }
    return S.top();
}
int main()
{
    char C[50];
    cout<<"Enter a prefix expression: ";
    cin.getline(C,50);

    cout<<"Evaluation of given expression: " << EvaluatePrefix(C);
}