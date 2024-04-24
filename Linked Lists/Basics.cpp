// H.W. --> Where do we use Linked Lists for storage management in operating system.
#include<iostream>

using namespace std;

class Node {
public: 
    int data;
    Node* next;

    Node ()
    {
        this->next = NULL;
    }
    Node (int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Whenever a LL is passed to a function, we will never use it's original pointer to traverse it, instead we will create a temporary pointer for this purpose.
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
    cout << endl;
    cout << "Length of LL: " << len << endl;
}

int main()
{
    // Creation of node
    // Static intialization
    Node n1;
    // Dynamic intialization
    Node* n2 = new Node();

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Head node
    Node* head = first;
    printLL(head);
}
// Whenever we solve a question on Linked Lists, there are generally 2-3 corner cases which are not covered thus, denying 2-3 test cases.