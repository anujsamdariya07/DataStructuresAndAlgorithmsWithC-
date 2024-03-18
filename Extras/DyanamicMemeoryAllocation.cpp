#include<iostream>

using namespace std;

void printArray(int arr[], int size)
{
    cout << "The array is:-" << endl;
    for(int i = 0 ; i < size ; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;
}

void inputArray(int arr[], int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout << "Enter " << i + 1 << ": ";
        cin >> arr[i];
    }
}

int main()
{
    // Static memory allocation
    int arr[5] = {1, 2, 4, 6, 7};
    printArray(arr, 5);

    // Dyanamic memory allocation
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    int *arr2 = new int[n];
    inputArray(arr2, n);
    printArray(arr2, n);
}