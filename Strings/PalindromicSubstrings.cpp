#include<iostream>
#include<string>

using namespace std;

bool isPallindrome(string s, int start, int end) 
{
    string s2 = s;
    int left = start, right = end;
    while(left < right)
    {
        swap(s[left], s[right]);
        left++, right--;
    }
    return (s == s2);
}

int countSubstrings(string s) 
{
    int count = 0;
    for(int i = 0 ; i < s.length() ; i++)
    {
        for(int j = i ; j < s.length() ; j++)
        {
            if(isPallindrome(s, i, j))
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    string str = "abbc";
    cout << countSubstrings(str) << endl;
}