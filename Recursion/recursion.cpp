#include<iostream>
using namespace std;

int Fact(int num)
{
    if(num == 1)
    {
        return 1;
    }
    else
    {
        return num * Fact(num - 1);
    }
}

int main()
{
    int num;
    cout<<"Enter a number to calculate factorial: ";
    cin>>num;
    cout<<"Factorial: " <<Fact(num);
}