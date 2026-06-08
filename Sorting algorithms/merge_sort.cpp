#include<iostream>
using namespace std;

// this function is used to merge the two sorted arrays
void Merge(int arr[], int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    // declaring left and right sub-arrays
    int *L = new int[sizeL];
    int *R = new int[sizeR];

    // to copy the elements of array in left and right sub-arrays
    for(int i = 0; i < sizeL; i++)
    {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < sizeR; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i=0, j=0, k=left; // i is to keep track for loop of left array, j is for right array and k is for main array

    //checking whether the left or right sub-array has smaller element and placing it in array
    while(i < sizeL && j < sizeR)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // if we have some remaining elements in either left or right sub-arrays, these while loops will execute, to put them in main array
    while(i < sizeL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < sizeR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// to sort the left and right sub-arrays using recursion
void MergeSort(int arr[], int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left) / 2;

    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);

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
    int arr[] = {29,5,19,15,45,39,7,21,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before: ";
    PrintArray(arr,size);
    MergeSort(arr, 0, size -1);
    cout<<"\nAfter: ";
    PrintArray(arr, size);
}