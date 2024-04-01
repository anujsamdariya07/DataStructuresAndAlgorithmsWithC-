// When a function calls itself directly or indirectly
// Used when solution of a big problem depends on the solution of a similar smaller problem

#include<iostream>
#include<cmath>

using namespace std;

int factorial(int n)
{
    // Base case
    if(n == 1) 
    {
        return 1;
    }
    if(n == 0) 
    {
        return 1;
    }
    
    // Recursive Relation
    return n * factorial(n-1);
    
    // Processing
    // here * is the processing as we are multiplying n to the smaller answer
}

// Head Recursion
void print1(int n) 
{
    if(n == 1) 
    {
        cout << 1 << endl;
        return;
    }
    cout << n << " ";
    print1(n-1);
}

// Tail Recursion
void print2(int n) 
{
    if(n == 1) 
    {
        cout << 1 << endl;
        return;
    }
    print2(n-1);
    cout << n << " ";
}

int power(int num, int p) 
{
    if (p == 0) 
    {
        return 1;
    }
    return num * pow(num, p-1);
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    } 
    if(n == 1) 
    {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    cout << "Factorial of 5 is " << factorial(5) << endl;
    print1(5);
    print2(5);
    cout << endl << "2 to the power 5 is " << power(2, 5) << endl;
    cout << "5th element of fibonacci series is "<< fibonacci(5) << endl;
}
// 0, 1, 1, 2, 3, 5