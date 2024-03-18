#include<iostream>

using namespace std;

void printExtremesInAnArray(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int left = 0, right = size - 1;
    int i = 1;
    cout << "It's Extremes are:-" << endl;
    while(right > left)
    {
        cout << "Extreme No." << i  << ": " << arr[left] << ", " 
        << arr[right] << endl;
        left++, right--, i++;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printExtremesInAnArray(arr, 10);
}