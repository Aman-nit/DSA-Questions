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
bool findNodeInBst(node *root, int target)
{
    bool leftAns = false;
    bool rightAns = false;
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
        rightAns = findNodeInBst(root->right, target);
    }
    else
    {
        leftAns = findNodeInBst(root->left, target);
    }
    // using or because if there is any true from left subtree or right subtree then the over all true will be return
    return right || leftAns;
}

int main()
{

    node *root = NULL;
    takeInput(root);
    int target;
    cout << "Enter the target value:-";
    cin >> target;
    cout << findNodeInBst(root, 25) << endl;
}