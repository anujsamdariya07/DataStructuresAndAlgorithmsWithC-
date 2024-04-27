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

Node *createTree()
{
    cout << "ENter the value for node: ";
    int value;
    cin >> value;
    if (value == -1)
    {
        return NULL;
    }

    Node *root = new Node(value);

    cout << "Entering the left of " << root->data << ": " << endl;
    root->left = createTree();
    cout << "Entering the right of " << root->data << ": " << endl;
    root->right = createTree();

    return root;
}

void lowLevelTraversal(Node *&root)
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

void printLeftBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    cout << root->data << " ";

    if (root != NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }

    if (root != NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

void printLeafNode(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    printLeafNode(root->left);
    printLeafNode(root->right);
}

void boundaryTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeafNode(root);
    printRightBoundary(root->right);
}

int main()
{
    Node *root = createTree();
    cout << "Tree: " << endl;
    lowLevelTraversal(root);
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1