#include<iostream>

using namespace std;

void sortingNegativePositive(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int j = 0;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }

    cout << "Sorted Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    int arr[5] = {-1, 2, 3, -4, -5};
    sortingNegativePositive(arr, 5);
}