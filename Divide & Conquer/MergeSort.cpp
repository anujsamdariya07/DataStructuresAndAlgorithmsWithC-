#include<iostream>

using namespace std;

void merge(int arr[], int start, int end)
{
    int mid = (start + end)/2;

    // Left array starts from start to mid
    // for an array having 5 elements, left array will be of indexes 0, 1, 2, length = 3 = (2-0) + 1 => (mid-start) + 1
    int lenLeft = mid - start + 1;

    // Right array starts from mid+1 to end
    // for an array having 5 elements, right array will be of indexes 3, 4, length = 2 = (4-2) => (end-mid)
    int lenRight = end - mid;

    // Now creating left array and right array
    int *leftArr = new int[lenLeft];
    int *rightArr = new int[lenRight];

    // Copying values from orginal array to left array
    int k = start;
    for(int i = 0 ; i < lenLeft ; i++)
    {
        leftArr[i] = arr[k];
        k++;
    }

    // Copying values from orginal array to right array
    k = mid+1;
    for(int i = 0 ; i < lenRight ; i++)
    {
        rightArr[i] = arr[k];
        k++;
    }

    // Now, left and right arrays are already sorted. So we will be merging them into a single sorted array
    int leftIndex = 0, rightIndex = 0;
    int mainArrayIndex = start;

    while(leftIndex < lenLeft && rightIndex < lenRight)
    {
        if(leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrayIndex] = leftArr[leftIndex];
            mainArrayIndex++, leftIndex++;
        } else {
            arr[mainArrayIndex] = rightArr[rightIndex];
            mainArrayIndex++, rightIndex++;
        }
    }

    // 2 corner-cases:
    // 1. Left array ❌, right array ✅
    while(rightIndex < lenRight)
    {
        arr[mainArrayIndex] = rightArr[rightIndex];
        mainArrayIndex++, rightIndex++;
    }
    // 2. Right array ❌, left array ✅
    while(leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = leftArr[leftIndex];
        mainArrayIndex++, leftIndex++;
    }

    // Delete the dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int start, int end)
{
    // Base condition
    if(start > end)
    {
        // Invalid array
        return;
    }
    if(start == end) 
    {
        // Single array element
        return;
    }

    int mid = (start + end)/2;

    // Array -> Left Array + Right Array
    // Left Array -> start ---- mid
    // Right Array -> mid+1 ---- end

    // Recursive call for left array
    mergeSort(arr, start, mid);
    // Recursive call for right array
    mergeSort(arr, mid+1, end);

    // Merge array
    merge(arr, start, end);
}

int main()
{
    int arr[] = {2, 1, 6, 9, 4, 5};
    int size = 6;
    int start = 0, end = size-1;

    cout << "Before merge sort: " << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, start, end);

    cout << "After merge sort: " << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}