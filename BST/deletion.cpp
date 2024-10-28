// in the delation of any node we will b behaving 4 cases
// 1. the node have left and right node NULL
// 2. the node have left node NULL only
// 3. the node have right node NULL only
// 4. the node will have both right and left node !NULL

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
node *builtBst(node *root, int data)
{
    if (root == NULL)
    {
        root = new node(data);
        return root;
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
node *findNodeInBst(node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == target)
    {
        return root;
    }
    if (target > root->data)
    {
        return findNodeInBst(root->right, target);
    }
    else
    {
        return findNodeInBst(root->left, target);
    }
}
node *deleteNodeInBst(node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return root;
    }
    // step 1
    node *temp = findNodeInBst(root, target);
    // now we have to delte that node
    // case 1(leaf node)
    if (temp->left == NULL && temp->right == NULL)
    {
        delete temp;
        return NULL;
    }
    // case 2(temp->left is NULL only)
    if (temp->left == NULL && temp->right != NULL)
    {
        node *child = temp->right;
        delete temp;
        return child;
    }
    // case 3(temp->right is NULL only)
    if (temp->left != NULL && temp->right == NULL)
    {
        node *child = temp->left;
        delete temp;
        return child;
    }
    // case 4(temp->right and temp->left both is not NULL)
    else
    {
    }
}
