#include<iostream>

using namespace std;

int findPivotElement(int arr[], int size)
{
    int answer = -1;
    int start = 0, end = size - 1, mid = (start + end) / 2;
    while(start <= end)
    {
        if(arr[mid] > arr[mid+1])
        {
            answer = mid;
            break;
        } else if(arr[mid] < arr[mid-1])
        {
            answer = mid - 1;
            break;
        } else if(arr[mid] < arr[start])
        {
            end = mid - 1;
        } else
        {
            start = mid + 1;
        }
        if(start == end)
        {
            answer = start;
        }
        mid = (start + end) / 2;
    }
    return answer;
}

int main()
{
    int arr[] = {12, 14, 16, 2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findPivotElement(arr, size);
    cout << "The pivot element " << arr[result] << 
    " is at index " << result << "." << endl;
}