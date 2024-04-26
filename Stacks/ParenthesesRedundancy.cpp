#include<iostream>
#include<stack>
#include<string>

using namespace std;

// It is given that the provided string will be with valid parentheses.
bool checkRedundant(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        {
            st.push(ch);
        } else if (ch == ')')
        {
            int opCount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '%')
                {
                    opCount++;
                }
                st.pop();
            }
            
            st.pop();

            if (opCount == 0)
            {
                return true;
            }
        }    
    }
    return false;
}

int main()
{
    string str = "(((a+b)*(c+d)))";
    bool ans = checkRedundant(str);

    if (ans == true)
    {
        cout << "Redundant Brackets Present" << endl;
    } else {
        cout << "Redundants Brackets Not Present" << endl;
    }
    
}