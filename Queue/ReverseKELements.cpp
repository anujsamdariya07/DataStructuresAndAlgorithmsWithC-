#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseKELements(queue<int> &q, int k)
{
    if (k > q.size() || k == 0)
    {
        return;
    }
    
    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        int front = q.front();
        q.pop();
        st.push(front);
    }
    

    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }

    for (int i = 0; i < (q.size()-k); i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
}

void print(queue<int> q)
{
    cout << "Queue: ";
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    print(q);
    reverseKELements(q, 3);
    print(q);
}