#include<iostream>

using namespace std;

int findLastOccurence(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid = (start + end) / 2, answer= 0;
    while(start <= end)
    {
        if(arr[mid] == target)
        {
            answer = mid;
            start = mid + 1;
        } else if(target < arr[mid])
        {
            end = mid - 1;
        } else if(target > arr[mid])
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return answer;
}

int main()
{
    int arr[] = {10, 20, 30, 30, 30, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    int result = findLastOccurence(arr, size, target);
    cout << "The target " << target << " last appears at index " 
    << result << endl;
}