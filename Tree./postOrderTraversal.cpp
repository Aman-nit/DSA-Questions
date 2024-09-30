#include <iostream>
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
    cout << "Enter the data:-";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);
    cout << "Enter the data for the left part of the node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for the right part of the node " << data << endl;
    root->right = buildTree();
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
    node *root = buildTree();

    cout << "Printing Post Order Traversala" << endl;
    postOrderTraversal(root);

    return 0;
}