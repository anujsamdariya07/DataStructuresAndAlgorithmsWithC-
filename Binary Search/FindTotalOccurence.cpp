#include<iostream>

using namespace std;

int findTotalOccurence(int arr[], int size, int target)
{
    int start = 0, end = size - 1, mid = (start + end) / 2, count = 0;
    while(start <= end)
    {
        if(arr[mid] == target)
        {
            count++;
            start = mid + 1;
        } else if(arr[mid] > target)
        {
            end = mid - 1;
        } else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    start = 0, end = size - 1, mid = (start + end) / 2;
    while(start <= end)
    {
        if(arr[mid] == target)
        {
            count++;
            end = mid - 1;
        } else if(arr[mid] > target)
        {
            end = mid - 1;
        } else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return count + 1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 40, 40, 40, 40, 40, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 40;
    int result = findTotalOccurence(arr, size, target);
    cout << "The target " << target << " occurs " << result << 
    " times." << endl;
}