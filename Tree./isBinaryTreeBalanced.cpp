// EVERY NODE'S LEFT SUB TREE AND RIGHT SUB TREE HRIGHT DIFFERENCE CAN NOTE BE GRATER THEN 1(<=1);
#include <iostream>
#include <math.h>

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

    cout << "Enter the data for left node " << data << endl;
    root->left = buildTree();
    cout << "Enter the data for rightt node " << data << endl;
    root->right = buildTree();

    return root;
}
int height(node *root)
{
    // Base case
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = 1 + max(leftHeight, rightHeight);

    return ans;
}
bool isBalanced(node *root)
{
    // Base
    if (root == NULL)
    {
        return true;
    }

    // 1 case
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = abs(leftHeight - rightHeight);
    bool ans1 = (diff <= 1);

    // Recursion
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    if (ans1 && leftAns && rightAns)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    node *root = buildTree();

    bool ans = isBalanced(root);
    if (ans)
    {
        cout << "Binary Tree is balanced..";
    }
    else
    {
        cout << "Binary Tree is not balanced";
    }

    return 0;
}
