#include<iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseAnArray(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i< size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int left = 0, right = size - 1;
    while(left < right)
    {
        swap(&arr[left], &arr[right]);
        left++;
        right--;
    }
    cout << "Reversed Array:-" << endl;
    for(int i = 0 ; i< size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverseAnArray(arr, 10);
}