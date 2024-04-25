#include<iostream>

using namespace std;

class Node 
{
public:
    int data;
    Node* prev;
    Node* next;

    Node ()
    {
        prev = NULL;
        next = NULL;
    }
    Node (int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL (Node* head)
{
    cout << "Printing the entire linked list:-" << endl;
    
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength (Node* head)
{
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead (Node* &head, Node* &tail, int data)
{
    if (head == NULL)
    {
        // LL is empty
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else 
    {
        // LL is non-empty
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev =newNode;
        head = newNode;
    }
}

void insertAtTail (Node* &head, Node* &tail, int data)
{
    if (head == NULL)
    {
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    } else 
    {
        // LL in non-empty
        Node* newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    
}

void insertAtPosition (Node* &head, Node* &tail, int data, int position)
{
    int length = getLength(head);

    if (position < 0 || position > length+1)
    {
        cout << "Cannot insert, give correct position!" << endl;
        return;
    }

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    } else if (position == length + 1)
    {
        insertAtTail(head, tail, data);
        return;
    } else 
    {
        // Create a new node
        Node* newNode = new Node(data);
        // Make prev and next and traverse them
        Node* previous = NULL;
        Node* current = head;
        while (position != 1)
        {
            position--;
            previous = current;
            current = current->next;
        }
        // Attach new node
        newNode->next = current;
        newNode->prev = previous;
        previous->next = newNode;
        current->prev = newNode;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 80);

    printLL(head);

    insertAtPosition(head, tail, 1000, 5);

    printLL(head);
}