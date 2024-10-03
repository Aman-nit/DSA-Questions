// time complexity in average case = O(H)=O(logn)
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
        return NULL;
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
bool findNodeInBst(node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    if (root->data < target)
    {
        return findNodeInBst(root->right, target);
    }
    else
    {
        return findNodeInBst(root->left, target);
    }
}

int main()
{

    node *root = NULL;
    takeInput(root);

    cout << findNodeInBst(root, 25) << endl;
}