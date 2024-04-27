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

// This will return the root node of the tree
Node *createTree()
{
    cout << "Enter the value: ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    // Create new node
    Node *newNode = new Node(data);
    // Create left subtree
    cout << "For left of " << newNode->data << ", ";
    newNode->left = createTree();
    // Create right subtree
    cout << "For right of " << newNode->data << ", ";
    newNode->right = createTree();

    return newNode;
}

void preOrderTraversal(Node *root)
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

void inOrderTraversal(Node *root)
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

void postOrderTraversal(Node *root)
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

void lowLevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
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

int maxDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    int height = max(leftHeight, rightHeight) + 1;

    return height;
}

int searchInOrder (int inOrder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == element)
        {
            return i;
        }
        
    }
    return -1;
}

// Pass preOrderIndex by reference otherwise it will be 0 for each recursion call.
Node* constructTreeFromPreInOrderTraversal (int preOrder[], int inOrder[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int size) {
    // Base case
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    
    // Solving 1 case
    int element = preOrder[preOrderIndex];
    preOrderIndex++;
    Node* root = new Node(element);

    // Searching the preOrder element in the inOrder array
    int position = searchInOrder(inOrder, size, element);

    root->left = constructTreeFromPreInOrderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, position-1, size);
    root->right = constructTreeFromPreInOrderTraversal(preOrder, inOrder, preOrderIndex, position+1, inOrderEnd, size);

    return root;
}

int main()
{
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;

    Node* root = constructTreeFromPreInOrderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
    cout << "Printing the entire tree: "<< endl;
    lowLevelOrderTraversal(root);
}