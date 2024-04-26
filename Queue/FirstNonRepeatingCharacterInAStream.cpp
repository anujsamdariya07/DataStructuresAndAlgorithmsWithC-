#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
    string str = "ababc";
    int freq[26] = {0};
    queue<char> q;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);

        while (!q.empty())
        {
            char frontElement = q.front();
            if (freq[frontElement-'a'] > 1)
            {
                q.pop();
            } else 
            {
                cout << frontElement << "->";
                break;
            }
        }
        
        if (q.empty())
        {
            cout << "#" << "->";
        }
    }
    
}