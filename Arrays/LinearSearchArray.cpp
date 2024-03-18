#include<iostream>

using namespace std;

bool linearSearchArray(int arr[], int size, int target)
{
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == target)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    int arr[5] = {546, 10, 946, 48, 13};
    if(linearSearchArray(arr, 5, 10))
    {
        cout << "Target Found" << endl;
    } else
    {
        cout << "Target Not Found" << endl;
    }
}