#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head)
{
    Node* temp = head;

    cout << "Printing the entire Linked List: " << endl;
    int len = 0;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        len++;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "NULL" << endl;
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

void createTail (Node* head, Node* &tail)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

void deleteNodeFromHead (Node* &head, Node* &tail)
{
    Node* temp = head;
    head = temp->next;
    temp->next = NULL;
    delete temp;
}

void deleteNodeFromTail (Node* &head, Node* &tail)
{
    Node* prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }
    prev->next = NULL;
    delete tail;
    tail = prev;
}

void deleteNode (Node* &head, Node* &tail, int position)
{
    if (head == NULL)
    {
        cout << "Cannot delete from null linked list" << endl;
        return;
    }

    if (head == tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    
    int length = getLength(head);

    if (position == 1)
    {
        // delete from head
        deleteNodeFromHead(head, tail);
    } else if (position == length)
    {
        // delete from tail
        deleteNodeFromTail(head, tail);
    } else
    {
        // delete from between head and tail
        Node* prev = NULL;
        Node* curr = head;
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
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

    // Head node
    Node *head = first;
    // Tail node
    Node *tail = NULL;
    createTail(head, tail);

    printLL(head);
    deleteNode(head, tail, 4);
    printLL(head);
}