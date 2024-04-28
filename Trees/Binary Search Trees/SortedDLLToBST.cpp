#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int val)
	{
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

Node *insertIntoBST(Node *&root, int data)
{
	if (root == NULL)
	{
		root = new Node(data);
		return root;
	}

	if (data > root->data)
	{
		root->right = insertIntoBST(root->right, data);
	}
	else
	{
		root->left = insertIntoBST(root->left, data);
	}
	return root;
}

void createBST(Node *&root)
{
	cout << "Enter data: ";
	int value;
	cin >> value;

	while (value != -1)
	{
		root = insertIntoBST(root, value);
		cout << "Enter data: ";
		cin >> value;
	}
}

void preOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// NLR
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// LNR
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}

	// LRN
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void levelOrderTraversal(Node *root)
{
	queue<Node *> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();

		if (temp == NULL)
		{
			cout << endl;
			if (!q.empty())
			{
				q.push(NULL);
			}
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left != NULL)
			{
				q.push(temp->left);
			}
			if (temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
}

Node* SortedDLLToBST (Node* head, int n)
{
    if (head == NULL || n < 1)
    {
        return NULL;
    }
    
    // LNR

    // L
    Node* leftSubTree = SortedDLLToBST(head, n/2);

    // N
    Node* root = head;
    // COnnecting middle node, i.e., root to the leftSubtree
    root->left = leftSubTree;
    // Moving left to right for rightSubTree to follow
    head = head->right;

    // R
    Node* rightSubTree = SortedDLLToBST(head, n - n/2 - 1);
    // COnnecting middle node, i.e., root to the rightSubtree
    root->right = rightSubTree;

    return root;
}

void printLL(Node* head)
{
	cout << "Entire Linked List: ";
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "->";
		temp = temp->right;
	}
	cout << "NULL" << endl;
}

int main()
{
	Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    first->right = second;
    second->right = third;
    third->right = fourth;
    fourth->right = fifth;
    first->left = NULL;
    second->left = first;
    third->left = second;
    fourth->left = third;

    Node *head = first;

    printLL(head);

    Node* root = SortedDLLToBST(head, 5);
    levelOrderTraversal(root);
}