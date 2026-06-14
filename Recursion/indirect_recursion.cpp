#include<iostream>
using namespace std;

// indirect recursion

void odd(int n);
void even(int n);

void odd(int n)
{
    if(n <= 10)
    {
        cout<< n+1 <<"  "; // add 1 if number is odd
        n++;
        even(n);
    }
    return;
}

void even(int n)
{
    if(n <= 10)
    {
        cout << n-1 <<"  "; // subtract 1 if number is even
        n++;
        odd(n);
    }
    return;
}

int main()
{
    odd(1);
    return 0;
}