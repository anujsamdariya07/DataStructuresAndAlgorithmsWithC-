#include<iostream>

using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    while(start <= end)
    {
        if(arr[mid - 1] == target)
        {
            return mid - 1;
        } else if(arr[mid] == target)
        {
            return mid;
        } else if(arr[mid + 1] == target)
        {
            return mid + 1;
        } else if(arr[mid] < target)
        {
            start = mid + 2;
        } else
        {
            end = mid - 2;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int result = binarySearch(arr, size, target);
    if(result == -1)
    {
        cout << "Target not found" << endl;
    } else
    {
        cout << "Target found at index at " << result << endl;
    }
}