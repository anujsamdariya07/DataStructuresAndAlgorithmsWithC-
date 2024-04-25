#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    stack<char> st;
    string str = "helojee";

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        st.push(ch);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    
}