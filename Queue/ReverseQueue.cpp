#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        int element = q.front();
        q.pop();
        st.push(element);
    }
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }
}

void reverseQueueUsingRecursion(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    
    int element = q.front();
    q.pop();
    reverseQueueUsingRecursion(q);
    q.push(element);
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

    reverseQueue(q);

    print(q);

    reverseQueueUsingRecursion(q);

    print(q);
}