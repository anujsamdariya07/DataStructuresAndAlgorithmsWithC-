#include <iostream>

using namespace std;

void callByValue(int *ptr) 
{
    ptr += 1;
}

void callByReference(int *&ptr) 
{
    ptr += 1;
}

int main()
{
    int a = 5;
    int* ptr = &a;
    int** ptr2 = &ptr;
    // cout << "a: " << a<< endl;
    // cout << "*ptr: " << *ptr << endl;
    // cout << "**ptr2: "<< **ptr2 << endl;

    cout << "--------Cal By Value--------" << endl;

    // Before call by value
    cout << "a before call by value: " << a << endl;
    cout << "&a before call by value: " << &a << endl;
    cout << "ptr before call by value: " << ptr << endl;
    cout << "*ptr before call by value: " << *ptr << endl;

    callByValue(ptr);

    // After call by value
    cout << "a after call by value: " << a << endl;
    cout << "&a after call by value: " << &a << endl;
    cout << "ptr after call by value: " << ptr << endl;
    cout << "*ptr after call by value: " << *ptr << endl;

    cout << "--------Cal By Reference--------" << endl;

    // Before call by reference
    cout << "a before call by reference: " << a << endl;
    cout << "&a before call by reference: " << &a << endl;
    cout << "ptr before call by reference: " << ptr << endl;
    cout << "*ptr before call by reference: " << *ptr << endl;

    callByReference(ptr);

    // After call by reference
    cout << "a after call by reference: " << a << endl;
    cout << "&a after call by reference: " << &a << endl;
    cout << "ptr after call by reference: " << ptr << endl;
    cout << "*ptr after call by reference: " << *ptr << endl;
}