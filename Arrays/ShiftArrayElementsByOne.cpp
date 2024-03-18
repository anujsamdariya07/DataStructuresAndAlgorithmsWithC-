#include<iostream>

using namespace std;

void shiftArrayElementsByOne(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int temp = arr[size - 1];
    for(int i = size - 1 ; i >= 1 ; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;

    cout << "Shifted Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i]<< " ";
    }
}

int main()
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    shiftArrayElementsByOne(arr, 10);
}