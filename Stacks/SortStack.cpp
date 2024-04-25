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

void insertInASortedArray(stack<int> &st, int data)
{
    if (st.empty() || data > st.top())
    {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();
    insertInASortedArray(st, data);
    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertInASortedArray(st, temp);
}

int main()
{
    stack<int> st;
    st.push(43);
    st.push(30);
    st.push(37);
    st.push(23);
    st.push(19);

    sortStack(st);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << endl;
}