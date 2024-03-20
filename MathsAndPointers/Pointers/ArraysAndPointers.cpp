#include <iostream>

using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4};
    // arr --> address of first element of array
    // &arr --> address of entire of array
    // This will point towards the first element of arr
    int *ptr3 = arr;
    // This will create a pointer poiting towards the entire arr
    int(*ptr4)[10] = &arr;
    // int* ptr3 = &arr;--> error
    cout << ptr3 << endl;

    char ch[10] = "Anuj";
    // This will point towards the entire ch
    char *cptr = ch;
    // char* cptr = &ch;--> error
    cout << cptr << endl;

    // Bad Practice because we are making the ptr cptr2 point to a temporary location so there is no credibility for the presence of "Anuj"
    char *cptr2 = "Anuj";
    cout << cptr2 << endl;
}