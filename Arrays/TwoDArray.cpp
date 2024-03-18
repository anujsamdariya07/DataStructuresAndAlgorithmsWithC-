#include<iostream>

using namespace std;

void printArray(int arr[][4], int row, int column)
{
    cout << "The array is:-" << endl;
    for(int i = 0 ; i < row ; i++)
    {
        cout << "{";
        for(int j = 0 ; j < column ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "}";
        cout << endl;
    }
}

void sumTwoDArray(int arr[][4], int row, int column)
{
    int sum = 0;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            sum += arr[i][j];
        }
    }
    cout << "The sum of the given array is " << sum << endl;
}

void rowWiseSum(int arr[][4], int row, int column)
{
    int sum;
    for(int i = 0 ; i < row ; i++)
    {
        sum = 0;
        for(int j = 0 ; j < column ; j++)
        {
            sum += arr[i][j];
        }
        cout << "Sum of row " << i+1 << " is " << sum << endl;
    }
}

void columnWiseSum(int arr[][4], int row, int column)
{
    int sum;
    for(int i = 0 ; i < column ; i++)
    {
        sum = 0;
        for(int j = 0 ; j < row ; j++)
        {
            sum += arr[j][i];
        }
        cout << "Sum of column " << i+1 << " is " << sum << endl;
    }
}

void diagonalSum(int arr[][4], int row, int column)
{
    int sum = 0;
    for(int i = 0 ; i < row ; i++)
    {
        sum += arr[i][i];
    }
    cout << "Diagonal Sum is " << sum << endl;
}

void otherDiagonalSum(int arr[][4], int row, int column)
{
    int sum = 0;
    for(int i = 0 ; i < row ; i++)
    {
        sum += arr[i][column - 1 - i];
    }
    cout << "Other Diagonal Sum is " << sum << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transpose(int arr[][4], int row, int column)
{
    cout << "Original Matrix:-" << endl;
    for(int i = 0 ; i < row ; i++)
    {
        cout << "{";
        for(int j = 0 ; j < column ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "}" << endl;
    }

    for(int i = 0 ; i < row ; i++)
    {
        for(int j = i ; j < column ; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }

    cout << "Transpose Matrix:-" << endl;
    for(int i = 0 ; i < row ; i++)
    {
        cout << "{";
        for(int j = 0 ; j < column ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "}" << endl;
    }
}

int main()
{
    int arr[][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
    };
    printArray(arr, 4, 4);
    sumTwoDArray(arr, 4, 4);
    rowWiseSum(arr, 4, 4);
    columnWiseSum(arr, 4, 4);
    diagonalSum(arr, 4, 4);
    otherDiagonalSum(arr, 4, 4);
    cout << "-----Transpose Of A Matrix-----" << endl;
    transpose(arr, 4, 4);
}