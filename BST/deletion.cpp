#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Build BST function
node *builtBst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = builtBst(root->left, data);
    }
    else
    {
        root->right = builtBst(root->right, data);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cout << "Enter the data:-";
    cin >> data;
    while (data != -1)
    {
        root = builtBst(root, data);
        cout << "Enter the data:-";
        cin >> data;
    }
}

// Find maximum value in the left subtree (used for deletion)
int maxValue(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Level order traversal
void levelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Delete node in BST function
node *deleteNodeInBst(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (target < root->data)
    {
        root->left = deleteNodeInBst(root->left, target);
    }
    else if (target > root->data)
    {
        root->right = deleteNodeInBst(root->right, target);
    }
    else
    {
        // Node to delete found
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2: One child (right child)
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // Case 2: One child (left child)
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else
        {
            int inorderPredecessor = maxValue(root->left);
            root->data = inorderPredecessor;
            root->left = deleteNodeInBst(root->left, inorderPredecessor);
        }
    }
    return root;
}

int main()
{
    node *root = NULL;
    takeInput(root);
    int target;
    cout << endl
         << "Enter the element you want to delete:-";
    cin >> target;
    root = deleteNodeInBst(root, target);
    cout << "Level order traversal after deletion:" << endl;
    levelOrderTraversal(root);

    return 0;
}
