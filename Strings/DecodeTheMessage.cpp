#include<iostream>
#include<string>

using namespace std;

string decodeMessage(string key, string message) 
{
    // 1. Create mapping
    char start = 'a';
    char mapping[300] = {0};
    for(auto ch: key)
    {
        if(ch != ' ' && mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++;
        }
    }
    
    // 2. Use mapping
    string ans;
    for(auto ch: message)
    {
        if(ch == ' ')
        {
            ans.push_back(' ');
        } else
        {
            ans.push_back(mapping[ch]);
        }
    }
    return ans;
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    cout << decodeMessage(key, message) << endl;
}