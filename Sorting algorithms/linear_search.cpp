#include<iostream>
using namespace std;

int LinearSearch(int arr[], int n, int target)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void FindAll(int arr[], int n, int target)
{
    bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            cout<<"Found at index: " <<i <<endl;
            found = true;
        }
    }
    if(!found)
    {
        cout<<"Not found.";
    }
}

int main()
{
    int arr[] = {1,3,5,9,10,15,9,20,30,9, 13, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout<<"Enter value to search: ";
    cin >> target;

    FindAll(arr, size, target);
}