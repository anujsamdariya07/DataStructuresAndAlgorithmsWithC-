#include<iostream>
#include<vector>
using namespace std;

void printArray(int arr[], int size, int index){
    if(index >= size) return;
    cout << arr[index] << " ";
    printArray(arr, size, index+1);
}

bool searchArray(int arr[], int size, int index, int target){
    if(index >= size) return false;
    if(arr[index] == target) return true;
    return searchArray(arr, size, index+1, target);
}

void solveArray(int arr[], int size, int index, vector<int> &ans){
    if(index >= size) return;
    if (arr[index] % 2 == 0)
    {
        ans.push_back(arr[index]);
    }
    solveArray(arr, size, index+1, ans);
}

void doubleArray(int arr[], int size, int index)
{
    if(index >= size) return;
    arr[index] *= 2;
    doubleArray(arr, size, index+1);
}

int targetIndex(int arr[], int size, int index, int target) 
{
    if(index >= size) return -1;

    if(target == arr[index]) return index;
    else return targetIndex(arr, size, index+1, target);
}

vector<int>& integerToVector(int num, vector<int> &ans)
{
    if(num == 0) return ans;

    int digit = num % 10;
    ans.push_back(digit);
    num /= 10;
    return integerToVector(num, ans);
}

int main() {
    int arr[] = {10, 21, 30, 41, 50};
    printArray(arr, 5, 0);
    cout << endl << searchArray(arr, 5, 0, 30) << endl;
    vector<int> ans;
    solveArray(arr, 5, 0, ans);
    for(int num: ans)
    {
        cout << num << " ";
    }
    cout << endl;
    doubleArray(arr, 5, 0);
    for(int num: arr)
    {
        cout << num << " ";
    }
    cout << endl << "60 is at index: "<< targetIndex(arr, 5, 0, 60) << endl;
    vector<int> ans2;
    integerToVector(4215, ans2);
    for(int num: ans2)
    {
        cout << num << " ";
    }
}
