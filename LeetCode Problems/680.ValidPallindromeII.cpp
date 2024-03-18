#include<iostream>
#include<string>

using namespace std;

bool isPallindrome(string s) 
{
    string s2 = s;
    int left = 0, right = s.length() - 1;
    while(left < right)
    {
        swap(s[left], s[right]);
        left++, right--;
    }
    return (s == s2);
}

bool validPalindromeII1(string s) 
{
    string s2 = s;
    for(int i = 0 ; i < s.length() ; i++)
    {
        s.erase(i, 1);
        if(isPallindrome(s))
        {
            return true;
        }
        s = s2;
    }
    return false;
}

bool validPalindromeII2(string s) 
{
    string s2 = s;
    int left = 0, right = s.length() - 1;
    while(left < right) 
    {
        if(s[left] == s[right])
        {
            left++, right--;
        }
        else 
        {
            string str1 = s.erase(left, 1);
            s = s2;
            string str2 = s.erase(right, 1);
            s = s2;
            return isPallindrome(str1) || isPallindrome(str2);
        }
    }
    return true;
}

int main()
{
    string str = "abc";
    string result1 = validPalindromeII1(str) ? "Time Limit Exceeded: Valid Pallindrome II" : "Time Limit Exceeded: Invalid Pallindrome II";
    cout << result1 << endl;
    string result2 = validPalindromeII2(str) ? "Correct Solution: Valid Pallindrome II" : "Correct Solution: Invalid Pallindrome II";
    cout << result2 << endl;
}