#include<iostream>

using namespace std;

int findMissingElement(int arr[], int size)
{
    int start = 0, end = size - 1, mid = (start + end) / 2, answer = -1;
    while(start <= end) 
    {
        if((arr[mid] - mid) == 1)
        {
            start = mid + 1;
        } else
        {
            answer = mid;
            end = mid - 1;
        }
        mid = (start + end) / 2;
        if(start == end)
        {
            if(answer + 1 == 0)
            {
                return size + 1;
            }
            return answer + 1;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findMissingElement(arr, size);
    cout << "The missing element is " << result << endl;
}