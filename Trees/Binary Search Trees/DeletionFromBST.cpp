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

Node *minValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No min value" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    if (root == NULL)
    {
        cout << "No min value" << endl;
        return NULL;
    }

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteFromBST(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // 4 cases:

        // 1 case - Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 2 case - left non-null and right null
        else if (root->left != NULL && root->right == NULL)
        {
            Node *childSubtree = root->left;
            delete root;
            return childSubtree;
        }

        // 3 case - left null and right non-null
        else if (root->left == NULL && root != NULL)
        {
            Node *childSubtree = root->right;
            delete root;
            return childSubtree;
        }

        // 4 case - left non-null and right non-null
        else
        {
            Node *maximum = maxValue(root->left);
            root->data = maximum->data;
            root->left = deleteFromBST(root->left, maximum->data);
        }
    }
    else if (root->data > target)
    {
        // !!!!Possible Mistake!!!!
        root->left = deleteFromBST(root->left, target);
    }
    else if (root->data < target)
    {
        // !!!!Possible Mistake!!!!
        root->right = deleteFromBST(root->right, target);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    createBST(root);
    levelOrderTraversal(root);

    int target;
    cout << "Enter element for deletion: ";
    cin >> target;

    while (target != -1 || root == NULL)
    {
        root = deleteFromBST(root, target);
        cout << endl
             << "Printing level order traversal: " << endl;
        levelOrderTraversal(root);
        cout << "Enter element for deletion: ";
        cin >> target;
    }
}