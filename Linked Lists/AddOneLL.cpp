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

void printLL(Node *head)
{
    Node *temp = head;

    cout << "Printing the entire Linked List: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
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

Node* reverse(Node* &head)
{
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

void addOne(Node* &head)
{
    // Reverse list
    head = reverse(head);

    // Add 1
    int carry = 1;
    Node *temp = head;
    while (temp->next != NULL)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;

        if (carry == 0)
        {
            break;
        }
    }
    if (carry != 0)
    {
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;

        if (carry != 0)
        {
            Node *newNode = new Node(carry);
            temp->next = newNode;
        }
    }

    // Reverse list
    head = reverse(head);
}

int main()
{
    Node *first = new Node(1);
    Node *second = new Node(9);
    Node *third = new Node(9);

    first->next = second;
    second->next = third;

    Node *head = first;

    printLL(head);

    addOne(head);

    printLL(head);
}