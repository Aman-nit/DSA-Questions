#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build the binary tree
node *buildTree()
{
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    // -1 represents NULL
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter data for the left part of node " << data << endl;
    root->left = buildTree();

    cout << "Enter data for the right part of node " << data << endl;
    root->right = buildTree();

    return root;
}

// Function to perform level order traversal of the tree
void levelOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);
    q.push(NULL); // Marker for the end of the current level

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // New level

            if (!q.empty())
            {
                q.push(NULL); // Mark the next level
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // Creating a binary tree
    node *root = buildTree();

    cout << "Level order traversal of the tree:" << endl;
    levelOrderTraversal(root);

    return 0;
}
