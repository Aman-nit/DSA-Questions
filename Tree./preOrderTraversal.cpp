#include <iostream>
#include <stack>
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

node *buildTree()
{
    int data;
    cout << "Enter the data of the node:-" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter data for the left part of node" << data << endl;
    root->left = buildTree();
    cout << "Enter data for the right part of node" << data << endl;
    root->right = buildTree();

    return root;
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

int main()
{
    node *root = buildTree();

    cout << "Printing Inorder traversal...." << endl;
    preOrderTraversal(root);

    return 0;
}