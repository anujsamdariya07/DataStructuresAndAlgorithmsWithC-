#include <iostream>
#include <stack>
#include <queue>

using namespace std;

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

void interLeaveQueue(queue<int> &first)
{
    queue<int> second;

    if (first.size() & 1)
    {
        for (int i = 0; i < (first.size()) / 2; i++)
        {
            int element = first.front();
            first.pop();
            second.push(element);
        }

        for (int i = 0; i < (first.size()) / 2; i++)
        {
            int element = second.front();
            second.pop();
            first.push(element);

            element = first.front();
            first.pop();
            first.push(element);
        }
    }
    else
    {
        for (int i = 0; i < (first.size()) / 2 + 1; i++)
        {
            int element = first.front();
            first.pop();
            second.push(element);
        }

        for (int i = 0; i < (first.size()) / 2 + 1; i++)
        {
            int element = second.front();
            second.pop();
            first.push(element);

            element = first.front();
            first.pop();
            first.push(element);
        }
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    print(q);
    interLeaveQueue(q);
    print(q);
}