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

void insertAtHead (Node* &head, Node* &tail, int data)
{
    if (head == NULL)
    {
        // Empty LL

        // Create new node
        Node* newNode = new Node();
        // Update head & tail
        head = newNode;
        tail = newNode;
    } else 
    {
        // Non-empty LL

        // Create a new node
        Node *newNode = new Node(data);

        // Attach new node to head node
        newNode->next = head;

        // Update head
        head = newNode;
    }
}

void insertAtTail (Node* head, Node* tail, int data)
{
    if(head == NULL)
    {
        // Empty LL

        // Create new node
        Node* newNode = new Node(data);
        // Update tail
        head = newNode;
        tail = newNode;
    } else 
    {
        // Non-empty LL

        // Create new node 
        Node* newNode = new Node();
        // Tail node attach with newNode
        tail->next = new Node(data);
        // Update tail
        tail = newNode;
    }
}

void insertAtPosition (Node* &head, Node* &tail, int data, int position)
{
    int length = getLength(head);
    cout << length<< endl;

    if (position < 0 || position > length + 1)
    {
        cout << "Cannot insert, enter a valid position." << endl; 
        return;
    }

    if (position == 0)
    {
        // In head
        insertAtHead(head, tail, data);
        return;
    } else if (position == length+1)
    {
        // In tail
        insertAtTail(head, tail, data);
        return;
    } else 
    {
        // In between head and tail

        // Create a new node
        Node* newNode = new Node(data);
        // Create curr and prev elements and traverse them
        Node* curr = head;
        Node* prev = NULL;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        // Attach newNode in between prev and curr
        newNode->next = curr;
        prev->next = newNode;
    }
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

    insertAtHead(head, tail, 0);

    printLL(head);

    insertAtTail(head, tail, 60);

    // int length = getLength(head);
    printLL(head);


    insertAtPosition(head, tail, 100, 3);

    printLL(head);
}