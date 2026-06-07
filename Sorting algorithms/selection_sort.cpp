#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }      
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i] <<" ";
    }
}

int main()
{
    int arr[] = {4,20,15,9,2,17,13,0};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Before: ";
    PrintArray(arr,size);
    cout<<"\nAfter: ";
    SelectionSort(arr,size);
    PrintArray(arr,size);
}
