#include<iostream>

using namespace std;

int findFirstOccurence(int arr[], int size, int target)
{
    int start = 0, end = size - 1, answer = 0;
    int mid = (start + end) / 2;
    while(start <= end)
    {
        if(arr[mid] == target) 
        {
            answer = mid;
            end = mid - 1;
        } else if(target > arr[mid])
        {
            start = mid + 1;
        } else if(target < arr[mid])
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return answer;
}

int main()
{
    int arr[] = {10, 15, 20, 40, 50, 20, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20;
    int result = findFirstOccurence(arr, size, target);
    cout << "The target " << target << " first appears at " << result 
    << endl;
}