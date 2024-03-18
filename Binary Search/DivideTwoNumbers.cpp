#include<iostream>

using namespace std;

int divideTwoNumbers(int num1, int num2)
{
    int negative = 0;
    if((num1 < 0) || (num2 < 0))
    {
        negative = 1;
    }
    if(num2 == 0)
    {
        return -1;
    }
    num1 = abs(num1);
    num2 = abs(num2);
    int start = 0;
    int end = num1;
    int mid = start + (end - start) / 2;
    int result = 0;
    while(start <= end)
    {
        if(mid * num2 == num1)
        {
            result = mid;
            break;
        } else if(mid * num2 > num1)
        {
            end = mid - 1;
        } else if(mid * num2 < num1)
        {
            result = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    if(negative == 1)
    {
        result -= 2*result;
    }
    return result;
}

int main()
{
    int num1, num2;
    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;
    int result = divideTwoNumbers(num1, num2);
    if(result == -1)
    {
        cout << "Not defined" << endl;
    } else
    {
    cout << "Answer = " << result << endl;
    }
}