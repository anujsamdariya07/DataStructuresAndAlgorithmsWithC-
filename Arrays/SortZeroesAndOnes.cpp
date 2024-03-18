#include<iostream>

using namespace std;

void sortZeroesAndOnes(int arr[], int size)
{
    cout << "Original Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int zeroCount = 0, oneCount = 0;
    // Counting the number of zeroes and ones
    for(int i = 0 ;  i < size ; i++)
    {
        if(arr[i] == 0)
        {
            zeroCount++;
        } else if(arr[i] == 1)
        {
            oneCount++;
        }
    }

    // Setting the desired result
    for(int i = 0 ; i < size ; i++)
    {
        if(i >= 0 && i < zeroCount)
        {
            arr[i] = 0;
        } else if(i >= zeroCount && i < size)
        {
            arr[i] = 1;
        }
    }

    cout << "Sorted Array:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[10] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 0};
    sortZeroesAndOnes(arr, 10);
}