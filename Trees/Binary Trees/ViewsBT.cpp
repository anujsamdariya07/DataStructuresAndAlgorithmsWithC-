#include <iostream>
#include <map>
#include <vector>
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

void preOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inOrderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
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

void printLeftView(Node *root, int level, vector<int> &leftView)
{
    if (root == NULL)
    {
        return;
    }

    if (level == leftView.size())
    {
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(Node *root, int level, vector<int> &rightView)
{
    if (root == NULL)
    {
        return;
    }

    if (level == rightView.size())
    {
        rightView.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

void printTopView(Node* root)
{
    map<int, int> horizontalDistanceToNode;
    queue < pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* frontNode = p.first;
        int horizontalDistance = p.second;

        // map.find(a) = map.end(), means there is no value for a in the map
        if (horizontalDistanceToNode.find(horizontalDistance) == horizontalDistanceToNode.end())
        {
            horizontalDistanceToNode[horizontalDistance] = frontNode->data;
        }

        // Left and right children
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, horizontalDistance-1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, horizontalDistance+1));
        }
    }
    
    cout << "Printing top view: "<< endl;
    for(auto i: horizontalDistanceToNode) 
    {
        cout << i.second << " ";
    }
    cout << endl;
}

void printBottomView(Node* root)
{
    map<int, int> horizontalDistanceToNode;
    queue < pair<Node*, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* frontNode = p.first;
        int horizontalDistance = p.second;

        // No condition required unlike top view
        horizontalDistanceToNode[horizontalDistance] = frontNode->data;

        // Left and right children
        if (frontNode->left != NULL)
        {
            q.push(make_pair(frontNode->left, horizontalDistance-1));
        }
        if (frontNode->right != NULL)
        {
            q.push(make_pair(frontNode->right, horizontalDistance+1));
        }
    }
    
    cout << "Printing bottom view: "<< endl;
    for(auto i: horizontalDistanceToNode) 
    {
        cout << i.second << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = createTree();
    cout << "Tree: " << endl;
    lowLevelTraversal(root);
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    for (auto i : leftView)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Tree: " << endl;
    vector<int> rightView;
    printRightView(root, 0, rightView);
    for (auto i : rightView)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Tree: " << endl;
    printTopView(root);
    cout << "Tree: " << endl;
    printBottomView(root);
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1