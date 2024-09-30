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
    cout << "Enter the data:-" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    node *root = new node(data);

    cout << "Enter the data for the left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for the right node " << data << endl;
    root->right = buildTree();

    return root;
}

void leavesCount(node *root, int &count)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    leavesCount(root->left, count);
    leavesCount(root->right, count);
}

int main()
{
    int count = 0;
    node *root = buildTree();
    leavesCount(root, count);
    cout << "Total number of leaves node in a Binary Tree is " << count;
}