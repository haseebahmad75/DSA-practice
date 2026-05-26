#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Palindrome string means if you reverse the string, it stays unchanged.

string ReverseString(string s)
{
    stack<char> S;
    string rev;

    for(int  i = 0; i < s.length(); i++)
    {
        S.push(s[i]);
    }

    for(int i = 0; i < s.length(); i++)
    {
        rev += S.top();
        S.pop();
    }
    return rev;
}

// for string, use length() and getline(cin, string_name) to take input
// for char[] (array of characters), use strlen(name) and cin.getline(name, size)

int main()
{
    string s;
    cout<<"Enter a word: ";
    getline(cin,s);

    string reversed = ReverseString(s);
    if(s == reversed)
    {
        cout<<"Palindrome";
    }
    else
    {
        cout<<"Not Palindrome";
    }
}