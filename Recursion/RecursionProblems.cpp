#include<iostream> 
#include<cstring> 

using namespace std;

// To find out whether an array is sorted or not.
bool isSortedArray(int arr[], int size, int index)
{
    // base condition
    if(index >= size) return true;
    
    if(arr[index] > arr[index-1]) {
        isSortedArray(arr, size, index+1);
    } else
    {
        return false;
    }
}

// Binary Search using recursion
int recursiveBinarySearch(int arr[], int start, int end, int target)
{
    int mid = start + (end - start)/2;

    // Base condition
    if(start > end) return -1;

    if(target == arr[mid]) 
    {
        return mid;
    } else if(target > arr[mid]) 
    {
        recursiveBinarySearch(arr, mid+1, end, target);
    } else if(target < arr[mid]) 
    {
        recursiveBinarySearch(arr, start, mid-1, target);
    }
}

// To find all the subsequences of a string in it's given order
void findSubsequences(string str, string output, int index)
{
    if(index >= str.length()) 
    {
        cout << "-->" << output << endl;
        return;
    }

    char ch = str[index];

    // Exclude 
    findSubsequences(str, output, index+1);

    // Include
    output.push_back(ch);
    findSubsequences(str, output, index+1);
}

int main()
{
    int arr[6] = {10, 20, 30, 40, 50, 60};

    // To find out whether an array is sorted or not.
    string answer = isSortedArray(arr, 6, 1)? "The array is sorted":"The array is unsorted.";
    cout << answer << endl;

    if (recursiveBinarySearch(arr, 0, 5, 30) == -1)
    {
        cout << "Element not found." << endl;
    } else 
    {
        cout << "Element found at index: " << recursiveBinarySearch(arr, 0, 5, 30) << endl;
    }

    cout << "Subsequences of string \"abc\" are: " << endl;
    findSubsequences("abc", "", 0);
}