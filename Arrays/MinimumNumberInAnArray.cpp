#include<iostream>
#include<limits.h>

using namespace std;

int minimumNumberInAnArray1(int arr[], int size)
{
    int minVal = INT_MAX;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

int minimumNumberBetweenTwo(int a, int b)
{
    if(a > b)
    {
        return b;
    } else
    {
        return a;
    }
}

int minimumNumberInAnArray2(int arr[], int size)
{
    int minVal = INT_MAX;
    for(int i = 0 ; i < size ; i++)
    {
        minVal = minimumNumberBetweenTwo(arr[i], minVal);
    }
    return minVal;
}

int main()
{
    int arr[10] = {15, 2978, 543, 46, 48, 374, 90, 76 ,91, 76};
    cout << "Minimum Number: " << minimumNumberInAnArray1(arr, 10) << endl;
    cout << "Minimum Number: " << minimumNumberInAnArray2(arr, 10) << endl;
}