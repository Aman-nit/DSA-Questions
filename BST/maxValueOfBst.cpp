// in BST min value will be the last left node in Binary Search Tree and in the same way the the last node of right subtree will be the max value in BST.

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
node *creatBst(node *root, int data)
{
    // for empty bst
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }
    if (root->data > data)
    {
        root->left = creatBst(root->left, data);
    }
    else
    {
        root->right = creatBst(root->right, data);
    }
    return root;
}
void takeInput(node *&root)
{
    int data;
    cout << "Enter the data for the node:- " << endl;
    cin >> data;
    while (data != -1)
    {
        root = creatBst(root, data);
        cout << "Enter the data for the node:- " << endl;
        cin >> data;
    }
}
int maxValue(node *root)
{
    node *temp = root;
    if (root == NULL)
    {
        return -1;
    }
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << temp->data << endl;
    return temp->data;
}

int main()
{
    node *root = NULL;
    takeInput(root);
    cout << "Maximum value of the BST is :-";
    maxValue(root);

    return 0;
}
