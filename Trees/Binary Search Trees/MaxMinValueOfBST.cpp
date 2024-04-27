#include<iostream>
#include<queue>

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

Node* minValue(Node* root)
{
    if (root == NULL)
    {
        cout << "No min value" << endl;
        return NULL;
    }
    
    
    Node* temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root)
{
    if (root == NULL)
    {
        cout << "No min value" << endl;
        return NULL;
    }
    
    
    Node* temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    Node* minNode = minValue(root);
    cout << "Min value: " << minNode->data << endl;

    Node* maxNode = maxValue(root);
    cout << "Max value: " << maxNode->data << endl;
}