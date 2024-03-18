#include <iostream>
#include <cmath>

using namespace std;

int decimalToBinaryByDivision(int n)
{
    int bit, binaryNumber = 0, i = 0;
    while(n != 0)
    {
        bit = (n % 2);
        binaryNumber += bit * pow(10, i);
        i++;
        n /= 2;
    }

    return binaryNumber;
}

int decimalToBinaryByBit(int n)
{
    int bit, binaryNumber = 0, i = 0;
    while(n)
    {
        bit = n & 1;
        binaryNumber += bit * pow(10, i);
        n = n >> 1;
        i++;
    }

    return binaryNumber;
}

int binaryToDecimal(int n)
{
    int bit, decimalNumber = 0, i = 0;
    while(n)
    {
        bit = n % 10;
        decimalNumber += bit * pow(2, i);
        i++;
        n /= 10;
    }

    return decimalNumber;
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << (decimalToBinaryByDivision(num)) << endl;
    cout << (decimalToBinaryByBit(num)) << endl;

    int binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;
    cout << binaryToDecimal(binaryNumber) << endl;
    
    return 0;
}