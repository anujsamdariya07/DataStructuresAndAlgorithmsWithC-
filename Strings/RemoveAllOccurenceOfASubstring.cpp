#include<iostream>
#include<string>

using namespace std;

string removeOccurrences(string s, string part) 
{
    while(s.find(part) != string::npos)
    {
        // if inside this loop then part exists
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    cout << removeOccurrences("daabcbaabcbc", "abc") << endl;
}