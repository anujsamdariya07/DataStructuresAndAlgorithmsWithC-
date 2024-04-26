// Also known as deque
#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_front(20);
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << dq.size() << endl;

    dq.pop_back();
    cout << "Front: " << dq.front() << endl;
    cout << dq.size() << endl;
}