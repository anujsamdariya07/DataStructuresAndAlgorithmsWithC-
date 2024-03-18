#include <iostream>

using namespace std;

void printName(string name)
{
    for(int i = 0 ; i < 5 ; i++)
    {
        cout << name << endl;
    }
}

void printSum2(int a, int b)
{
    cout << a + b << endl;
}

void printSum3(int a, int b, int c)
{
    cout << a + b + c << endl;
}

int main()
{
    printSum2(10, 8);
    
    return 0;
}