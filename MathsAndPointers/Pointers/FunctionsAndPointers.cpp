#include<iostream>

using namespace std;

void solve(int *arr, int size) {
    cout << "Size of arr inside function: " << arr << endl;
    // Only &arr inside the function will have a diffrent value
    cout << "Size of &arr inside function: " << &arr << endl;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    cout << "Size of arr outside function: " << arr << endl;
    cout << "Size of &arr outside function: " << arr << endl;
    // When we pass an array to a function as an argument, only the address of arr[0] or arr is passed to the function
    solve(arr, 5);
}