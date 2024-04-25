#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    cout << "Printing the entire linked list:-" << endl;

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void createTail(Node *head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void deleteFromHead(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    
    if (head == NULL)
    {
        cout << "Cannot perform deletion, Empty Linked List!!" << endl;
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        // Check if the new head is not NULL
        if (head != NULL) 
            head->prev = NULL;
        else
            // Update tail if the list becomes empty
            tail = NULL; 
        temp->next = NULL;
        delete temp;
    }
}

void deleteFromTail(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    
    if (head == NULL)
    {
        cout << "Cannot perform deletion, Empty Linked List!!" << endl;
    }
    else
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
}

void deleteFromPosition (Node *&head, Node *&tail, int position)
{
    int length = getLength(head);
    
    if (position < 1 || position > length)
    {
        cout << "Cannot perform deletion, give correct position!" << endl;
        return;
    }
    
    if (position == 1)
    {
        deleteFromHead(head, tail);
    } else if (position == length)
    {
        deleteFromTail(head, tail);
    } else 
    {
        Node* pervious = NULL;
        Node* current = head;
        while (position != 1)
        {
            position--;
            pervious = current;
            current = current->next;
        }
        pervious->next = current->next;
        (current->next)->prev = pervious;
        current->next = NULL;
        current->prev = NULL;
        delete current;
    }
    
    
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    first->prev = NULL;
    second->prev = first;
    third->prev = second;
    fourth->prev = third;

    Node *head = first;
    Node *tail = NULL;
    createTail(head, tail);

    printLL(head);

    deleteFromHead(head, tail);

    printLL(head);
    
    deleteFromTail(head, tail);

    printLL(head);

    deleteFromPosition(head, tail, 2);

    printLL(head);
}