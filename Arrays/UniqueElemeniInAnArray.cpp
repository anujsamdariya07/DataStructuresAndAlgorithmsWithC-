#include<iostream>

using namespace std;

void uniqueElementInAnArray(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = 0;
    for(int i = 0 ; i < size ; i++)
    {
        result ^= arr[i];
    }

    cout << "The unique element in this array is " <<
    result << endl;
}

int main()
{
    int arr[9] = {2, 34, 93, 63, 68 ,34, 93, 68, 63};
    uniqueElementInAnArray(arr, 9);
}