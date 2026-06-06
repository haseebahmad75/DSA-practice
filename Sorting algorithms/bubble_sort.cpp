#include<iostream>
using namespace std;

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        bool swapped = false;
        for(int j = 0; j < n-1-i; j++) // last i elements are already sorted, that's why we minus it
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped)
        break;
    }
}

void PrintArray(int arr[], int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout<<arr[i] <<"  ";
    }
    cout<<endl;
}

int main()
{
    int count = 0;
    int arr[] = {64,35,25,10,70,15};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before: ";
    PrintArray(arr,n);
    BubbleSort(arr,n);
    cout<<"After: ";
    PrintArray(arr,n);

    return 0;
}