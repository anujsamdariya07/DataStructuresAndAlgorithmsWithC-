#include<iostream>

using namespace std;

void printingPairsInAnArray(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "All the possible pairs of this array:-" 
    << endl;
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            cout << "(" << arr[i] << ", " << 
            arr[j] << ")" << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printingPairsInAnArray(arr, 10);
}