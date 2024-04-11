#include<iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int arr[], int size, int start, int end)
{    
    // Base condition
    if(start >= end) return;
    
    int pivot = end;
    int i = start-1, j = start;
    while(j < pivot)
    {
        if(arr[j] < arr[pivot])
        {
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    pivot = i;

    // For left array
    quickSort(arr, size, start, pivot-1);

    // For right array
    quickSort(arr, size, pivot+1, end);
}

int main()
{
    int arr[] = {7, 2, 1, 8, 6, 3, 5, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before quick sort: " << endl;
    printArray(arr, size);
    quickSort(arr, size, 0, size-1);
    cout << "Array after quick sort: " << endl;
    printArray(arr, size);
}