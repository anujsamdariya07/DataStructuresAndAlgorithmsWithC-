#include<iostream>

using namespace std;

int oddOccuringElement(int arr[], int size)
{
    int start = 0, end = size - 1;
    int mid = start + (end - start) / 2;
    while(start <= end)
    {
        if(mid % 2 == 0)
        {
            if(arr[mid] == arr[mid+1])
            {
                start = mid + 2;
            } else
            {
                end = mid;
            }
        } else if(mid % 2 == 1)
        {
            if(arr[mid] == arr[mid - 1])
            {
                start = mid + 1;
            } else
            {
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
        if(start == end)
        {
            return start;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = oddOccuringElement(arr, size);
    cout << "The odd occuring element is " << arr[result] << 
    " at index " << result << endl;
}