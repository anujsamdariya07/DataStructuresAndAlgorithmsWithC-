#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Size: "<< st.size() << endl;
    st.pop();
    if (st.empty())
    {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << "Top element: " << st.top() << endl;
    
}
// No index in stack only one way--> top, cannot print entire stack at once