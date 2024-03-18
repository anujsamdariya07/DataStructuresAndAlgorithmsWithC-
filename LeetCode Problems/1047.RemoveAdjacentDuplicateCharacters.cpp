#include<iostream>

using namespace std;

string removeDuplicates1(string s) 
{
    int i = 1;
    while(i < s.length())
    {
        if(s[i] == s[i-1])
        {
            s.erase(i-1, 2);
            i = 1;
        } else 
        {
            i++;
        }
    }
    return s;
}

string removeDuplicates2(string s) 
{
    int i = 0;
    while(i < s.length())
    {
        if(s[i] == s[i+1])
        {
            s.erase(i, 2);
            i = 0;
        } else 
        {
            i++;
        }
    }
    return s;
}

int main()
{
    cout << "Time limit exceeded: " << removeDuplicates1("abbaca") << endl;
    cout << "Correct Solution: " << removeDuplicates2("abbaca") << endl;
}