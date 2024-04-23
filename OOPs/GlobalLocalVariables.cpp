#include<iostream>

using namespace std;

// Global variable
int x = 10;

int main()
{
    // Local variable
    int x = 4;

    // This will print local x
    cout << x << endl;

    // This will print global x
    cout << ::x << endl;

    {
        int x = 100;
        cout << x << endl;
        // This will print global x, ie, 10
        cout << ::x << endl;
    }
}