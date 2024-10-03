// Creation of binary search tree, in this special type of tree in which the node data is smaller than node->left and greater than node->right if all the node follows this rule then we can say that this tree is binary search tree,and the leaf node will concered as valid binary search tree

#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    // Constructor corrected
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to insert a node into the BST
node *creationOfBst(node *root, int data)
{
    if (root == NULL)
    {
        // This is the root node
        root = new node(data);
        return root;
    }
    // If data is smaller, insert into the left subtree
    if (data < root->data)
    {
        root->left = creationOfBst(root->left, data);
    }
    // If data is greater, insert into the right subtree
    else
    {
        root->right = creationOfBst(root->right, data);
    }
    return root;
}

// Function to take input for the BST
void takeInput(node *&root)
{
    int data;
    cout << "Enter the data for the node:- " << endl;
    cin >> data;
    while (data != -1)
    {
        root = creationOfBst(root, data);
        cout << "Enter the data for the node:- " << endl;
        cin >> data;
    }
}

// Function for level-order traversal
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

        cout << current->data << " "; // Print current node's data

        // Enqueue left child
        if (current->left != nullptr)
        {
            q.push(current->left);
        }

        // Enqueue right child
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
    }
    cout << endl;
}
void preOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// IN ORDER OF THE BST IS ALWAYS GIVE YOU SORTED
void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    takeInput(root); // Take user input
    cout << "Level order traversal of the BST: " << endl;
    levelOrderTraversal(root); // Display the BST in level order
    cout << "Printing Inorder traversal:-" << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "Printing postorder traversal:-" << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "Printing preorder traversal:-" << endl;
    preOrderTraversal(root);
    cout << endl;

    return 0;
}
