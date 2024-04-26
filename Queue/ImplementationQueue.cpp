#include<iostream>

using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size]{};
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        if (rear == size-1)
        {
            // Full
            cout << "Queue overflow" << endl;
        } else if (front == -1 && rear == -1)
        {
            // EMpty case
            rear++, front++;
            arr[rear] = val;
        } else
        {
            rear++;
            arr[rear] = val;
        }
                
    }

    void pop()
    {
        if (front == -1 && rear == -1)
        {
            // EMpty
            cout << "Queue underflow" << endl;
        } else if (front == rear)
        {
            // Single element removal
            arr[front] = -1;
            front = -1;
            rear = -1;
        } else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        } else
        {
            return false;
        }
    }

    int getSize()
    {
        if (front == -1 && rear == -1)
        {
            return 0;
        }
        
        return rear-front+1;
    }

    int getFront()
    {
        if (front == -1)
        {
            cout << "No element can give front element" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }

    void printQueue()
    {
        cout << "Printing Queue: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);
    q.printQueue();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.printQueue();

    cout << "Size of queue: "<< q.getSize() << endl;

    q.pop();
    q.printQueue();

    cout << "Size of queue: "<< q.getSize() << endl;
}