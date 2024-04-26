#include <iostream>

using namespace std;

class CQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int size)
    {
        arr = new int[size]{};
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
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

    void pop()
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

    void printQueue()
    {
        cout << "Front: "<< front << ", Rear: " << rear << endl;
        
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
    CQueue q(5);
    q.printQueue();

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.printQueue();
    q.push(60);

    q.printQueue();

    q.pop();
    q.printQueue();

    q.push(100);
    q.printQueue();
}
// Using modulus operator is a heavy operation so always try to avoid it ans use any other method possible.