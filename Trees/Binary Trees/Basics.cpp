#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// This will return the root node of the tree
Node* createTree()
{
    cout << "Enter the value: ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    
    // Create new node
    Node* newNode = new Node(data);
    // Create left subtree
    cout << "For left of " << newNode->data << ", ";
    newNode->left = createTree();
    // Create right subtree
    cout << "For right of " << newNode->data << ", ";
    newNode->right = createTree();

    return newNode;
}

void preOrderTraversal(Node* root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    
    // NLR
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    
    // LNR
    // L
    preOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }
    
    // LRN
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

void lowLevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node* front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
        } else 
        {
            cout << front->data << " ";

        if (front->left != NULL)
        {
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            q.push(front->right);
        }
        }
    }
     
}

int main()
{
    Node* root = createTree();

    cout << "Printing Preorder: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Printing Inorder: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Printing Postorder: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Printing Low-level Order: ";
    lowLevelOrderTraversal(root);
    cout << endl;
}