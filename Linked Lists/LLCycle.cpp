#include <iostream>
#include <map>

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

bool hasCycle(Node *head)
{
    map<Node *, bool> table;

    Node *temp = head;
    while (temp != NULL)
    {
        if (table[temp] == false)
        {
            table[temp] = true;
        }
        else
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Hare & Tortoise Method
bool hasCycle2(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            return true;
        }

        if (fast == NULL)
        {
            return NULL;
        }
    }
    return false;
}

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

Node *detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            break;
        }
    }

    if (fast == NULL)
    {
        return NULL;
    }

    slow = head;

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void removeCycle(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            break;
        }
    }

    slow = head;

    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *startingPoint = slow;

    Node *temp = startingPoint;
    while (temp->next != startingPoint)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    Node *tail = fifth;

    tail->next = third;

    cout << hasCycle2(head) << endl;
    removeCycle(head);
    printLL(head);
}