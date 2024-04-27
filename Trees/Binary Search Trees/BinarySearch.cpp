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

bool searchInBST(Node* root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    
    if (root->data == target)
    {
        return true;
    } 
    
    bool leftAns = false, rightAns = false;
    if (root->data > target)
    {
        leftAns = searchInBST(root->left, target);
    } else if (root->data < target)
    {
        rightAns = searchInBST(root->right, target);
    }

    return leftAns || rightAns;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    int target;
    cout << "Enter the target: ";
    cin >> target;

    while (target != -1)
    {
        bool ans = searchInBST(root, target);
        if (ans == true)
        {
            cout << "Found" << endl;
        }
        else {
            cout << "Not found" << endl;
        }

        cout << "ENter the target: ";
        cin >> target;
    }
}