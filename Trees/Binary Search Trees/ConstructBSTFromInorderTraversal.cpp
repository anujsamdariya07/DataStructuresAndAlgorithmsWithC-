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

Node* bstFromInOrder(int inOrder[], int start, int end)
{
    // Base case
    if (start > end)
    {
        return NULL;
    }
    
    // Solving 1 case
    int mid = start + (end-start)/2;
    int element = inOrder[mid];
    Node* root = new Node(element);

    // Recursive call
    root->left = bstFromInOrder(inOrder, start, mid-1);
    root->right = bstFromInOrder(inOrder, mid+1, end);

    return root;
}

int main()
{
    // Node *root = NULL;
    // createBST(root);

    int inOrder[] = {10, 20, 30, 40 ,50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size-1;
    Node* root = bstFromInOrder(inOrder, start, end);
    levelOrderTraversal(root);
}