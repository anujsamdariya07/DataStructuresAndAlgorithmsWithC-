#include <iostream>

using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        arr = new int[size]{};
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push_back(int val)
    {
        // Overflow
        // Remember IMP!
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Queue Overflow" << endl;
        }

        // EMpty case - first element
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }

        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }

        // Normal Flow
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void push_front(int val)
    {
        // Overflow
        if ((front == 0 && rear == size - 1) || rear == front - 1)
        {
            cout << "Queue Overflow" << endl;
        }

        // Empty
        else if (front == -1 && rear == -1)
        {
            front++, rear++;
            arr[front] = val;
        }

        // Circular
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
            arr[front] = val;
        }

        // Normal
        else
        {
            front--;
            arr[front] = val;
        }
    }

    void pop_front()
    {
        // Underflow
        if (front == -1 && rear == -1)
        {
            cout << "Queue Underflow" << endl;
        }

        // Single ELement
        else if (front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }

        // Circular nature
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }

        // Normal flow
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void pop_back()
    {
        // Underflow
        if (front == -1 && rear == -1)
        {
            cout << "Deque Underflow" << endl;
        }

        // Single element
        else if (front == rear)
        {
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }

        // Circular Nature
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }
        
        // Normal flow
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};

int main()
{
}