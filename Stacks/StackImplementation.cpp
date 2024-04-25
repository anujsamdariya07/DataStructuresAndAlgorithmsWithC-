#include<iostream>

using namespace std;

class Stack {
public: 
    int *arr;
    int size;
    int top;

    Stack (int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push (int data)
    {
        if (top == size-1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        
        top++;
        arr[top] = data;
    }

    void pop ()
    {
        if (top == -1)
        {
            cout << "Stack underflow" << endl;
            return;
        }
        top--;
    }

    bool isEmpty () {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    int getTop ()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        
        return arr[top];
    }

    int getSize ()
    {
        return top+1;
    }

    void printStack ()
    {
        cout << "Top: "<< top << endl;
        cout << "Top Element: " << getTop() << endl;

        cout << "Stack: ";
        for (int i = 0; i < getSize(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(8);
    st.push(10);
    st.printStack();
    st.push(20);
    st.printStack();
    st.push(30);

    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
    st.pop();
    st.printStack();
}