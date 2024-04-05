#include<iostream>
#include<climits>

using namespace std;

int maximizeCuts(int n, int x, int y, int z)
{
    if(n == 0) return 0;
    if (n < 0) return INT_MIN;

    // take 1 segment of x and leave the rest to recursion
    int option1 = 1 + maximizeCuts(n-x, x, y, z);
    // take 1 segment of y and leave the rest to recursion
    int option2 = 1 + maximizeCuts(n-y, x, y, z);
    // take 1 segment of x and leave the rest to recursion
    int option3 = 1 + maximizeCuts(n-z, x, y, z);

    int finalAnswer = max(option1, max(option2, option3));
    return finalAnswer;
}

int main()
{
    int n = 40;
    cout << maximizeCuts(n, 2, 3, 5) << endl;
}