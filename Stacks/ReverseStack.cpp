#include <iostream>
#include <stack>

using namespace std;

void pushAtBottom (stack<int> &st, int data)
{
    int size = st.size();
    if (size == 0)
    {
        st.push(data);
        return;
    }
    
    int temp = st.top();
    st.pop();
    pushAtBottom(st, data);
    st.push(temp);
}

void reverseStack (stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverseStack(st);

    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    st.pop();
    cout << st.top() << " ";
    cout << endl;
}